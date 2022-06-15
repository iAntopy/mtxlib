#include "mtxlib.h"


// mtx_slice_view provides a seperate t_mtx struct which gives a view of 
// a slice of the original matrix described by the slice param..
// A view means that the data of the array
// is the same as the original array so that changes made in the view matrix 
// DO change the data in the original.
// A view matrix can be trasposed as just as a regular matrix with mtx_transpose..
//
// slice is a 4 int array where each member represents the following:
//	- slice[0] = row_s = starting row index.
//	- slice[1] = row_e = ending row index (indexed exclisivly [row_s:row_e[ ).
//	- slice[2] = col_s = starting col index.
//	- slice[3] = col_e = ending col index (indexed exclisivly [col_s:col_e[ ).
// [side]_e must be greater than [side_s].
// if INT_MAX is given as [side]_e, slicing is done to the end of this side of matrix.
// indices must within [0:shape[side][ exclusively.
t_mtx	*mtx_slice_view(t_mtx *mtx, int slice[4])
{
	t_mtx	*ret;
	int	rrange;
	int	crange;

	if (!mtx || !mtx_index_is_inbound(mtx, slice[0], slice[1])
		|| !mtx_index_is_inbound(mtx, slice[2], slice[3]))
		return (fperror("mtx_slice_view : no mtx or out of bound %d",
			));
	rrange = slice[1] - slice[0];
	crange = slice[3] - slice[2];
	if (!rrange || !crange)
		return (fperror("mtx_slice_view : "));

	ret = mtx_dup_struct(mtx);
	ret->arr = mtx->arr + (mtx->strides[0] * slice[0])
	ret->arr += mtx->strides[1] * slice[1];
	ret->shape[0] = ;
	
}
