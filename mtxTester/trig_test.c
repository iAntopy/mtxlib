/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trig_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 02:23:32 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/04 02:24:42 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

float	sinf(float nb);

int	main()
{
	t_mtx	*m1;
	t_mtx	*m2;

	m1 = mtx_linspace(0, M_PI, 16, 1);
	if (!m1)
		return (1);
	m2 = mtx_sin(m1, NULL);
	if (!m2)
		return (2);
	printf("linspace array : \n");
	mtx_print(m1);
	mtx_display_info(m1);
	printf("sin func over linspace : \n");
	mtx_print(m2);
	mtx_display_info(m2);	
	return (0);
}
