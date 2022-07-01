/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_prod_sided.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 08:22:07 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 22:53:51 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	_mtx_prod_by_row_f(t_mtx *mtx, t_mtx *out)
{
	int		i;
	int		j;
	float	prod;
	float	*marr;
	float	*mout;

	marr = _mtx_arr(mtx);
	mout = _mtx_arr(out);
	i = -1;
	while (++i < mtx->shape[0])
	{
		j = -1;
		prod = 1;
		while (++j < mtx->shape[1])
			prod *= *(float *)_mtx_idx(marr, mtx->strides, i, j);
		*(float *)_mtx_idx(mout, out->strides, i, 0) = prod;
	}
}

void	_mtx_prod_by_col_f(t_mtx *mtx, t_mtx *out)
{
	int		i;
	int		j;
	float	prod;
	float	*marr;
	float	*mout;

	marr = _mtx_arr(mtx);
	mout = _mtx_arr(out);
	j = -1;
	while (++j < mtx->shape[1])
	{
		i = -1;
		prod = 1;
		while (++i < mtx->shape[0])
			prod *= *(float *)_mtx_idx(marr, mtx->strides, i, j);
		*(float *)_mtx_idx(mout, out->strides, j, 0) = prod;
	}
}

void	_mtx_prod_by_row_i(t_mtx *mtx, t_mtx *out)
{
	int	i;
	int	j;
	int	prod;
	int	*marr;
	int	*mout;

	marr = _mtx_arr(mtx);
	mout = _mtx_arr(out);
	i = -1;
	while (++i < mtx->shape[0])
	{
		j = -1;
		prod = 1;
		while (++j < mtx->shape[1])
			prod *= *(int *)_mtx_idx(marr, mtx->strides, i, j);
		*(int *)_mtx_idx(mout, out->strides, i, 0) = prod;
	}
}

void	_mtx_prod_by_col_i(t_mtx *mtx, t_mtx *out)
{
	int	i;
	int	j;
	int	prod;
	int	*marr;
	int	*mout;

	marr = _mtx_arr(mtx);
	mout = _mtx_arr(out);
	j = -1;
	while (++j < mtx->shape[1])
	{
		i = -1;
		prod = 1;
		while (++i < mtx->shape[0])
			prod *= *(int *)_mtx_idx(marr, mtx->strides, i, j);
		*(int *)_mtx_idx(mout, out->strides, j, 0) = prod;
	}
}
/*
t_mtx	*mtx_prod_sided(t_mtx *mtx, int axis, t_mtx *out)
{
	static UFUNC_SIDED	ufuncs[2][2] = {
	{_mtx_prod_by_col_i, _mtx_prod_by_col_f},
	{_mtx_prod_by_row_i, _mtx_prod_by_row_f}};
	t_mtx				*ret;

	if (!mtx_isvalid_sided_ufunc(mtx, axis, out, (char *)__FUNCTION__))
		return (NULL);
	ret = out;
	if (!ret && axis == ROWWISE)
		ret = mtx_create_empty(mtx->shape[1], 1, mtx->dtype);
	else if (!ret && axis == COLWISE)
		ret = mtx_create_empty(mtx->shape[0], 1, mtx->dtype);
	if (!mtx)
		return (MTX_ERROR("malloc error "));
	ufuncs[axis][mtx->dtype == DTYPE_F](mtx, ret);
	return (ret);
}
*/
