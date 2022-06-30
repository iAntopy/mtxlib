/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_unary_opps_apply.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 22:12:37 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/26 00:01:40 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_apply_f(t_mopp *mo)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mo->r)
	{
		j = -1;
		while (++j < mo->c)
		{
			__mtx_execute_unary_moppf(mo);
			mo->av = _mtx_idx(mo->a, mo->as, i, j);
			mo->ov = _mtx_idx(mo->o, mo->os, i, j);
		}
	}
}

void	_mtx_apply_i(t_mopp *mo)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mo->r)
	{
		j = -1;
		while (++j < mo->c)
		{
			__mtx_execute_unary_moppi(mo);
			mo->av = _mtx_idx(mo->a, mo->as, i, j);
			mo->ov = _mtx_idx(mo->o, mo->os, i, j);
		}
	}
}

t_mtx	*mtx_apply_f(t_mtx *a, float (*func)(float), t_mtx *out)
{
	t_mopp	mo;
	t_mtx	*ret;

	if (!a && a->dtype == DTYPE_F)
		return (fperror("%s: no input mtx or has wrong dtype", __FUNCTION__));
	ret = out;
	if (!ret && !mtx_dup_empty(a, &ret, DTYPE_F))
		return (fperror("%s: malloc error", __FUNCTION__));
	else if (!mtx_are_same_type(a, out, NULL) || !mtx_are_same_shape(a, ret))
		return (fperror("%s: a=>out shape or dtype mismatch", __FUNCTION__));
	__mtx_init_math_opp(&mo, a, a, out);
	mo.oppf = func;
	_mtx_apply_f(&mo);
	return (ret);
}

t_mtx	*mtx_apply_i(t_mtx *a, int (*func)(int), t_mtx *out)
{
	t_mopp	mo;
	t_mtx	*ret;

	if (!a && a->dtype == DTYPE_I)
		return (fperror("%s: no input mtx or has wrong dtype", __FUNCTION__));
	ret = out;
	if (!ret && !mtx_dup_empty(a, &ret, DTYPE_I))
		return (fperror("%s: malloc error", __FUNCTION__));
	else if (!mtx_are_same_type(a, out, NULL) || !mtx_are_same_shape(a, ret))
		return (fperror("%s: a=>out shape or dtype mismatch", __FUNCTION__));
	__mtx_init_math_opp(&mo, a, a, out);
	mo.oppi = func;
	_mtx_apply_i(&mo);
	return (ret);
}
