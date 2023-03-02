/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_ZZZf_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 01:31:10 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 04:21:06 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_mulf_line_r(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_line_row(a, b, out, __mtx_std_mulf);
}

void	_mtx_imulf_line_r(t_mtx *a, t_mtx *b)
{
	_mtx_opp_line_row(a, b, a, __mtx_std_mulf);
}

void	_mtx_mulf_line_c(t_mtx *a, t_mtx *b, t_mtx *out)
{
	_mtx_opp_line_col(a, b, out, __mtx_std_mulf);
}

void	_mtx_imulf_line_c(t_mtx *a, t_mtx *b)
{
	_mtx_opp_line_col(a, b, a, __mtx_std_mulf);
}
