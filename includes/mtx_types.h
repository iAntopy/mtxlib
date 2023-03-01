/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:14:49 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 05:17:42 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTX_TYPES_H
# define MTX_TYPES_H

enum	e_mtx_data_types
{
	DTYPE_I = 0,
	DTYPE_F = 1
};

enum	e_mtx_axis_IDs
{
	WHOLE = -1,
	ROWWISE = 0,
	COLWISE = 1
};

typedef struct s_mtx_base
{
	int		ndims;
	int		dtype;
	int		shape[MAX_DIMS];
	int		strides[MAX_DIMS];
	void	*arr;
	void	*swap;
	void	**view_ptr;
	int		is_view;
	size_t	offset;
	int		is_transposed;
}	t_mtx;

typedef struct s_math_opp
{
	void	*a;
	void	*b;
	void	*o;
	int		*as;
	int		*bs;
	int		*os;
	int		r;
	int		c;
	void	*av;
	void	*bv;
	void	*ov;
	void	(*opp)();
	float	(*oppf)(float);
	int		(*oppi)(int);
}	t_mopp;

typedef struct s_cumul_opp
{
	void	*a;
	void	*o;
	int		*as;
	int		*os;
	int		r;
	int		c;
	void	*av;
	void	*ov;
	void	(*init_opp)();
	void	(*cumul_opp)();
	void	(*post_opp)();
}	t_copp;

typedef struct s_dot_opp
{
	void	*a;
	void	*b;
	void	*o;
	int		*as;
	int		*bs;
	int		*os;
	int		n;
	int		m;
	int		l;
	int		is_pure;
	t_mtx	*inplace_mtx;
}	t_dopp;

typedef struct s_quaternion_base
{
	float	ang;
	float	uv[4];
	float	q[4];
	t_mtx	*rot_mtx;
	t_mtx	*translation;
	t_mtx	__mtx;
	float	__rot_arr[4][4];
	t_mtx	__tr_view;
}	t_quat;

typedef void (* MOPP_FUNC)(t_mtx *, t_mtx *, t_mtx *);
typedef void (* DOPP_FUNC)(t_dopp *);

#endif
