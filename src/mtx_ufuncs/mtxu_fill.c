/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_fill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:53:46 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 05:09:15 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtxlib.h"

// Does NOT work with views, Very fast.
t_mtx	*__mtx_fill_zeros(t_mtx *mtx)
{
	ft_memclear(mtx->arr, mtx_sizeof_array(mtx));
	return (mtx);
}

t_mtx	*_mtx_fill_zeros(t_mtx *mtx)
{
	int	i;
	int	j;
	int	*arr;

	if (mtx_get_dsize(mtx->dtype) != 4)
		return (MTX_ERROR("Can't fill mtx with dsize other then 4"));
	arr = _mtx_arr(mtx);
	i = -1;
	while (++i < mtx->shape[0])
	{
		j = -1;
		while (++j < mtx->shape[1])
			*(int *)_mtx_idx(arr, mtx->strides, i, j) = 0;
	}
	return (mtx);
}

static void	__mtx_fill(void *a, void *v, size_t dsize, size_t n_elems)
{
	char	*carr;
	int		*iarr;
	size_t	*sarr;

	if (dsize == sizeof(int))
	{
		iarr = (int *)a;
		while (n_elems--)
			*(iarr++) = *(int *)v;
	}
	else if (dsize == sizeof(char))
	{
		carr = (char *)a;
		while (n_elems--)
			*(carr++) = *(char *)v;
	}
	else if (dsize == sizeof(size_t))
	{
		sarr = (size_t *)a;
		while (n_elems--)
			*(sarr++) = *(size_t *)v;
	}
}

static void	__mtx_fill_view(t_mtx *m, void *value, size_t dsize)
{
	int		r;
	int		c;
	int		i;
	int		j;
	void	*arr;

	r = m->shape[0];
	c = m->shape[1];
	i = -1;
	arr = _mtx_arr(m);
	while (++i < r)
	{
		j = -1;
		while (++j < c)
		{
			if (dsize == sizeof(int))
				*(int *)_mtx_idx(arr, m->strides, i, j) = *(int *)value;
			else if (dsize == sizeof(size_t))
				*(size_t *)_mtx_idx(arr, m->strides, i, j) = *(size_t *)value;
			else if (dsize == sizeof(char))
				*(char *)_mtx_idx(arr, m->strides, i, j) = *(char *)value;
		}
	}
}

//fills matrix with the value pointed by void *. The size of the 
//value to copy is derived from the matrix dtype.
t_mtx	*mtx_fill(t_mtx *mtx, void *value)
{
	size_t	dsize;

	if (!mtx || !value)
		return (MTX_ERROR("missing params"));
	dsize = mtx_get_dsize(mtx->dtype);
	if (mtx->is_view)
	{
		if ((dsize == 4) && (*(int *)value == 0))
			_mtx_fill_zeros(mtx);
		else
			__mtx_fill_view(mtx, value, dsize);
	}
	else
	{
		if ((dsize == 4) && (*(int *)value == 0))
			__mtx_fill_zeros(mtx);
		else
			__mtx_fill(mtx->arr, value, dsize, mtx_get_nb_elems(mtx));
	}
	return (mtx);
}
