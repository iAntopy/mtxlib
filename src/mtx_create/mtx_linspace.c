/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_linspace.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:32:42 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/02 08:54:43 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

static void	__mtx_fill_linspace(float *arr, float start, float incr, int n_divs)
{
	while (n_divs--)
	{
		*(arr++) = start;
		start += incr;
	}
}

// Only available with floats. w_end will segment the linear space so that
// the last entry == end. In other words, if (w_end != 0) then end is inclusive 
// otherwise is end exclusive.
t_mtx	*mtx_linspace(float start, float end, int n_divs, int w_end)
{
	t_mtx	*mtx;
	float	incr;

	if (!n_divs || start == end)
		return (mtx_err((char *)__FUNCTION__,
				"mtx_linspace : n_divs or range == 0"));
	mtx = mtx_create_empty(n_divs, 1, DTYPE_F);
	if (!mtx)
		return (NULL);
	incr = (end - start) / (n_divs - !!w_end);
	__mtx_fill_linspace((float *)_mtx_arr(mtx), start, incr, n_divs);
	return (mtx);
}

t_mtx	*mtx_linspace_update(t_mtx *mtx, float start, float end, int w_end)
{
	float	incr;
	int		n_divs;

	if (start == end)
		return (mtx_err((char *)__FUNCTION__,
				"mtx_linspace : range == 0"));
	n_divs = mtx->shape[0];
	incr = (end - start) / (n_divs - !!w_end);
	__mtx_fill_linspace((float *)_mtx_arr(mtx), start, incr, n_divs);
	return (mtx);
}
