/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_dot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 15:00:42 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/02 00:05:54 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// Called when a && b are NOT views
static void	__route_dot_pure(t_dopp *dop, t_mtx *a, t_mtx *b, t_mtx *out)
{
	static t_dopp_fc	dot_funcs[2][2] = {
	{_mtx_dot_nxn_ii_to_pure, _mtx_dot_nxn_if_to_pure},
	{_mtx_dot_nxn_fi_to_pure, _mtx_dot_nxn_ff_to_pure}};

	dot_funcs[a->dtype == DTYPE_F][b->dtype == DTYPE_F](dop);
	if (out->is_view)
		__mtx_copy_view_swap_to_array_4bytes(out);
	else if (dop->inplace_mtx)
	{
		_mtx_swap_arrays(out);
	}
}

// Only called when output is not inplace and is view.
static void	__route_dot_to_view(t_dopp *dop, t_mtx *a, t_mtx *b, t_mtx *out)
{
	static t_dopp_fc	dot_funcs[2][2] = {
	{_mtx_dot_nxn_ii_to_view, _mtx_dot_nxn_if_to_view},
	{_mtx_dot_nxn_fi_to_view, _mtx_dot_nxn_ff_to_view}};

	(void)out;
	dot_funcs[a->dtype == DTYPE_F][b->dtype == DTYPE_F](dop);
}

// Called when >= 1 input is view or transposed.
static void	__route_dot_to_arr(t_dopp *dop, t_mtx *a, t_mtx *b, t_mtx *out)
{
	static t_dopp_fc	dot_funcs[2][2] = {
	{_mtx_dot_nxn_ii_to_arr, _mtx_dot_nxn_if_to_arr},
	{_mtx_dot_nxn_fi_to_arr, _mtx_dot_nxn_ff_to_arr}};

	dot_funcs[a->dtype == DTYPE_F][b->dtype == DTYPE_F](dop);
	if (dop->inplace_mtx)
	{
		if (dop->inplace_mtx->is_view || out->is_view)
		{
			__mtx_copy_view_swap_to_array_4bytes(out);
		}
		else
		{
			_mtx_swap_arrays(out);
		}
	}
}

t_mtx	*mtx_dot(t_mtx *a, t_mtx *b, t_mtx *out)
{
	t_mtx	*ret;
	t_dopp	dop;

	ret = out;
	if ((out && !mtx_isvalid_broadcast_to_dot(a, b, out))
		|| (!out && !mtx_isvalid_broadcast_dot(a, b)))
		return (mtx_err((char *)__FUNCTION__, "invalid broadcast"));
	if (!mtx_isvalid_dtype(a->dtype) || !mtx_isvalid_dtype(b->dtype))
		return (mtx_err((char *)__FUNCTION__, "invalid mtx dtype"));
	if (!ret)
		ret = mtx_create_empty(a->shape[0], b->shape[1], mtx_dtype_out(a, b));
	if (!ret || !__mtx_init_dopp(&dop, a, b, ret))
		return (mtx_err((char *)__FUNCTION__, "malloc error"));
	if (dop.is_pure)
		__route_dot_pure(&dop, a, b, ret);
	else if (!dop.inplace_mtx && ret->is_view)
		__route_dot_to_view(&dop, a, b, ret);
	else
		__route_dot_to_arr(&dop, a, b, ret);
	return (ret);
}
