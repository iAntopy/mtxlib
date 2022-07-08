/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 01:33:38 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/08 14:13:35 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// The _quat*() versions do no validations on shape, dtype or swap status.
// They are most efficient but check what you are doing.
void	_quat_rotate(t_mtx *mtx, t_quat *q, float *out)
{
	__mtx_dotf_nx4_4x4(mtx->shape[0], mtx->arr, (float *)q->rot_mtx, out);
}

//Assumes mtx is <n x 4> and DTYPE_F and mtx and q exist and mtx is NOT view.
void	_quat_irotate(t_mtx *mtx, t_quat *q)
{
	if (!mtx->swap && !mtx_malloc_swap(mtx))
		return (MTX_ERROR("malloc error"));
	__mtx_dotf_nx4_4x4(mtx->shape[0], mtx->arr, (float *)q->rot_mtx, mtx->swap);
	_mtx_swap_arrays(mtx);		
}

void	*quat_irotate(t_mtx *mtx, t_quat *q)
{
	if (!mtx || !q)
		return (MTX_ERROR("missing params"));
	if (mtx->is_view)
		return (MTX_ERROR("Can't output quaternion rotation to view"));
	else if (!mtx_malloc_swap(mtx))
		return (MTX_ERROR("malloc error"));
	__mtx_dotf_nx4_4x4(mtx->shape[0], mtx->arr, (float *)q->rot_mtx, mtx->swap);
	if (!mtx_swap_arrays(mtx))
		return (MTX_ERROR("swap error"));
	return ((void *)SIZE_MAX);
}

// The output array MUST NOT be mtx itself. Use quat_irotate for inplace rotation.
// out CANNOT be a view matrix. Quaternions only opperate on nx4 matrices.
void	*quat_rotate(t_mtx *mtx, t_quat *q, t_mtx *out)
{
	if (!mtx || !q || !out)
		return (fperror("%s : missing params", __FUNCTION__));
	if (!mtx_are_same_shape(mtx, out))
		return (fperror("%s : mtx and out shape mismatch.", __FUNCTION__));
	__mtx_dotf_nx4_4x4(mtx->shape[0], mtx->arr, (float *)q->rot_mtx, out->arr);
	return ((void *)SIZE_MAX);
}
