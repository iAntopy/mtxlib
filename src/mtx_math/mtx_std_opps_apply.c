/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_std_opps_apply.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 02:33:54 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/21 21:48:22 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_std_scalar(t_mopp *mo)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mo->r)
	{
		j = -1;
		while (++j < mo->c)
		{
			__mtx_execute_mopp(mo);
			mo->av = _mtx_idx(mo->a, mo->as, i, j);
			mo->ov = _mtx_idx(mo->o, mo->os, i, j);
		}
	}
}

void	__mtx_std_mtx(t_mopp *mo)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mo->r)
	{
		j = -1;
		while (++j < mo->c)
		{
			__mtx_execute_mopp(mo);
			mo->av = _mtx_idx(mo->a, mo->as, i, j);
			mo->bv = _mtx_idx(mo->b, mo->bs, i, j);
			mo->ov = _mtx_idx(mo->o, mo->os, i, j);
		}
	}
}

void	__mtx_std_line_col(t_mopp *mo)
{
	int	i;
	int	j;

	i = -1;
	while (++i < mo->r)
	{
		j = -1;
		mo->bv = _mtx_idx(mo->b, mo->bs, i, 0);
		while (++j < mo->c)
		{
			__mtx_execute_mopp(mo);
			mo->av = _mtx_idx(mo->a, mo->as, i, j);
			mo->ov = _mtx_idx(mo->o, mo->os, i, j);
		}
	}
}

void	__mtx_std_line_row(t_mopp *mo)
{
	int	i;
	int	j;

	j = -1;
	while (++j < mo->c)
	{
		i = -1;
		mo->bv = _mtx_idx(mo->b, mo->bs, j, 0);
		while (++i < mo->r)
		{
			__mtx_execute_mopp(mo);
			mo->av = _mtx_idx(mo->a, mo->as, i, j);
			mo->ov = _mtx_idx(mo->o, mo->os, i, j);
		}
	}
}

