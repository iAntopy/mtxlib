/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_meani_COPPS.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:33:43 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 23:36:50 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_meani_init(int *a, int *out)
{
	(void)a;
	*out = 0;
}

void	__mtx_meani_cumul(int *a, int *out)
{
	*out += *a;
}

void	__mtx_meani_post(int *out, int n)
{
	*out /= n;
}
