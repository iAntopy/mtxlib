/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_combine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:28:07 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/09 15:40:46 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

static void	__quat_combine(t_quat *q1, t_quat *q2, t_quat *out, float t)
{
	float	w;
	float	a;
	float	b;
	float	c;
	float	*q;

	q = q1->q;
	w = q2->q[0];
	a = q2->q[1];
	b = q2->q[2];
	c = q2->q[3];
	out->q[0] = w * q[0] - a * q[1] - b * q[2] - c * q[3];
	out->q[1] = w * q[1] + a * q[0] + b * q[3] - c * q[2];
	out->q[2] = w * q[2] - a * q[3] + b * q[0] + c * q[1];
	out->q[3] = w * q[3] + a * q[2] - b * q[1] + c * q[0];
	t = sinf(acosf(out->q[0]));
	out->ang = 2 * t;
	out->uv[1] = out->q[1] / t;
	out->uv[2] = out->q[2] / t;
	out->uv[3] = out->q[3] / t;
}

t_quat	*quat_combine(t_quat *q1, t_quat *q2, t_quat *out)
{
	t_quat	*ret;

	if (!q1 || !q2)
		return (MTX_ERROR("missing params"));
	ret = out;
	if (!ret)
		ret = quat_create_empty(NULL);
	if (!ret)
		return (MTX_ERROR("malloc error"));
	__quat_combine(q1, q2, ret, 0);
	__quat_init_rot_mtx(ret->rot_mtx, ret->q, ret->q[0]);
//	mtx_dot(q1->mtx, q2->mtx, out->mtx, 0);
	return (ret);
}
