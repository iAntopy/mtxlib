/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_mul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:33:18 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 04:06:36 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

static void	put_biggest_first(t_mtx **a, t_mtx **b, int specs[2])
{
	t_mtx	*temp;

	specs[1] = 0;
	if (!specs[0] && ((*a == NULL) || ((*a)->shape[0] == 1)
			|| ((*a)->ndims == 1 && (*b)->ndims == 2)))
	{	
		temp = *a;
		*a = *b;
		*b = temp;
		if (*b != NULL)
			specs[1] = 1;
	}
}

static t_mtx	*route_opp(t_mtx *a, t_mtx *b, t_mtx *out, int specs[2])
{
	static MOPP_FUNC	opps[2][6] = {
	{_mtx_muli_scalar, _mtx_rmuli_scalar, _mtx_muli_line_r,
		_mtx_rmuli_line_r, _mtx_muli_line_c, _mtx_rmuli_line_c},
	{_mtx_mulf_scalar, _mtx_rmulf_scalar, _mtx_mulf_line_r,
		_mtx_rmulf_line_r, _mtx_mulf_line_c, _mtx_rmulf_line_c}};
	int					rev;
	MOPP_FUNC			act_opp;

	rev = specs[1];
	act_opp = NULL;
	if (b->shape[0] == 1)
		act_opp = opps[a->dtype == DTYPE_F][0 + rev];
	else if ((b->shape[0] == a->shape[1]) && !b->is_transposed)
		act_opp = opps[a->dtype == DTYPE_F][2 + rev];
	else if ((b->shape[0] == a->shape[0]) && b->is_transposed)
		act_opp = opps[a->dtype == DTYPE_F][4 + rev];
	if (act_opp)
		act_opp(a, b, out);
	else
		return (MTX_ERROR("mismatch shapes "));
	return (out);
}

t_mtx	*mtx_mul(t_mtx *a, t_mtx *b, t_mtx *out)
{
	t_mtx	*ret;
	int		same_shape;
	int		specs[2];
	int		out_null;

	out_null = !out;
	ret = out;
	if (!(a || b) || !mtx_are_same_type(a, b, ret))
		return (MTX_ERROR("missing inputs or mismatch dtypes"));
	same_shape = mtx_are_same_shape(a, b);
	specs[0] = same_shape;
	put_biggest_first(&a, &b, specs);
	if (!ret && !mtx_dup_empty(a, &ret, a->dtype))
		return (MTX_ERROR("malloc error"));
	if (same_shape && (a->dtype == DTYPE_F))
		_mtx_mulf_mtx(a, b, ret);
	else if (same_shape && (a->dtype == DTYPE_I))
		_mtx_muli_mtx(a, b, ret);
	else if (!route_opp(a, b, ret, specs))
	{
		if (out_null)
			mtx_clear(&ret);
		ret = NULL;
	}
	return (ret);
}
