/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_identity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 22:01:06 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/22 02:09:04 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

static void	fill_identity_i(t_mtx *mtx)
{
	int	i;

	i = -1;
	while (++i < mtx->shape[0])
		*(int *)_mtx_idx(mtx->arr, mtx->strides, i, i) = 1;
}

static void	fill_identity_f(t_mtx *mtx)
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
		return ((t_mtx *)fperror("mtx_identity : %d is invalid n", n));
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
		return (fperror("%s: malloc error", __FUNCTION__));
	if (dtype == DTYPE_I)
		fill_identity_i(mtx);
	else if (dtype == DTYPE_F)
		fill_identity_f(mtx);
	return (mtx);
}
/*
int	main()
{
	t_mtx	*mtx;

	mtx = mtx_identity(3, DTYPE_I);
	mtx_print(mtx);
	mtx_clear(&mtx);
	return (0);
}*/
