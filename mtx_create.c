
#include "mtxlib.h"

static void	__mtx_setup_1d(t_mtx *mtx, int rows, int cols, size_t stride)
{
	mtx->ndims = (unsigned char)1;
	mtx->shape[0] = (rows > 1) * rows + (cols > 1) * cols;
	mtx->strides[0] = stride;
}

static void	__mtx_setup_2d(t_mtx *mtx, int rows, int cols, size_t stride)
{	
	mtx->ndims = (unsigned char)2;
	mtx->shape[0] = rows;
	mtx->shape[1] = cols;
	mtx->strides[1] = stride;
	mtx->strides[0] = cols * stride;
}

t_mtx	*mtx_create_emtpy(int rows, int cols, int dtype)
{
	t_mtx	*mtx;
	size_t	dsize;

	if (rows < 1 || cols < 1 || !(dtype == DTYPE_I || dtype == DTYPE_F))
	{
		perror("mtx_creat_empty : Invalid inputs ");
		return (NULL);
	}
	if (!malloc_free_p(sizeof(t_mtx), (void **)&mtx))
		return (NULL);
	mtx->ndims = (unsigned char)(rows > 1 + cols > 1);
	dsize = get_dsize(dtype);
	mtx->dtype = dtype;
	if (rows == 1 || rows == 1)
		__mtx_setup_1d(mtx, rows, cols, dsize);
	else
		__mtx_setup_2d(mtx, rows, cols, dsize);
	if (!malloc_free_p(dsize * rows * cols, (void **)&(mtx->arr)))
		return (malloc_free(0, (void **)&mtx));
	return (mtx);
}

t_mtx	*mtx_create_zeros(int rows, int cols, int dtype)
{
	t_mtx		*mtx;
	unsigned char	zero;

	zero = 0;
	mtx = mtx_create_empty(rows, cols, dtype);
	if (!mtx)
		return (NULL);
	mtx_fill(mtx, &zero);
	return (mtx);
}
