/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rotation_2x2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 01:56:14 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 23:19:45 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

static void	__fill_rotmat_2x2(float sin_ang, float cos_ang, float *arr)
{
	*(arr++) = cos_ang;
	*(arr++) = -sin_ang;
	*(arr++) = sin_ang;
	*(arr++) = cos_ang;
}

t_mtx	*mtx_get_rotmat_2x2(float ang, t_mtx *out)
{
	t_mtx	*ret;

	ret = out;
	if (out && !(out->shape[0] == 2 && out->shape[1] == 2))
		return (mtx_err((char *)__FUNCTION__, "wrong output shape"));
	if (!ret)
	{
		ret = mtx_create_empty(2, 2, DTYPE_F);
		if (!ret)
			return (mtx_err((char *)__FUNCTION__, "malloc error"));
	}
	__fill_rotmat_2x2(sinf(ang), cosf(ang), ret->arr);
	return (ret);
}
