/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_copp_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:10:29 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 00:05:53 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_init_cumul_opp(t_copp *co, t_mtx *a, t_mtx *out)
{
	co->a = _mtx_arr(a);
	co->o = _mtx_arr(out);
	co->as = a->strides;
	co->os = out->strides;
	co->r = a->shape[0];
	co->c = a->shape[1];
	co->av = NULL;
	co->ov = NULL;
}
/*
void	__mtx_execute_copp(t_mopp *mo)
{
	co->opp(co->av, co->ov);
}

void	__mtx_execute_unary_moppf(t_mopp *mo)
{
	*(float *)mo->ov = mo->oppf(*(float *)mo->av);
}

void	__mtx_execute_unary_moppi(t_mopp *mo)
{
	*(int *)mo->ov = mo->oppi(*(int *)mo->av);
}
*/
