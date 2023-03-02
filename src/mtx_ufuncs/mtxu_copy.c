/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxu_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 22:35:05 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 23:18:20 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

t_mtx	*mtx_dup_struct(t_mtx *mtx, t_mtx **out)
{
	t_mtx	*new;

	if (!mtx)
		return (mtx_err((char *)__FUNCTION__, "no input mtx"));
	if (!malloc_free_p(sizeof(t_mtx), (void **)&new))
		return (mtx_err((char *)__FUNCTION__, "malloc error"));
	ft_memcpy(new, mtx, sizeof(t_mtx));
	new->arr = NULL;
	new->swap = NULL;
	if (out)
		*out = new;
	return (new);
}

t_mtx	*mtx_dup_empty(t_mtx *mtx, t_mtx **out, int dtype)
{
	t_mtx	*new;
	size_t	arr_size;

	if (!mtx
		|| (dtype && mtx_get_dsize(mtx->dtype) != mtx_get_dsize(dtype)))
		return (mtx_err((char *)__FUNCTION__, "no mtx or dsize mismatch"));
	if (!mtx_dup_struct(mtx, &new))
		return (mtx_err((char *)__FUNCTION__, "malloc error"));
	arr_size = mtx_sizeof_array(mtx);
	if (!malloc_free_p(arr_size, (void **)&(new->arr)))
	{
		mtx_clear(&new);
		return (mtx_err((char *)__FUNCTION__, "malloc error "));
	}
	new->dtype = dtype;
	new->view_ptr = &(new->arr);
	if (out)
		*out = new;
	return (new);
}

// CANNOT BE VIEW
t_mtx	*mtx_copy(t_mtx *mtx)
{
	t_mtx	*new;

	if (!mtx)
		return (mtx_err((char *)__FUNCTION__, "no intput mtx"));
	if (mtx->is_view)
		return (mtx_err((char *)__FUNCTION__, "cannot copy view"));
	if (!mtx_dup_empty(mtx, &new, mtx->dtype))
		return (mtx_err((char *)__FUNCTION__, "malloc error"));
	ft_memcpy(new->arr, mtx->arr, mtx_sizeof_array(mtx));
	return (new);
}
