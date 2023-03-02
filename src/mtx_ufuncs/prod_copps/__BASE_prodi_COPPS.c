/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_prodi_COPPS.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:12:36 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 23:37:10 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_prodi_init(int *a, int *out)
{
	(void)a;
	*out = 1;
}

void	__mtx_prodi_cumul(int *a, int *out)
{
	*out *= *a;
}

void	__mtx_prodi_post(int *out, int n)
{
	(void)out;
	(void)n;
	return ;
}
