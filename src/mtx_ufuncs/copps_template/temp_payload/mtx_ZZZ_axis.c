/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_ZZZ_axis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:32:03 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/03 20:32:57 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_ZZZf_row(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_ZZZf_init;
	co.cumul_opp = __mtx_ZZZf_cumul;
	co.post_opp = __mtx_ZZZf_post;
	_mtx_copp_by_col(&co);
}

void	_mtx_ZZZf_col(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_ZZZf_init;
	co.cumul_opp = __mtx_ZZZf_cumul;
	co.post_opp = __mtx_ZZZf_post;
	_mtx_copp_by_row(&co);
}

void	_mtx_ZZZi_row(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_ZZZi_init;
	co.cumul_opp = __mtx_ZZZi_cumul;
	co.post_opp = __mtx_ZZZi_post;
	_mtx_copp_by_col(&co);
}

void	_mtx_ZZZi_col(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_ZZZi_init;
	co.cumul_opp = __mtx_ZZZi_cumul;
	co.post_opp = __mtx_ZZZi_post;
	_mtx_copp_by_row(&co);
}
