/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_ZZZ_whole.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 16:22:55 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/28 23:42:33 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_meanf_whole(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_meanf_init;
	co.cumul_opp = __mtx_meanf_cumul;
	co.post_opp = __mtx_meanf_post;
	_mtx_copp_whole(&co);
}

void	_mtx_meani_whole(t_mtx *mtx, t_mtx *out)
{
	t_copp	co;

	__mtx_init_cumul_opp(&co, mtx, out);
	co.init_opp = __mtx_meani_init;
	co.cumul_opp = __mtx_meani_cumul;
	co.post_opp = __mtx_meani_post;
	_mtx_copp_whole(&co);
}
