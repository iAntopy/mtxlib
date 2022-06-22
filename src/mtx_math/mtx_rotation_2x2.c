/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_rotation_2x2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 01:56:14 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/22 02:33:12 by iamongeo         ###   ########.fr       */
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

// Assumes that out mtx is 3x3.
void	__mtx_rotation_matrix_2x2(float ang, float *out)
{
	__fill_roll_rotmat_3x3(sinf(rll), cos(rll), out);
}

t_mtx	*mtx_get_rotmat_2x2(float rll, float pch, float yaw, t_mtx *out)
{
	t_mtx	*ret;
	float	sa;
	float	ca;

	ret = out;
	if (out && !(out->shape[0] == 2 && out->shape[1] == 2))
		return (fperror("%s: wrong output shape", __FUNCTION__));
	if (!ret)
	{
		ret = mtx_create_empty(2, 2, DTYPE_F);
		if (!ret)
			return (fperror("%s: malloc error", __FUNCTION__));
	}
	__fill_rotmat_2x2(sinf(ang), cosf(ang), ret->arr);
	return (ret);	
}
