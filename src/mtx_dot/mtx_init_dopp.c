/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_init_dopp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:05:40 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/11 21:51:10 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

t_dopp	*__mtx_init_dopp(t_dopp *dop, t_mtx *a, t_mtx *b, t_mtx *out)
{
	dop->inplace_mtx = NULL;
	if (a == out)
		dop->inplace_mtx = a;
	else if (b == out)
		dop->inplace_mtx = b;
	dop->is_pure = !(a->is_view || b->is_view);// || (out->is_view && !dop->inplace_mtx));
	dop->a = _mtx_arr(a);
	dop->b = _mtx_arr(b);
	if (dop->inplace_mtx || out->is_view)
	{
		if (!mtx_malloc_swap(out))
			return (MTX_ERROR("malloc error"));
		dop->o = out->swap;
	}
	else
		dop->o = _mtx_arr(out);
	dop->as = a->strides;
	dop->bs = b->strides;
	dop->os = out->strides;
	dop->n = a->shape[0];
	dop->m = a->shape[1];
	dop->l = b->shape[1];
	return (dop);
}
