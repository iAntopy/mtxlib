

#include "mtxlib.h"

t_mtx	*mtx_identity(int n, int dtype)
{
	t_mtx	*mtx;
	char	*arr;
	int	i;
	int	j;

	if (n < 1)
		return ((t_mtx *)fperror("mtx_identity : %d is invalid n", n));
	mtx = mtx_create_zeros(n, n, dtype);
	if (!mtx)
		return (NULL);
	i = -1;
	arr = (char *)mtx->arr;
	while (++i < n)
		arr[i * mtx->strides[0] + i * mtx->strides[1]] = 1;
	return (mtx);
}

int	main()
{
	t_mtx	*mtx;

	mtx = mtx_identity(3, DTYPE_I);
	mtx_print(mtx);
	mtx_clear(&mtx);
	return (0);
}
