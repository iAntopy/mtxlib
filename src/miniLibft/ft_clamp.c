/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clamp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:27:18 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/02 00:25:14 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

int	ft_clamp(int n, int min, int max)
{
	if (n < min)
		return (min);
	else if (n > max)
		return (max);
	return (n);
}
