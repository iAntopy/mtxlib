/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_hypoti_COPPS.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 17:33:43 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 23:35:31 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	__mtx_hypoti_init(int *a, int *out)
{
	(void)a;
	*out = 0;
}

void	__mtx_hypoti_cumul(int *a, int *out)
{
	*out += (*a) * (*a);
}

// Possibly illigal int to float to int convertion.
void	__mtx_hypoti_post(int *out, int n)
{
	float	temp;

	(void)n;
	temp = 1;
	temp *= *out;
	*out = 1;
	*out *= sqrtf(temp);
}
