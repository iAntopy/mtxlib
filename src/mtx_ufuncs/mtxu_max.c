/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:19:54 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/15 00:20:47 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtxlib.h"

static int	*__mtx_max_i(int *arr, size_t n_elem)
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

static float	*__mtx_max_f(float *arr, size_t n_elem)
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


void	*mtxu_max(t_mtx *mtx)
{
	void	*res;

	res = NULL;
	if (mtx->dtype == DTYPE_I)
		res = __mtx_max_i(mtx->arr, mtx->shape[0] * mtx->shape[1]);
	else if (mtx->dtype == DTYPE_F)
		res = __mtx_max_f(mtx->arr, mtx->shape[0] * mtx->shape[1]);
	else
		perror("mtxu_max : dtype of mtx is invalid ");
	return (res);	
}
