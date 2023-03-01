/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_init_opp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:49:37 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 04:13:38 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_init_math_opp(t_mopp *mo, t_mtx *a, t_mtx *b, t_mtx *out)
{
	mo->a = _mtx_arr(a);
	mo->b = _mtx_arr(b);
	mo->o = _mtx_arr(out);
	mo->as = a->strides;
	mo->bs = b->strides;
	mo->os = out->strides;
	mo->r = a->shape[0];
	mo->c = a->shape[1];
	mo->av = NULL;
	mo->bv = NULL;
	mo->ov = NULL;
}

void	__mtx_execute_mopp(t_mopp *mo)
{
	mo->opp(mo->av, mo->bv, mo->ov);
}

void	__mtx_execute_unary_moppf(t_mopp *mo)
{
	*(float *)mo->ov = mo->oppf(*(float *)mo->av);
}

void	__mtx_execute_unary_moppi(t_mopp *mo)
{
	*(int *)mo->ov = mo->oppi(*(int *)mo->av);
}
