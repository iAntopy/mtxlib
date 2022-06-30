/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_hypot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 08:04:15 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/27 00:38:43 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// The mtx_hypot functions treats a <n x m> matrix as a series of vectors and
// gives their lengths in a <n x 1> vector. The only allowed dtype is float.
// CANNOT BE VIEW.
void	__mtx_hypot(float *arr, int r, int c, float *out)
{
	int		j;
	
	while (r--)
	{
		*out = 0;
		j = -1;
		while (++j < c)
		{
			*out += (*arr) * (*arr);
			arr++;
		}
		*out = sqrtf(*out);
		out++;
	}
}

// CAN BE VIEW
void	_mtx_hypot(t_mtx *mtx, t_mtx *out)
{
	int		i;
	int		j;
	float	*oarr;
	float	*marr;
	float	*ov;
	
	oarr = (float *)_mtx_arr(out);
	marr = (float *)_mtx_arr(mtx);
	i = -1;
	while (++i < mtx->shape[0])
	{
		ov = (float *)_mtx_idx(oarr, out->strides, i, 0);
		*ov = 0;
		j = -1;
		while (++j < mtx->shape[1])
			*ov += powf(*(float *)_mtx_idx(marr, mtx->strides, i, j), 2);
		*ov = sqrtf(*ov);
	}
}

// CANNOT BE VIEW.
void	__mtx_hypot_nx3(float *arr, int r, float *out)
{
	while (r--)
	{
		*(out++) = sqrtf((*arr) * (*arr) + arr[1] * arr[1]
			+ arr[2] * arr[2]);
		arr += 3;
	}
}

// CANNOT BE VIEW.
void	__mtx_hypot_nx4(float *arr, int r, float *out)
{
	while (r--)
	{
		*(out++) = sqrtf((*arr) * (*arr) + arr[1] * arr[1]
			+ arr[2] * arr[2] + arr[3] * arr[3]);
		arr += 4;
	}
}

t_mtx	*mtx_hypot(t_mtx *mtx, t_mtx *out)
{
	t_mtx	*ret;

	if (!mtx || mtx->dtype != DTYPE_F)
		return (fperror("%s : !mtx or dtype != DTYPE_F ", __FUNCTION__));
	ret = out;
	if (!ret && !mtx_create_empty(mtx->shape[0], 1, DTYPE_F))
		return (fperror("%s : malloc error ", __FUNCTION__));
	else if (out->shape[1] != 1 || out->shape[0] != mtx->shape[0]
		|| out->dtype != DTYPE_F)
		return (fperror("%s : out shape or dtype mismatch", __FUNCTION__));
	_mtx_hypot(mtx, out);//mtx->arr, mtx->shape[0], mtx->shape[1], out->arr);
	return (ret);
}
