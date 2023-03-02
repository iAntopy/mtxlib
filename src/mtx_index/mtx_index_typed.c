/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_index_typed.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:31:10 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/02 08:17:46 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// Doesn't work for views. Optimized. Unsafe. Returns value ptr.
inline int	*_mtx_index_iptr(t_mtx *mtx, int row, int col)
{
	return (mtx->arr + (row * mtx->strides[0] + col * mtx->strides[1]));
}

// Doesn't work for views. Optimized. Unsafe. Returns value ptr.
inline float	*_mtx_index_fptr(t_mtx *mtx, int row, int col)
{
	return (mtx->arr + (row * mtx->strides[0] + col * mtx->strides[1]));
}

// Doesn't work for views. Optimized. Unsafe. Returns value value.
inline int	_mtx_index_i(t_mtx *mtx, int row, int col)
{
	return (*(int *)(mtx->arr
		+ (row * mtx->strides[0] + col * mtx->strides[1])));
}

// Doesn't work for views. Optimized. Unsafe. Returns value value.
inline float	_mtx_index_f(t_mtx *mtx, int row, int col)
{
	return (*(float *)(mtx->arr
		+ (row * mtx->strides[0] + col * mtx->strides[1])));
}
