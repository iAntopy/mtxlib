/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_prod_whole.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:40:14 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 22:40:24 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_prod_f(t_mtx *mtx, t_mtx *out)
{
	int		i;
	int		j;
	float	*arr;
	float	*ov;

	arr = _mtx_arr(mtx);
	i = mtx->shape[0];
	ov = (int *)_mtx_idx(_mtx_arr(out), out->strides, 0, 0);
	*ov = 1;
	while (--i)
	{
		j = mtx->shape[1];
		while (--j)
			*ov *= *(float *)_mtx_idx(arr, mtx->strides, i, j);
	}
}

void	_mtx_prod_i(t_mtx *mtx, t_mtx *out)
{
	int	i;
	int	j;
	int	*arr;
	int	*ov;

	arr = _mtx_arr(mtx);
	i = mtx->shape[0];
	ov = (int *)_mtx_idx(_mtx_arr(out), out->strides, 0, 0);
	*ov = 1;
	while (--i)
	{
		j = mtx->shape[1];
		while (--j)
			*ov *= *(int *)_mtx_idx(arr, mtx->strides, i, j);
	}
}
