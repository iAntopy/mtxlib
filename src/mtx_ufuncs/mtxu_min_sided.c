/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_min_sided.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 03:26:05 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 21:22:15 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_min_by_row_f(t_mtx *mtx, t_mtx *out)
{
	int		i;
	int		j;
	float	res;
	float	value;
	float	*arr;

	arr = _mtx_arr(mtx);
	i = -1;
	while (++i < mtx->shape[0])
	{
		j = 0;
		res = *(float *)_mtx_idx(arr, mtx->strides, i, j);
		while (++j < mtx->shape[1])
		{
			value = *(float *)_mtx_idx(arr, mtx->strides, i, j);
			if (value < res)
				res = value;
		}
		*(float *)_mtx_idx(_mtx_arr(out), out->strides, i, 0) = res;
	}
}

void	_mtx_min_by_col_f(t_mtx *mtx, t_mtx *out)
{
	int		i;
	int		j;
	float	res;
	float	value;
	float	*arr;

	arr = _mtx_arr(mtx);
	j = -1;
	while (++j < mtx->shape[1])
	{
		i = 0;
		res = *(float *)_mtx_idx(arr, mtx->strides, i, j);
		while (++i < mtx->shape[0])
		{
			value = *(float *)_mtx_idx(arr, mtx->strides, i, j);
			if (value < res)
				res = value;
		}
		*(float *)_mtx_idx(_mtx_arr(out), out->strides, j, 0) = res;
	}
}

void	_mtx_min_by_row_i(t_mtx *mtx, t_mtx *out)
{
	int	i;
	int	j;
	int	res;
	int	value;
	int	*arr;

	arr = _mtx_arr(mtx);
	i = -1;
	while (++i < mtx->shape[0])
	{
		j = 0;
		res = *(int *)_mtx_idx(arr, mtx->strides, i, j);
		while (++j < mtx->shape[1])
		{
			value = *(int *)_mtx_idx(arr, mtx->strides, i, j);
			if (value < res)
				res = value;
		}
		*(int *)_mtx_idx(_mtx_arr(out), out->strides, i, 0) = res;
	}
}

void	_mtx_min_by_col_i(t_mtx *mtx, t_mtx *out)
{
	int	i;
	int	j;
	int	res;
	int	value;
	int	*arr;

	arr = _mtx_arr(mtx);
	j = -1;
	while (++j < mtx->shape[1])
	{
		i = 0;
		res = *(int *)_mtx_idx(arr, mtx->strides, i, j);
		while (++i < mtx->shape[0])
		{
			value = *(int *)_mtx_idx(arr, mtx->strides, i, j);
			if (value < res)
				res = value;
		}
		*(int *)_mtx_idx(_mtx_arr(out), out->strides, j, 0) = res;
	}
}

t_mtx	*mtx_min_sided(t_mtx *mtx, int axis, t_mtx *out)
{
	static UFUNC_SIDED	ufuncs[2][2] = {
	{_mtx_min_by_col_i, _mtx_min_by_col_f},
	{_mtx_min_by_row_i, _mtx_min_by_row_f}};
	t_mtx				*ret;

	if (!mtx_isvalid_sided_ufunc(mtx, axis, out, (char *)__FUNCTION__))
		return (MTX_ERROR("invalid opperation in given axis"));
	ret = out;
	if (!ret && axis == ROWWISE)
		ret = mtx_create_empty(mtx->shape[1], 1, mtx->dtype);
	else if (!ret && axis == COLWISE)
		ret = mtx_create_empty(mtx->shape[0], 1, mtx->dtype);
	if (!ret)
		return (MTX_ERROR("malloc error"));
	ufuncs[axis][mtx->dtype == DTYPE_F](mtx, ret);
	return (ret);
}
