/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_combine.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 16:28:07 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/08 14:02:18 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

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
	mtx_dot(q1->mtx, q2->mtx, out->mtx);
}
