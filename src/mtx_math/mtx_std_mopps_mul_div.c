/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_std_mopps_mul_div.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:25:15 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/20 20:26:47 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_std_muli(int *v1, int *v2, int *out)
{
	*out = (*v1) * (*v2);
}

void	__mtx_std_mulf(float *v1, float *v2, float *out)
{
	*out = (*v1) * (*v2);
}

void	__mtx_std_divi(int *v1, int *v2, int *out)
{
	*out = *v1 / *v2;
}

void	__mtx_std_divf(float *v1, float *v2, float *out)
{
	*out = *v1 / *v2;
}
