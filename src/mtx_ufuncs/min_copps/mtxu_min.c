/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_ZZZ.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:43:20 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 22:24:34 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

static t_mtx	*__route_min_rowwise(t_mtx *mtx, t_mtx *out)
{
	int	out_null;

	out_null = !out;
	if (out_null)
	{
		out = mtx_create_empty(mtx->shape[1], 1, mtx->dtype);
		if (!out)
			return (mtx_err((char *)__FUNCTION__, "malloc error"));
	}
	if (!mtx_are_same_type(mtx, out, NULL))
		return (mtx_err((char *)__FUNCTION__, "mtx/out dtype mismatch"));
	if (!(mtx->shape[1] == out->shape[0]))
		return (mtx_err((char *)__FUNCTION__, "invalid out shape"));
	if (mtx->dtype == DTYPE_F)
		_mtx_minf_row(mtx, out);
	else if (mtx->dtype == DTYPE_I)
		_mtx_mini_row(mtx, out);
	else if (out_null)
		return (mtx_e_clr((char *)__FUNCTION__, "invalid dtype", &out));
	else
		return (mtx_err((char *)__FUNCTION__, "invalid dtype"));
	return (out);
}

static t_mtx	*__route_min_colwise(t_mtx *mtx, t_mtx *out)
{
	int	out_null;

	out_null = !out;
	if (out_null)
	{
		out = mtx_create_empty(mtx->shape[0], 1, mtx->dtype);
		if (!out)
			return (mtx_err((char *)__FUNCTION__, "malloc error"));
	}
	if (!mtx_are_same_type(mtx, out, NULL))
		return (mtx_err((char *)__FUNCTION__, "mtx/out dtype mismatch"));
	if (!(mtx->shape[0] == out->shape[0]))
		return (mtx_err((char *)__FUNCTION__, "invalid out shape"));
	if (mtx->dtype == DTYPE_F)
		_mtx_minf_col(mtx, out);
	else if (mtx->dtype == DTYPE_I)
		_mtx_mini_col(mtx, out);
	else if (out_null)
		return (mtx_e_clr((char *)__FUNCTION__, "invalid dtype", &out));
	else
		return (mtx_err((char *)__FUNCTION__, "invalid dtype"));
	return (out);
}

static t_mtx	*__route_min_whole(t_mtx *mtx, t_mtx *out)
{
	int	out_null;

	out_null = !out;
	if (out_null)
	{
		out = mtx_create_empty(1, 1, mtx->dtype);
		if (!out)
			return (mtx_err((char *)__FUNCTION__, "malloc error"));
	}
	if (!mtx_are_same_type(mtx, out, NULL))
		return (mtx_err((char *)__FUNCTION__, "mtx/out dtype mismatch"));
	if (!((out->shape[0] == 1) && out->shape[1] == 1))
		return (mtx_err((char *)__FUNCTION__, "invalid out shape"));
	if (mtx->dtype == DTYPE_F)
		_mtx_minf_whole(mtx, out);
	else if (mtx->dtype == DTYPE_I)
		_mtx_mini_whole(mtx, out);
	else if (out_null)
		return (mtx_e_clr((char *)__FUNCTION__, "invalid dtype", &out));
	else
		return (mtx_err((char *)__FUNCTION__, "invalid dtype"));
	return (out);
}

t_mtx	*mtx_min(t_mtx *mtx, int axis, t_mtx *out)
{
	t_mtx	*ret;

	ret = out;
	if (!mtx)
		return (mtx_err((char *)__FUNCTION__, "no input mtx"));
	if (axis == ROWWISE)
		ret = __route_min_rowwise(mtx, ret);
	else if (axis == COLWISE)
		ret = __route_min_colwise(mtx, ret);
	else if (axis == WHOLE)
		ret = __route_min_whole(mtx, ret);
	else
		return (mtx_err((char *)__FUNCTION__, "invalid axis"));
	return (ret);
}
