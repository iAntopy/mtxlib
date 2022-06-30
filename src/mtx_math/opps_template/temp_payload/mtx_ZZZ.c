/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_ZZZ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:33:18 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 01:09:45 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

static void	put_biggest_first(t_mtx **a, t_mtx **b, int *rev, int same_sh)
{
	t_mtx	*temp;

	if (!same_sh && ((*a == NULL) || ((*a)->shape[0] == 1)
			|| ((*a)->ndims == 1 && (*b)->ndims == 2)))
	{	
		temp = *a;
		*a = *b;
		*b = temp;
		if (*b != NULL)
			*rev = 1;
	}
}

static t_mtx	*route_opp(t_mtx *a, t_mtx *b, t_mtx *out, int same_sh)
{
	static MOPP_FUNC	opps[2][6] = {
		{_mtx_ZZZi_scalar, _mtx_rZZZi_scalar, _mtx_ZZZi_line_r,
		_mtx_rZZZi_line_r, _mtx_ZZZi_line_c, _mtx_rZZZi_line_c},
		{_mtx_ZZZf_scalar, _mtx_rZZZf_scalar, _mtx_ZZZf_line_r,
		_mtx_rZZZf_line_r, _mtx_ZZZf_line_c, _mtx_rZZZf_line_c}};
	int					rev;

	printf("routing opp\n");
	rev = 0;
	put_biggest_first(&a, &b, &rev, same_sh);
	if (b->shape[0] == 1)
	{
		printf("Routing scalar opp\n");
		opps[a->dtype == DTYPE_F][0 + rev](a, b, out);
	}
	else if ((b->shape[0] == a->shape[1]) && !b->is_transposed)
	{
		printf("Routing line by row opp\n");
		opps[a->dtype == DTYPE_F][2 + rev](a, b, out);
	}
	else if ((b->shape[0] == a->shape[0]) && b->is_transposed)
	{
		printf("Routing line by column opp\n");
		opps[a->dtype == DTYPE_F][4 + rev](a, b, out);
	}
	else
	{
		printf("Erreur sur la personne.\n");
		return (fperror("%s: mismatch shapes ", __FUNCTION__));
	}
	return (out);
}

t_mtx	*mtx_ZZZ(t_mtx *a, t_mtx *b, t_mtx *out)
{
	t_mtx	*ret;
	int		same_shape;

	ret = out;
	printf("mtx_ZZZ entered\n");
	if (!(a || b) || !mtx_are_same_type(a, b, ret))
		return (fperror("%s: missing inputs or mismatch dtypes", __FUNCTION__));
	same_shape = mtx_are_same_shape(a, b);
	printf("same_shape : %d\n", same_shape);
	if (!ret && !mtx_dup_empty(a, &ret, a->dtype))
		return (fperror("%s: malloc error", __FUNCTION__));
	printf("ret is valid\n");
	if (same_shape && (a->dtype == DTYPE_F))
		_mtx_ZZZf_mtx(a, b, ret);
	else if (same_shape && (a->dtype == DTYPE_I))
		_mtx_ZZZi_mtx(a, b, ret);
	else
		route_opp(a, b, ret, same_shape);
	printf("mtx_ZZZ SUCCESSFUL\n");
	return (ret);
}
