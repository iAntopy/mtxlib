/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_slice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:21:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/15 06:25:06 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtxlib.h"

// mtx_slice_view provides a seperate t_mtx struct which gives a view of 
// a slice of the original matrix described by the slice param.
// A view means that the data of the array is the same as the original array
// so that changes made in the view matrix DO change the data in the original.
// A view matrix can be transposed just as a regular matrix with mtx_transpose.
//
// slice is a 4 int array where each member represents the following:
//	- slice[0] = row_s = starting row index.
//	- slice[1] = col_s = starting col index.
//	- slice[2] = row_e = ending row index (indexed exclisivly [row_s:row_e[ ).
//	- slice[3] = col_e = ending col index (indexed exclisivly [col_s:col_e[ ).
// [side]_e must be greater than [side_s].
// if INT_MAX is given as [side]_e, slicing is done to the end of this side of 
// matrix. Indices must within [0:shape[side][ exclusively.

t_mtx	*mtx_slice_view(t_mtx *mtx, const int slice[4])
{
	t_mtx	*ret;
	int		rrange;
	int		crange;

	if (!mtx || !mtx_index_is_inbound(mtx, slice[0], slice[1])
		|| !mtx_index_is_inbound(mtx, slice[2] - 1, slice[3] - 1))
		return (fperror("mtx_slice_view : no mtx or out of bound : %d, %d",
				slice[0], slice[2]));
	rrange = slice[2] - slice[0];
	crange = slice[3] - slice[1];
	if (rrange < 1 || crange < 1)
		return (fperror("mtx_slice_view : non conforming ranges : r %d, c %d",
				rrange, crange));
	ret = mtx_dup_struct(mtx);
	ret->arr = mtx->arr + (mtx->strides[0] * slice[0]);
	ret->arr += mtx->strides[1] * slice[1];
	ret->shape[0] = rrange;
	ret->shape[1] = crange;
	ret->is_view = 1;
	if (rrange == 1)
		mtx_transpose(ret);
	ret->ndims = 2 - (rrange == 1 || crange == 1);
	return (ret);
}
