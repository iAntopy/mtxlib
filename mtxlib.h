
// HEADER

#ifndef MTXLIB_H
# define MTXLIB_H

# define MAX_DIMS 2

# include <math.h>
# include <stdlib.h>
# include <limits.h>

#include <stdio.h>

#include "../libft/libft.h"
//# include "mtx_mem_utils.h"

enum	mtx_data_types
{
	DTYPE_I = 1,
	DTYPE_F = 2
};

const size_t	mtx_DTYPE_SIZES[5];

typedef struct s_mtx_base
{
	int	ndims;
	int	dtype;
	int	shape[MAX_DIMS];
	int	strides[MAX_DIMS];
	void	*arr;
}	t_mtx;

void	mtx_clear(t_mtx **mtx);
t_mtx	*mtx_create_1x2_i(int arr[2]);
t_mtx	*mtx_create_2x2_i(int arr[2][2]);
t_mtx	*mtx_create_nx2_i(int n, int *arr);
t_mtx	*mtx_create_1x3_i(int arr[3]);
t_mtx	*mtx_create_3x3_i(int arr[3][3]);
t_mtx	*mtx_create_nx3_i(int n, int *arr);
t_mtx	*mtx_create_1x4_i(int arr[4]);
t_mtx	*mtx_create_4x4_i(int arr[4][4]);
t_mtx	*mtx_create_nx4_i(int n, int *arr);
t_mtx	*mtx_create_empty(int rows, int cols, int dtype);
t_mtx	*mtx_create_zeros(int rows, int cols, int dtype);
t_mtx	*mtx_create_array(void *arr, int rows, int cols, int dtype);
t_mtx	*mtx_identity(int n, int dtype);

// MEMORY MANAGEMENT
int	malloc_free_p(size_t size, void **ptr);
void	*malloc_free(size_t size, void **ptr);
size_t	get_dsize(int dtype);

// PRINT FUNCS
void	mtx_print(t_mtx *mtx);
void	mtx_print_f(t_mtx *mtx);
void	mtx_print_i(t_mtx *mtx);

// GENERIC UTILS
int	mtxu_max_i(t_mtx *mtx);
float	mtxu_max_f(t_mtx *mtx);
void	mtxu_fill(t_mtx *mtx, void *value);
void	mtx_init_as_array(t_mtx *mtx, void *arr, int rows, int cols);

// MATH_OPS
int	mtx_dot(t_mtx *m1, t_mtx *m2);
int	__mtx_dot_22o22(int *a1, int *a2, int *out);
int	__mtx_dot_n2o22(int *a1, int *a2, int n, int *out);

#endif
