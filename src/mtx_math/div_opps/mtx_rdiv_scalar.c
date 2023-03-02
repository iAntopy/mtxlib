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

void	_mtx_ridivf_scalar(t_mtx *a, t_mtx *b)
{
	_mtx_opp_scalar(a, b, a, __mtx_std_rdivf);
}

void	_mtx_rdivf_scalar(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_scalar(a, b, out, __mtx_std_rdivf);
}

void	_mtx_ridivi_scalar(t_mtx *a, t_mtx *b)
{
	_mtx_opp_scalar(a, b, a, __mtx_std_rdivi);
}

void	_mtx_rdivi_scalar(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_scalar(a, b, out, __mtx_std_rdivi);
}
