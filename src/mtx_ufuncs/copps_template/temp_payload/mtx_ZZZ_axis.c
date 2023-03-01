/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_ZZZ_axis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:32:03 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/28 23:42:15 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_zzzf_row(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_zzzf_init;
	co.cumul_opp = __mtx_zzzf_cumul;
	co.post_opp = __mtx_zzzf_post;
	_mtx_copp_by_col(&co);
}

void	_mtx_zzzf_col(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_zzzf_init;
	co.cumul_opp = __mtx_zzzf_cumul;
	co.post_opp = __mtx_zzzf_post;
	_mtx_copp_by_row(&co);
}

void	_mtx_zzzi_row(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_zzzi_init;
	co.cumul_opp = __mtx_zzzi_cumul;
	co.post_opp = __mtx_zzzi_post;
	_mtx_copp_by_col(&co);
}

void	_mtx_zzzi_col(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_zzzi_init;
	co.cumul_opp = __mtx_zzzi_cumul;
	co.post_opp = __mtx_zzzi_post;
	_mtx_copp_by_row(&co);
}
