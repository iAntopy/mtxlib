/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_swap_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 02:01:52 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/21 19:17:30 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

int	mtx_swap_arrays(t_mtx *mtx)
{
	void	*temp;

	if (!mtx || !mtx->swap)
	{
		fperror("%s : !mtx or !swap", __FUNCTION__);
		return (0);
	}
	temp = mtx->arr;
	mtx->arr = mtx->swap;
	mtx->swap = temp;
	return (1);
}

void	*mtx_malloc_swap(t_mtx *mtx)
{
	if (!mtx)
		return (fperror("%s : no mtx given", __FUNCTION__));
	if (!mtx->swap
		&& !malloc_free_p(mtx_sizeof_array(mtx), (void **)&mtx->swap))
		return (fperror("%s : malloc error", __FUNCTION__));
	return (mtx->swap);
}

int	__mtx_copy_view_swap_to_array_4bytes(t_mtx *view)
{
	int	i;
	int	j;
	int	c;
	size_t	dsize;
	int	*swap;

	dsize = mtx_get_dsize(view->dtype);
	if (!view || !view->is_view || !view->swap || dsize != 4)
	{
		fperror("%s : no view or !is_view or !swap or dsize != 4", __FUNCTION__);
		return (0);
	}
	c = view->shape[1];
	swap = view->swap;
	i = -1;
	while (++i < view->shape[0])
	{
		j = -1;
		while (++j < c)
			*(int *)_mtx_idx(view, i, j) = *(swap++);
	}
	return (1);
}
