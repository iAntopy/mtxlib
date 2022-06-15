
#include "libft.h"
#include "mtxlib.h"

int	mtx_init_as_array(t_mtx *mtx, void *arr, int rows, int cols)
{
	printf("init as array : !!arr : %s, shape[0] == rows : %s, shape[1] == cols : %s\n", !!arr?"TRUE":"FALSE", (mtx->shape[0] == rows)?"TRUE":"FALSE", (mtx->shape[1] == cols)?"TRUE":"FALSE");
	if (!mtx || !mtx->arr || mtx->shape[0] != rows || mtx->shape[1] != cols)
		return (0);
	printf("init_as_array : mtx->arr[0] %d, arr[0] %d, sizeof array %zu\n", ((int *)mtx->arr)[0], ((int *)arr)[0], mtx_sizeof_array(mtx));
	ft_memcpy(mtx->arr, arr, mtx_sizeof_array(mtx));
	return (1);
}
