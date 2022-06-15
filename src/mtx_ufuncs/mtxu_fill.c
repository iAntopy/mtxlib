
#include "mtxlib.h"

static void	mtx_fill_4byte(int *arr, int value, size_t n_elems)
{
	while (n_elems--)
		*(arr++) = value;
}

static void	mtx_fill_1byte(char *arr, char value, size_t n_elems)
{
	while (n_elems--)
		*(arr++) = value;
}

static void	mtx_fill_8byte(size_t *arr, size_t value, size_t n_elems)
{
	while (n_elems--)
		*(arr++) = value;
}

//fills matrix with the value poited by void *. The size of the 
//value to copy is derived from the matrix dtype.
void	mtx_fill(t_mtx *mtx, void *value)
{
	size_t	dsize;
	size_t	n_elems;

	dsize = get_dsize(mtx->dtype);
	if (mtx->ndims == 1)
		n_elems = mtx->shape[0];
	else if (mtx->ndims == 2)
		n_elems = mtx->shape[0] * mtx->shape[1];
	if (dsize == sizeof(int))
		mtx_fill_4byte((int *)mtx->arr, *(int *)value, n_elems);
	else if (dsize == sizeof(size_t))
		mtx_fill_8byte((size_t *)mtx->arr, *(size_t *)value, n_elems);
	else if (dsize == sizeof(char))
		mtx_fill_1byte((char *)mtx->arr, *(char *)value, n_elems);
}
