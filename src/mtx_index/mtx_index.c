#include "mtxlib.h"

int	mtx_index_is_inbound(t_mtx *mtx, int row, int col)
{
	return (row >= 0 && col >= 0
		&& row < mtx->shape[0] && col < mtx->shape[1]);
}

// Garanties to returns the correct array ptr weither 
// mtx is a view or not. offset will be 0 if is regular array
// and offset >= 0 if view. The offset is set by the mtx_slice_view func.
// On regular arrays the view_ptr member will be a ptr to the mtx->arr
// member itself (mtx->view_ptr = &mtx->arr). That way view matrices 
// always have access the original array even after it has been swapped.
void	*_mtx_arr(t_mtx *mtx)
{
	return (*(mtx->view_ptr) + mtx->offset);
}

// For view matrices, the arr should be *(mtx->view_ptr) and be 
// offset by mtx->offset before entering this function. For
// regular matrices (non view) arr should be mtx->arr. In
// either case strides is mtx->strdes.
void	*_mtx_idx(void *arr, int *strides, int row, int col)
{
	return (arr + (strides[0] * row) + (strides[1] * col));
}

void	*mtx_index(t_mtx *mtx, int row, int col)
{
	if (row < 0 || col < 0 || row >= mtx->shape[0] || col >= mtx->shape[1])
		return (MTX_ERROR("index out of bounds"));
	return (_mtx_idx(_mtx_arr(mtx), mtx->strides, row, col));
}
