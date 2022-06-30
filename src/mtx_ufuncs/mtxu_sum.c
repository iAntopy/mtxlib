/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_sum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 08:16:27 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/26 01:07:53 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

//works on full raw array, NOT on views.
int	__mtxu_sum_i(int *arr, size_t n_elem)
{
	int	sum;

	sum = *(arr++);
	while (--n_elem)
		sum += *(arr++);
	return (sum);
}

//works on full raw array, NOT on views.
float	__mtxu_sum_f(float *arr, size_t n_elem)
{
	float	sum;

	sum = *(arr++);
	while (--n_elem)
		sum += *(arr++);
	return (sum);
}

float	_mtxu_sum_f(t_mtx *mtx)
{
	int		i;
	int		j;
	float	sum;
	float	*arr;

	arr = _mtx_arr(mtx);
	i = mtx->shape[0];
	sum = 1;
	while (--i)
	{
		j = mtx->shape[1];
		while (--j)
			sum += *(float *)_mtx_idx(arr, mtx->strides, i, j);
	}
	return (sum);
}

int	_mtxu_sum_i(t_mtx *mtx)
{
	int	i;
	int	j;
	int	sum;
	int	*arr;

	arr = _mtx_arr(mtx);
	i = mtx->shape[0];
	sum = 1;
	while (--i)
	{
		j = mtx->shape[1];
		while (--j)
			sum += *(int *)_mtx_idx(arr, mtx->strides, i, j);
	}
	return (sum);
}

void	*mtxu_sum(t_mtx *mtx, void *out)
{
	int		res_i;
	float	res_f;

	if (mtx->dtype == DTYPE_I)
	{
		if (mtx->is_view)
			res_i = _mtxu_sum_i(mtx);
		else
			res_i = __mtxu_sum_i(mtx->arr, mtx_get_nb_elems(mtx));
		*(int *)out = res_i;
	}
	else if (mtx->dtype == DTYPE_F)
	{
		if (mtx->is_view)
			res_f = _mtxu_sum_f(mtx);
		else
			res_f = __mtxu_sum_f(mtx->arr, mtx_get_nb_elems(mtx));
		*(float *)out = res_f;
	}
	else
		fperror("%s : mtx->dtype is invalid", __FUNCTION__);
	return (out);
}
