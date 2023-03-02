/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_meanf_COPPS.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:33:43 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 23:36:45 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_meanf_init(float *a, float *out)
{
	(void)a;
	*out = 0;
}

void	__mtx_meanf_cumul(float *a, float *out)
{
	*out += *a;
}

void	__mtx_meanf_post(float *out, int n)
{
	*out /= n;
}
