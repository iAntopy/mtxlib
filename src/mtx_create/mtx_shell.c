/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_shell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:47:09 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/29 20:05:25 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// Initializes stack declared t_mtx. This is to avoid mallocing
// a t_mtx for intermidiary steps in a greater calculation.
// A stack matrix shell will serve as output to one matrix fonction call
// and input to an other and will naturally be discarded at the end of
// function where it is declared.
// The array should also be declared on the stack and set as mtx->arr.
// No verification is made that the array is the right size so 
// use carefully.
void	mtx_shell(t_mtx *mtx, int rows, int cols, int dtype)
{
	if (!mtx || (rows < 1) || (cols < 1))
		fperror("%s: input missing or row/col < 1", __FUNCTION__);
	if (!mtx_isvalid_dtype(dtype))
		fperror("%s: dtype is invalid", __FUNCTION__);
	if ((rows == 1) || (cols == 1))
		__mtx_setup_1d(mtx, rows, cols, mtx_get_dsize(dtype));
	else
		__mtx_setup_2d(mtx, rows, cols, mtx_get_dsize(dtype));
	/*
	if ((rows == 1) || (cols == 1))
	{
		mtx->ndims = (unsigned char)1;
		mtx->shape[0] = (rows > 1) * rows + (cols > 1) * cols;
		mtx->shape[1] = 1;
		mtx->strides[0] = mtx_get_dsize(dtype);
		mtx->strides[1] = 0;
	}
	else
	{
		mtx->ndims = (unsigned char)2;
		mtx->shape[0] = rows;
		mtx->shape[1] = cols;
		mtx->strides[0] = mtx_get_dsize(dtype);
		mtx->strides[1] = mtx->strides[0] * cols;
	}
	*/
	mtx->is_view = 0;
	mtx->is_transposed = 0;
	mtx->dtype = dtype;
	mtx->view_ptr = &mtx->arr;
	mtx->swap = NULL;
	mtx->offset = 0;
}
