/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_sumi_COPPS.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:12:36 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 23:37:28 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_sumi_init(int *a, int *out)
{
	(void)a;
	*out = 0;
}

void	__mtx_sumi_cumul(int *a, int *out)
{
	*out += *a;
}

void	__mtx_sumi_post(int *out, int n)
{
	(void)n;
	(void)out;
	return ;
}
