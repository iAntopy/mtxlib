

#include "mtxlib.h"
#include <stdio.h>

int	main()
{
	int	arr[5] = {1, 2, 3, 4, 5};
	t_mtx	*mtx;
	int	value = 99;

	mtx = mtx_create_array(arr, 5, 1, DTYPE_I);
	printf("fill test : Post creation matrix :\n");
	mtx_print(mtx);
	mtx_display_info(mtx);
	mtx_fill(mtx, &value);
	printf("fill test : Post fill matrix :\n");
	mtx_print(mtx);
	mtx_clear(&mtx);

	return (0);
}
