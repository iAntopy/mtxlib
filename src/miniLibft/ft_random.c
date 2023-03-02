/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 16:05:47 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/02 00:26:11 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtx_libft.h"
#include <time.h>

//Generates random uniformaly distributed float nb between [0, 1].
float	ft_random(void)
{
	static int	seed_is_set;

	if (!seed_is_set)
	{
		srand(time(NULL));
		seed_is_set = 1;
	}
	return ((double)rand() / (double)RAND_MAX);
}

int	ft_randint(int min, int range)
{
	static int	seed_is_set;

	if (!seed_is_set)
	{
		srand(time(NULL));
		seed_is_set = 1;
	}
	return (rand() % range + min);
}
