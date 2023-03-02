/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_sumf_COPPS.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:12:36 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 23:37:21 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_sumf_init(float *a, float *out)
{
	(void)a;
	*out = 0;
}

void	__mtx_sumf_cumul(float *a, float *out)
{
	*out += *a;
}

void	__mtx_sumf_post(float *out, int n)
{
	(void)out;
	(void)n;
	return ;
}
