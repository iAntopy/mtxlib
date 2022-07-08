/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_identity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:01:06 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/07 17:08:17 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__fill_identity_i(int n, int *arr)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			*(arr++) = (i == j);
	}
}

void	__fill_identity_f(int n, float *arr)
{
	int	i;
	int	j;

	i = -1;
	while (++i < n)
	{
		j = -1;
		while (++j < n)
			*(arr++) = (i == j);
	}
}

void	fill_identity_i(t_mtx *mtx)
{
	int	i;

	i = -1;
	while (++i < mtx->shape[0])
		*(int *)_mtx_idx(mtx->arr, mtx->strides, i, i) = 1;
}

void	fill_identity_f(t_mtx *mtx)
{
	int	i;

	i = -1;
	while (++i < mtx->shape[0])
		*(float *)_mtx_idx(mtx->arr, mtx->strides, i, i) = 1;
}

t_mtx	*mtx_identity(int n, t_mtx *out, int dtype)
{
	t_mtx	*mtx;
	size_t	v;

	if (n < 1)
		return (MTX_ERROR("invalid negative shape value"));
	if (out)
	{
		mtx = out;
		v = 0;
		mtx_fill(out, &v);
		dtype = out->dtype;
	}
	else
		mtx = mtx_create_zeros(n, n, dtype);
	if (!mtx)
		return (MTX_ERROR("malloc error"));
	if (dtype == DTYPE_I)
		fill_identity_i(mtx);
	else if (dtype == DTYPE_F)
		fill_identity_f(mtx);
	return (mtx);
}
