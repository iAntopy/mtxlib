/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_scalar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 17:28:18 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/03 04:59:05 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

t_mtx	*mtx_create_scalar(void *s, int dtype)
{
	t_mtx	*mtx;

	mtx = mtx_create_array(s, 1, 1, dtype);
	if (!mtx)
		return (NULL);
	return (mtx);
}
