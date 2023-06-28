/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_doti_1D.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 03:29:17 by iamongeo          #+#    #+#             */
/*   Updated: 2023/06/27 21:22:19 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

int	_mtx_doti_1d_1d(t_mtx *m1, t_mtx *m2)
{
	int		res;
	int		*ma1;
	int		*ma2;
	size_t	n_elems;

	res = 0;
	ma1 = (int *)m1->arr;
	ma2 = (int *)m2->arr;
	n_elems = m1->shape[0];
	while (n_elems--)
		res += (*(ma1++)) * (*(ma2++));
	return (res);
}

int	_mtx_doti_1x2_1x2(t_mtx *m1, t_mtx *m2)
{
	return (((int *)m1->arr)[0] * ((int *)m2->arr)[0]
		+ ((int *)m1->arr)[1] * ((int *)m2->arr)[1]);
}

int	_mtx_doti_1x3_1x3(t_mtx *m1, t_mtx *m2)
{
	return (((int *)m1->arr)[0] * ((int *)m2->arr)[0]
		+ ((int *)m1->arr)[1] * ((int *)m2->arr)[1]
		+ ((int *)m1->arr)[2] * ((int *)m2->arr)[2]);
}

int	_mtx_doti_1x4_1x4(t_mtx *m1, t_mtx *m2)
{
	return (((int *)m1->arr)[0] * ((int *)m2->arr)[0]
		+ ((int *)m1->arr)[1] * ((int *)m2->arr)[1]
		+ ((int *)m1->arr)[2] * ((int *)m2->arr)[2]
		+ ((int *)m1->arr)[3] * ((int *)m2->arr)[3]);
}

int	mtx_doti_1d_1d(t_mtx *m1, t_mtx *m2)
{
	if (!mtx_isvalid_broadcast_dot(m1, m2))
	{
		mtx_err((char *)__FUNCTION__, "invalid broadcast");
		return (0);
	}
	else if (!((m1->shape[0] == 1) && (m2->shape[0] == 1))
		|| (m1->dtype != DTYPE_I))
	{
		mtx_err((char *)__FUNCTION__, "mtx not 1d or not DTYPE_I");
		return (0);
	}
	return (_mtx_doti_1d_1d(m1, m2));
}
