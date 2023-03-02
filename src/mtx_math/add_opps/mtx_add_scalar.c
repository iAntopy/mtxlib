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

void	_mtx_iaddf_scalar(t_mtx *a, t_mtx *b)
{
	_mtx_opp_scalar(a, b, a, __mtx_std_addf);
}

void	_mtx_addf_scalar(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_scalar(a, b, out, __mtx_std_addf);
}

void	_mtx_iaddi_scalar(t_mtx *a, t_mtx *b)
{
	_mtx_opp_scalar(a, b, a, __mtx_std_addi);
}

void	_mtx_addi_scalar(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_scalar(a, b, out, __mtx_std_addi);
}
