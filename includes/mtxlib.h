/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:32:39 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/15 18:49:47 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTXLIB_H
# define MTXLIB_H

# define MAX_DIMS 2

# include <math.h>
# include <stdlib.h>
# include <limits.h>

# include <stdio.h>

# include "libft.h"
//# include "mtx_mem_utils.h"

# define SHAPE_STR(r, c) ({(c > 0) ? ("<"#r" x "#c">"):("<"#r" x 1>");})

enum	mtx_data_types
{
	DTYPE_I = 1,
	DTYPE_F = 2
};

typedef unsigned char U_CHAR;
typedef unsigned int U_INT;

typedef struct s_mtx_base
{
	int		ndims;
	int		dtype;
	int		shape[MAX_DIMS];
	int		strides[MAX_DIMS];
	void		*arr;
	void		*out;
	int		is_view;
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
void	*mtx_clear_list(int n, ...);
int	malloc_free_p(size_t size, void **ptr);
void	*malloc_free(size_t size, void **ptr);
size_t	get_dsize(int dtype);
size_t	mtx_sizeof_array(t_mtx *mtx);

// INDEXING FUNCTIONS
void	*mtx_index(t_mtx *mtx, int row, int col);
void	*_mtx_idx(t_mtx *mtx, int row, int col);
int	mtx_index_is_inbound(t_mtx *mtx, int row, int col);
// PRINT FUNCS
void	mtx_print(t_mtx *mtx);
void	mtx_print_f(t_mtx *mtx);
void	mtx_print_i(t_mtx *mtx);
void	mtx_display_info(t_mtx *mtx);

// VALIDATOR FUNCS
int	mtx_isvalid_broadcast_dot(t_mtx *m1, t_mtx *m2);
int	mtx_isvalid_broadcast_to_dot(t_mtx *m1, t_mtx *m2, t_mtx *out);
int	mtx_dtype_out(t_mtx *m1, t_mtx *m2);

// GENERIC UTILS
//int	mtxu_max_i(t_mtx *mtx);
//float	mtxu_max_f(t_mtx *mtx);
int		mtx_init_as_array(t_mtx *mtx, void *arr, int rows, int cols);
t_mtx	*mtx_transpose(t_mtx *mtx);
void	*mtx_max(t_mtx *mtx);
void	*mtx_min(t_mtx *mtx);
void	mtx_fill(t_mtx *mtx, void *value);
void	mtx_convert_arr_type(t_mtx *new, t_mtx *old);
int		mtx_dtype_out(t_mtx *m1, t_mtx *m2);

t_mtx	*mtx_dup_struct(t_mtx *mtx);
t_mtx	*mtx_dup_empty(t_mtx *mtx, int dtype);
t_mtx	*mtx_copy(t_mtx *mtx, int dtype);

t_mtx	*mtx_slice_view(t_mtx *mtx, const int slice[4]);
t_mtx	*mtx_select_row(t_mtx *mtx, int row);
t_mtx	*mtx_select_col(t_mtx *mtx, int col);


/////// ARITHMETIC OPS
//	ADD OPS
void	_mtx_addf_scalar(t_mtx *mtx, float sc, t_mtx *out);
void	_mtx_iaddf_scalar(t_mtx *mtx, float sc);
void	_mtx_addf_line(t_mtx *mtx, t_mtx *line, t_mtx *out);
void	_mtx_iaddf_line(t_mtx *mtx, t_mtx *line);
void	_mtx_addf_mtx(t_mtx *m1, t_mtx *m2, t_mtx *out);
void	_mtx_iaddf_mtx(t_mtx *m1, t_mtx *m2);

//	SUB OPS
void	_mtx_subf_scalar(t_mtx *mtx, float sc, t_mtx *out);
void	_mtx_isubf_scalar(t_mtx *mtx, float sc);
void	_mtx_subf_line(t_mtx *mtx, t_mtx *line, t_mtx *out);
void	_mtx_isubf_line(t_mtx *mtx, t_mtx *line);
void	_mtx_subf_mtx(t_mtx *m1, t_mtx *m2, t_mtx *out);
void	_mtx_isubf_mtx(t_mtx *m1, t_mtx *m2);
void	_mtx_rsubf_scalar(float sc, t_mtx *mtx, t_mtx *out);
void	_mtx_risubf_scalar(float sc, t_mtx *mtx);
void	_mtx_rsubf_line(t_mtx *line, t_mtx *mtx, t_mtx *out);
void	_mtx_risubf_line(t_mtx *line, t_mtx *mtx);

//	MUL OPS
void	_mtx_mulf_scalar(t_mtx *mtx, float sc, t_mtx *out);
void	_mtx_imulf_scalar(t_mtx *mtx, float sc);
void	_mtx_mulf_line(t_mtx *mtx, t_mtx *line, t_mtx *out);
void	_mtx_imulf_line(t_mtx *mtx, t_mtx *line);
void	_mtx_mulf_mtx(t_mtx *m1, t_mtx *m2, t_mtx *out);
void	_mtx_imulf_mtx(t_mtx *m1, t_mtx *m2);

//	DIV OPS
void	_mtx_divf_scalar(t_mtx *mtx, float sc, t_mtx *out);
void	_mtx_idivf_scalar(t_mtx *mtx, float sc);
void	_mtx_divf_line(t_mtx *mtx, t_mtx *line, t_mtx *out);
void	_mtx_idivf_line(t_mtx *mtx, t_mtx *line);
void	_mtx_divf_mtx(t_mtx *m1, t_mtx *m2, t_mtx *out);
void	_mtx_idivf_mtx(t_mtx *m1, t_mtx *m2);
void	_mtx_rdivf_scalar(float sc, t_mtx *mtx, t_mtx *out);
void	_mtx_ridivf_scalar(float sc, t_mtx *mtx);
void	_mtx_rdivf_line(t_mtx *line, t_mtx *mtx, t_mtx *out);
void	_mtx_ridivf_line(t_mtx *line, t_mtx *mtx);

// TRIG OPS
t_mtx	*mtx_trig(t_mtx *mtx, float (*func)(float));

// LINALG OPS
t_mtx	*mtx_dot(t_mtx *m1, t_mtx *m2, t_mtx **out);
int	mtx_doti_1D(t_mtx *m1, t_mtx *m2);
int	mtx_dotf_1D(t_mtx *m1, t_mtx *m2);
void	_mtx_dotf_4x4_4x4(float *a, float *b, float *out);
void	_mtx_dotf_nx4_4x4(int n, float *a, float *b, float *out);


//int	__mtx_dot_22o22(int *a1, int *a2, int *out);
//int	__mtx_dot_n2o22(int *a1, int *a2, int n, int *out);

#endif
