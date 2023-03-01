/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_usec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:28:41 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 00:32:18 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/time.h>
#include <stdio.h>

static void	ft_put_delta_t(ssize_t d, char *note)
{
	ssize_t	secs;
	ssize_t	ms;
	ssize_t	us;

	secs = d / 1000000;
	ms = (d % 1000000) / 1000;
	us = (d % 1000);
	printf("%ld sec, %ld ms and %ld usec elapsed : %s\n",
		secs, ms, us, note);
}

ssize_t	ft_timedelta_usec(char *note)
{
	static struct timeval	last_t;
	struct timeval			curr_t;
	ssize_t					delta_t;

	gettimeofday(&curr_t, NULL);
	if (last_t.tv_sec)
	{
		delta_t = (size_t)(curr_t.tv_sec - last_t.tv_sec) * 1000000;
		delta_t += (size_t)(curr_t.tv_usec - last_t.tv_usec);
		if (note)
			ft_put_delta_t(delta_t, note);
	}
	else
		delta_t = 0;
	last_t.tv_sec = curr_t.tv_sec;
	last_t.tv_usec = curr_t.tv_usec;
	return (delta_t);
}
