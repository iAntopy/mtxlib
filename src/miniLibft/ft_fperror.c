/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fperror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:30:32 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/02 08:23:39 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdio.h>
#include "mtx_ft_printf.h"

void	*mtx_fperror(char *fmt, ...)
{
	va_list	ap;

	va_start(ap, fmt);
	ft_vprintf(fmt, &ap);
	perror(" ");
	va_end(ap);
	return (NULL);
}
