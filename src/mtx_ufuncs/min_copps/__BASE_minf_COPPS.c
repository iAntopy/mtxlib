/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_minf_COPPS.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:12:36 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 23:36:18 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_minf_init(float *a, float *out)
{
	(void)a;
	*out = INT_MAX;
}

void	__mtx_minf_cumul(float *a, float *out)
{
	if (*a < *out)
		*out = *a;
}

void	__mtx_minf_post(float *out, int n)
{
	(void)n;
	(void)out;
	return ;
}
