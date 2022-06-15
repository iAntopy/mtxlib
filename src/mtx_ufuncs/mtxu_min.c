
#include "mtxlib.h"

static int	*__mtx_min_i(int *arr, size_t n_elem)
{
	int	*res;

	res = arr;
	while (n_elem--)
	{
		if (*arr < *res)
			res = arr;
		arr++;
	}
	return (res);
}

static float	*__mtx_min_f(float *arr, size_t n_elem)
{
	float	*res;

	res = arr;
	while (n_elem--)
	{
		if (*arr < *res)
			res = arr;
		arr++;
	}
	return (res);
}


void	*mtxu_min(t_mtx *mtx)
{
	void	*res;

	res = NULL;
	if (mtx->dtype == DTYPE_I)
		res = __mtx_min_i(mtx->arr, mtx->shape[0] * mtx->shape[1]);
	else if (mtx->dtype == DTYPE_F)
		res = __mtx_min_f(mtx->arr, mtx->shape[0] * mtx->shape[1]);
	else
		perror("mtxu_min : dtype of mtx is invalid ");
	return (res);	
}
