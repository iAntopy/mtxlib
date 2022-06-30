/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:19:54 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/26 00:40:01 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtxlib.h"

int	*__mtxu_max_i(int *arr, size_t n_elem)
{
	int	*res;

	res = arr;
	while (n_elem--)
	{
		if (*arr > *res)
			res = arr;
		arr++;
	}
	return (res);
}

float	*__mtxu_max_f(float *arr, size_t n_elem)
{
	float	*res;

	res = arr;
	while (n_elem--)
	{
		if (*arr > *res)
			res = arr;
		arr++;
	}
	return (res);
}

float	*_mtxu_max_f(t_mtx *mtx)
{
	int		i;
	int		j;
	float	*res;
	float	*value;
	void	*arr;

	arr = _mtx_arr(mtx);
	res = (float *)arr;
	i = mtx->shape[0];
	while (i--)
	{
		j = -1;
		while (++j < mtx->shape[1])
		{
			value = (float *)_mtx_idx(arr, mtx->strides, i, j);
			if (*value > *res)
				res = value;
		}
	}
	return (res);
}

int	*_mtxu_max_i(t_mtx *mtx)
{
	int		i;
	int		j;
	int		*res;
	int		*value;
	void	*arr;

	arr = _mtx_arr(mtx);
	res = (int *)arr;
	i = mtx->shape[0];
	while (i--)
	{
		j = -1;
		while (++j < mtx->shape[1])
		{
			value = (int *)_mtx_idx(arr, mtx->strides, i, j);
			if (*value > *res)
				res = value;
		}
	}
	return (res);
}

void	*mtxu_max(t_mtx *mtx)
{
	void	*res;

	res = NULL;
	if (mtx->dtype == DTYPE_I)
	{
		if (mtx->is_view)
			res = _mtxu_max_i(mtx);
		else
			res = __mtxu_max_i(mtx->arr, mtx_get_nb_elems(mtx));//mtx->shape[0] * mtx->shape[1]);
	}
	else if (mtx->dtype == DTYPE_F)
	{
		if (mtx->is_view)
			res = _mtxu_max_f(mtx);
		else
			res = __mtxu_max_f(mtx->arr, mtx_get_nb_elems(mtx));
	}
	else
		perror("mtxu_max : dtype of mtx is invalid ");
	return (res);	
}
