/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rZZZ_scalar.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:13:46 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 04:21:53 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_ripowf_scalar(t_mtx *a, t_mtx *b)
{
	_mtx_opp_scalar(a, b, a, __mtx_std_rpowf);
}

void	_mtx_rpowf_scalar(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_scalar(a, b, out, __mtx_std_rpowf);
}

void	_mtx_ripowi_scalar(t_mtx *a, t_mtx *b)
{
	_mtx_opp_scalar(a, b, a, __mtx_std_rpowi);
}

void	_mtx_rpowi_scalar(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_scalar(a, b, out, __mtx_std_rpowi);
}
