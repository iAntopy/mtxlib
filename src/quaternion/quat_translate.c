/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_translate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:31:38 by iamongeo          #+#    #+#             */
/*   Updated: 2023/02/28 23:32:20 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// All quaternion translations are done inplace, inside the quaternion 
// rotation matrix. 

t_quat	*_quat_translation_set(t_quat *q, float x, float y, float z)
{
	float	*_arr;

	if (!q)
		return (MTX_ERROR("missing quaternion"));
	_arr = (float *)_mtx_arr(q->rot_mtx);
	*(_arr++) = x;
	*(_arr++) = y;
	*(_arr++) = z;
	*(_arr++) = 1;
	return (q);
}

t_quat	*_quat_translation_move(t_quat *q, float dx, float dy, float dz)
{
	float	*_arr;

	if (!q)
		return (MTX_ERROR("missing quaternion"));
	_arr = (float *)_mtx_arr(q->rot_mtx);
	*(_arr++) += dx;
	*(_arr++) += dy;
	*(_arr++) += dz;
	*(_arr++) = 1;
	return (q);
}

// pos must indexable as row vector.
t_quat	*quat_translation_set(t_quat *q, t_mtx *pos)
{
	float	*_qarr;
	float	*_parr;

	if (!q || !pos || (pos->dtype != DTYPE_F))
		return (MTX_ERROR("missing quaternion or pos, or dtype not float."));
	_qarr = (float *)_mtx_arr(q->rot_mtx);
	_parr = (float *)_mtx_arr(pos);
	*(_qarr++) += *(_parr++);
	*(_qarr++) += *(_parr++);
	*(_qarr++) += *(_parr++);
	*(_qarr++) = 1;
	return (q);
}

// pos must contiguous row vector [dx, dy, dz, 0].
t_quat	*quat_translation_move(t_quat *q, t_mtx *delta)
{
	float	*_qarr;
	float	*_parr;

	if (!q || !delta || (delta->dtype != DTYPE_F))
		return (MTX_ERROR("missing quaternion or pos, or dtype not float."));
	_qarr = (float *)_mtx_arr(q->rot_mtx);
	_parr = (float *)_mtx_arr(delta);
	*(_qarr++) += *(_parr++);
	*(_qarr++) += *(_parr++);
	*(_qarr++) += *(_parr++);
	*(_qarr++) = 1;
	return (q);
}
