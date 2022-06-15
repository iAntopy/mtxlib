
// HEADER

#ifndef MTXLIB_H
# define MTXLIB_H

# define MAX_DIMS 2

# include <math.h>
# include <stdlib.h>
# include <limits.h>

# include <stdio.h>

# include "libft.h"
//# include "mtx_mem_utils.h"

# define SHAPE_STR(rows, cols) ({(cols > 0) ? ("<"#rows" x "#cols">"):("<"#rows" x 1>");})

enum	mtx_data_types
{
	DTYPE_I = 1,
	DTYPE_F = 2
};

typedef struct s_mtx_base
{
	int	ndims;
	int	dtype;
	int	shape[MAX_DIMS];
	int	strides[MAX_DIMS];
	void	*arr;
	void	*out;
	int	is_view;
}	t_mtx;

//t_mtx	*mtx_create_1x2_i(int arr[2]);
//t_mtx	*mtx_create_2x2_i(int arr[2][2]);
//t_mtx	*mtx_create_nx2_i(int n, int *arr);
//t_mtx	*mtx_create_1x3_i(int arr[3]);
//t_mtx	*mtx_create_3x3_i(int arr[3][3]);
//t_mtx	*mtx_create_nx3_i(int n, int *arr);
//t_mtx	*mtx_create_1x4_i(int arr[4]);
//t_mtx	*mtx_create_4x4_i(int arr[4][4]);
//t_mtx	*mtx_create_nx4_i(int n, int *arr);
t_mtx	*mtx_create_empty(int rows, int cols, int dtype);
t_mtx	*mtx_create_zeros(int rows, int cols, int dtype);
t_mtx	*mtx_create_array(void *arr, int rows, int cols, int dtype);
t_mtx	*mtx_identity(int n, int dtype);
t_mtx	*mtx_arange(int a, int b, int dtype);
t_mtx	*mtx_linspace(float start, float end, int n_divs, int w_end);

// MEMORY MANAGEMENT
void	*mtx_clear(t_mtx **mtx);
int	malloc_free_p(size_t size, void **ptr);
void	*malloc_free(size_t size, void **ptr);
size_t	get_dsize(int dtype);
size_t	mtx_sizeof_array(t_mtx *mtx);

// INDEXING FUNCTIONS
void	*mtx_index(t_mtx *mtx, int row, int col);
int	mtx_index_is_inbound(t_mtx *mtx, int row, int col);
// PRINT FUNCS
void	mtx_print(t_mtx *mtx);
void	mtx_print_f(t_mtx *mtx);
void	mtx_print_i(t_mtx *mtx);
void	mtx_display_info(t_mtx *mtx);

// VALIDATOR FUNCS
int	mtx_isvalid_broadcast_dot(t_mtx *m1, t_mtx *m2);
int	mtx_isvalid_broadcast_to_dot(t_mtx *m1, t_mtx *m2, t_mtx *out);

// GENERIC UTILS
//int	mtxu_max_i(t_mtx *mtx);
//float	mtxu_max_f(t_mtx *mtx);
int	mtx_init_as_array(t_mtx *mtx, void *arr, int rows, int cols);
t_mtx	*mtx_transpose(t_mtx *mtx);
void	*mtx_max(t_mtx *mtx);
void	*mtx_min(t_mtx *mtx);
void	mtx_fill(t_mtx *mtx, void *value);
void	mtx_convert_arr_type(t_mtx *new, t_mtx *old);

t_mtx	*mtx_dup_struct(t_mtx *mtx);
t_mtx	*mtx_dup_empty(t_mtx *mtx, int dtype);
t_mtx	*mtx_copy(t_mtx *mtx, int dtype);

// TRIG OPS
t_mtx	*mtx_trig(t_mtx *mtx, float (*func)(float));

// LINALG OPS
int	mtx_dot(t_mtx *m1, t_mtx *m2);
int	mtx_doti_1D(t_mtx *m1, t_mtx *m2);
int	mtx_dotf_1D(t_mtx *m1, t_mtx *m2);

//int	__mtx_dot_22o22(int *a1, int *a2, int *out);
//int	__mtx_dot_n2o22(int *a1, int *a2, int n, int *out);

#endif
