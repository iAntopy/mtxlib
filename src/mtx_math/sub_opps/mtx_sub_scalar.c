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

void	_mtx_isubf_scalar(t_mtx *a, t_mtx *b)
{
	_mtx_opp_scalar(a, b, a, __mtx_std_subf);
}

void	_mtx_subf_scalar(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_scalar(a, b, out, __mtx_std_subf);
}

void	_mtx_isubi_scalar(t_mtx *a, t_mtx *b)
{
	_mtx_opp_scalar(a, b, a, __mtx_std_subi);
}

void	_mtx_subi_scalar(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_scalar(a, b, out, __mtx_std_subi);
}
