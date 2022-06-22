/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_init_opp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:49:37 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/22 02:33:49 by iamongeo         ###   ########.fr       */
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
	mo->av = _mtx_idx(mo->a, mo->as, 0, 0);
	mo->bv = _mtx_idx(mo->b, mo->bs, 0, 0);
	mo->ov = _mtx_idx(mo->o, mo->os, 0, 0);
}

void	_mtx_execute_mopp(t_mopp *mo)
{
	mo->opp(mo->av, mo->bv, mo->ov);
}
