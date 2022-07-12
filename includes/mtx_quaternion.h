/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_quaternion.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:13:30 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/11 22:07:26 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MTX_QUATERNION_H
# define MTX_QUATERNION_H

# include "mtx_types.h"

// QUATERNION CREATE

t_quat	*quat_create(float ang, float x, float y, float z);
t_quat	*quat_create_empty(t_quat *out);
void	_quat_update(t_quat *q, float vect[3], float ang);

// QUATERNION ROTATION

t_mtx	*quat_rotate(t_mtx *mtx, t_quat *q, t_mtx *out);
t_mtx	*quat_irotate(t_mtx *mtx, t_quat *q);
t_mtx	*_quat_rotate(t_mtx *mtx, t_quat *q, t_mtx *out);
t_mtx	*_quat_irotate(t_mtx *mtx, t_quat *q);

#endif
