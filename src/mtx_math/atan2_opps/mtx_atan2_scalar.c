/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_ZZZ_scalar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 02:13:20 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 04:22:15 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_iatan2f_scalar(t_mtx *a, t_mtx *b)
{
	_mtx_opp_scalar(a, b, a, __mtx_std_atan2f);
}

void	_mtx_atan2f_scalar(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_scalar(a, b, out, __mtx_std_atan2f);
}

void	_mtx_iatan2i_scalar(t_mtx *a, t_mtx *b)
{
	_mtx_opp_scalar(a, b, a, __mtx_std_atan2i);
}

void	_mtx_atan2i_scalar(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_scalar(a, b, out, __mtx_std_atan2i);
}
