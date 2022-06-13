
#include <stdio.h>
void	pseudo_fill(int *arr, int value, int n_elems)
{
	while (n_elems--)
	{
		printf("new arr ptr %p\n", arr++);
	}
}

int	main()
{
	int	arr[5] = {1, 2, 3, 4, 5};

	pseudo_fill(arr, 99, 5);
	return (0);
}
