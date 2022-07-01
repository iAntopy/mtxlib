/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_prod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 08:16:27 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 22:41:26 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

static t_mtx	*__route_prod_rowwise(t_mtx *mtx, t_mtx *out)
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
	if (dtype == DTYPE_F)
		_mtx_prod_by_col_f(mtx, out);
	else if (dtype == DTYPE_I)
		_mtx_prod_by_col_i(mtx, out);
	else if (out_null)
		return (MTX_ERR_CLR("invalid dtype", out));
	else
		return (MTX_ERROR("invalid dtype"));
	return (out);
}

static t_mtx	*__route_prod_colwise(t_mtx *mtx, t_mtx *out)
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
	if (dtype == DTYPE_F)
		_mtx_prod_by_row_f(mtx, out);
	else if (dtype == DTYPE_I)
		_mtx_prod_by_row_i(mtx, out);
	else if (out_null)
		return (MTX_ERR_CLR("invalid dtype", out));
	else
		return (MTX_ERROR("invalid dtype"));
	return (out);
}

static t_mtx	*__route_prod_whole(t_mtx *mtx, t_mtx *out)
{
	int	out_null;

	out_null = !out;
	if (out_null)
	{
		out = mtx_create_scalar(1, 1, mtx->dtype);
		if (!out)
			return (MTX_ERROR("malloc error"));
	}
	if (!mtx_are_same_type(mtx, out, NULL))
		return (MTX_ERROR("mtx/out dtype mismatch"));
	if (!((out->shape[0] == 1) && out->shape[1] == 1))
		return (MTX_ERROR("invalid out shape"));
	if (mtx->dtype == DTYPE_F)
		_mtx_prod_f(mtx, out);
	else if (mtx->dtype == DTYPE_I)
		_mtx_prod_i(mtx, out);
	else if (out_null)
		return (MTX_ERR_CLR("invalid dtype", out));
	else
		return (MTX_ERROR("invalid dtype"));
	return (out);
}

t_mtx	*mtx_prod(t_mtx *mtx, int axis, t_mtx *out)
{
	t_mtx	*ret;

	ret = out;
	if (!mtx)
		return (MTX_ERROR("no input mtx"));
	if (axis == ROWWISE)	
		ret = __route_prod_rowwise(mtx, ret);
	else if (axis == COLWISE)	
		ret = __route_prod_colwise(mtx, ret);
	else if (axis == WHOLE)
		ret = __route_prod_whole(mtx, ret);
	else
		return (MTX_ERROR("invalid axis"));
	return (ret);
}
