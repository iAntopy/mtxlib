/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_ZZZ_whole.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:22:55 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/03 20:33:04 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_ZZZf_whole(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_ZZZf_init;
	co.cumul_opp = __mtx_ZZZf_cumul;
	co.post_opp = __mtx_ZZZf_post;
	_mtx_copp_whole(&co);
}

void	_mtx_ZZZi_whole(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_ZZZi_init;
	co.cumul_opp = __mtx_ZZZi_cumul;
	co.post_opp = __mtx_ZZZi_post;
	_mtx_copp_whole(&co);
}
