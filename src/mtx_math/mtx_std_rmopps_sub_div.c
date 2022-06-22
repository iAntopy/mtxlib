/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_std_rev_mopps.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 02:54:26 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/21 02:58:55 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_rstd_subi(int *v1, int *v2, int *out)
{
	*out = *v2 - *v1;
}

void	__mtx_rstd_subf(float *v1, float *v2, float *out)
{
	*out = *v2 - *v1;
}

void	__mtx_rstd_suvi(int *v1, int *v2, int *out)
{
	*out = *v2 / *v1;
}

void	__mtx_rstd_divf(float *v1, float *v2, float *out)
{
	*out = *v2 / *v1;
}
