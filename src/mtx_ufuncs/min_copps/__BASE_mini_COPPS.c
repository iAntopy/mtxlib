/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_mini_COPPS.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:12:36 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 23:36:12 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_mini_init(int *a, int *out)
{
	(void)a;
	*out = INT_MAX;
}

void	__mtx_mini_cumul(int *a, int *out)
{
	if (*a < *out)
		*out = *a;
}

void	__mtx_mini_post(int *out, int n)
{
	(void)n;
	(void)out;
	return ;
}
