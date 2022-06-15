
#include "libft.h"
#include "mtxlib.h"

int	mtx_init_as_array(t_mtx *mtx, void *arr, int rows, int cols)
{
	printf("init as array : !!arr : %s, shape[0] == rows : %s, shape[1] == cols : %s\n", !!arr?"TRUE":"FALSE", (mtx->shape[0] == rows)?"TRUE":"FALSE", (mtx->shape[1] == cols)?"TRUE":"FALSE");
	if (!mtx || !mtx->arr || mtx->shape[0] != rows || mtx->shape[1] != cols)
		return (0);
	if (mtx->dtype == DTYPE_I)
		printf("init_as_array : mtx->arr[0] %d, arr[0] %d, sizeof array %zu\n", ((int *)mtx->arr)[0], ((int *)arr)[0], mtx_sizeof_array(mtx));
	else	
		printf("init_as_array : mtx->arr[0] %f, arr[0] %f, sizeof array %zu\n", ((float *)mtx->arr)[0], ((float	*)arr)[0], mtx_sizeof_array(mtx));

	printf("init_as_array : init mem\n");
	ft_putbin(mtx->arr, mtx_sizeof_array(mtx));
	ft_memcpy(mtx->arr, arr, mtx_sizeof_array(mtx));
	printf("\ninit_as_array : new mem\n");
	ft_memcpy(mtx->arr, arr, mtx_sizeof_array(mtx));
	ft_putbin(mtx->arr, mtx_sizeof_array(mtx));


	if (mtx->dtype == DTYPE_I)
		printf("init_as_array : post memcpy mtx->arr[0] : %d\n", ((int *)mtx->arr)[0]);
	else	
		printf("init_as_array : post memcpy mtx->arr[0] : %f\n", ((float *)mtx->arr)[0]);
	return (1);
}
