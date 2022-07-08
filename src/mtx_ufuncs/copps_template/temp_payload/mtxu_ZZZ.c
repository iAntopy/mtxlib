/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_ZZZ.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:43:20 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/04 02:00:12 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

static t_mtx	*__route_ZZZ_rowwise(t_mtx *mtx, t_mtx *out)
{
	int	out_null;

	out_null = !out;
	if (out_null)
	{
		out = mtx_create_empty(mtx->shape[1], 1, mtx->dtype);
		if (!out)
			return (MTX_ERROR("malloc error"));
	}
	if (!mtx_are_same_type(mtx, out, NULL))
		return (MTX_ERROR("mtx/out dtype mismatch"));
	if (!(mtx->shape[1] == out->shape[0]))
		return (MTX_ERROR("invalid out shape"));
	if (mtx->dtype == DTYPE_F)
		_mtx_ZZZf_row(mtx, out);//_mtx_ZZZ_by_col_f(mtx, out);
	else if (mtx->dtype == DTYPE_I)
		_mtx_ZZZi_row(mtx, out);
	else if (out_null)
		return (MTX_ERR_CLR("invalid dtype", &out));
	else
		return (MTX_ERROR("invalid dtype"));
	return (out);
}

static t_mtx	*__route_ZZZ_colwise(t_mtx *mtx, t_mtx *out)
{
	int	out_null;

	out_null = !out;
	if (out_null)
	{
		out = mtx_create_empty(mtx->shape[0], 1, mtx->dtype);
		if (!out)
			return (MTX_ERROR("malloc error"));
	}
	if (!mtx_are_same_type(mtx, out, NULL))
		return (MTX_ERROR("mtx/out dtype mismatch"));
	if (!(mtx->shape[0] == out->shape[0]))
		return (MTX_ERROR("invalid out shape"));
	if (mtx->dtype == DTYPE_F)
		_mtx_ZZZf_col(mtx, out);
	else if (mtx->dtype == DTYPE_I)
		_mtx_ZZZi_col(mtx, out);
	else if (out_null)
		return (MTX_ERR_CLR("invalid dtype", &out));
	else
		return (MTX_ERROR("invalid dtype"));
	return (out);
}

static t_mtx	*__route_ZZZ_whole(t_mtx *mtx, t_mtx *out)
{
	int	out_null;

	out_null = !out;
	if (out_null)
	{
		out = mtx_create_empty(1, 1, mtx->dtype);
		if (!out)
			return (MTX_ERROR("malloc error"));
	}
	if (!mtx_are_same_type(mtx, out, NULL))
		return (MTX_ERROR("mtx/out dtype mismatch"));
	if (!((out->shape[0] == 1) && out->shape[1] == 1))
		return (MTX_ERROR("invalid out shape"));
	if (mtx->dtype == DTYPE_F)
		_mtx_ZZZf_whole(mtx, out);
	else if (mtx->dtype == DTYPE_I)
		_mtx_ZZZi_whole(mtx, out);
	else if (out_null)
		return (MTX_ERR_CLR("invalid dtype", &out));
	else
		return (MTX_ERROR("invalid dtype"));
	return (out);
}

t_mtx	*mtx_ZZZ(t_mtx *mtx, int axis, t_mtx *out)
{
	t_mtx	*ret;

	ret = out;
	if (!mtx)
		return (MTX_ERROR("no input mtx"));
	if (axis == ROWWISE)	
		ret = __route_ZZZ_rowwise(mtx, ret);
	else if (axis == COLWISE)	
		ret = __route_ZZZ_colwise(mtx, ret);
	else if (axis == WHOLE)
		ret = __route_ZZZ_whole(mtx, ret);
	else
		return (MTX_ERROR("invalid axis"));
	return (ret);
}