
#include "libft.h"
#include "mtxlib.h"

int	mtx_init_as_array(t_mtx *mtx, void *arr, int rows, int cols)
{
	if (!mtx->arr || mtx->shape[0] != rows || mtx->shape[1] != cols)
		return (-1);
	ft_memcpy(mtx->arr, arr, mtx->stride[0] * mtx->shape[0]);
	return (1);
}
