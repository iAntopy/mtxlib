/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_combine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:28:07 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/12 21:53:09 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// Doesn't work inplace
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

t_quat	*quat_add(t_quat *q, float rll, float ptc, float yaw)
{
	t_quat	q2;
	t_quat	q3;
	float	v[3];

	if (!q)
		return (MTX_ERROR("missing params"));
	if (!(rll || ptc || yaw))
		return (q);
	quat_create_empty(&q2);
	quat_create_empty(&q3);
	if (rll)
	{
		_quat_update(q2,);
		q3.uv[1] = 1;
		q3.uv[2] = 0;
		q3.uv[3] = 0;
		_quat_update(rll, q3.uv + 1, 0);
		quat
	}


	if (!ret)
		ret = quat_create_empty(NULL);
	if (!ret)
		return (MTX_ERROR("malloc error"));
	__quat_combine(q1, q2, ret, 0);
	__quat_init_rot_mtx(ret->rot_mtx, ret->q, ret->q[0]);
//	mtx_dot(q1->mtx, q2->mtx, out->mtx, 0);
	free(q2);
	free(q3);
	return (ret);
}
