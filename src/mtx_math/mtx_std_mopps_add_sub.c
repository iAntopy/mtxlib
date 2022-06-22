/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_std_mopps_add_sub.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:05:11 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/21 03:05:20 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_std_addi(int *v1, int *v2, int *out)
{
	*out = *v1 + *v2;
}

void	__mtx_std_addf(float *v1, float *v2, float *out)
{
	*out = *v1 + *v2;
}

void	__mtx_std_subi(int *v1, int *v2, int *out)
{
	*out = *v1 - *v2;
}

void	__mtx_std_subf(float *v1, float *v2, float *out)
{
	*out = *v1 - *v2;
}
