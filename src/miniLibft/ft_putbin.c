/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 01:52:07 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 00:31:02 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// writes n bytes of data following addr ptr in binary
void	ft_putbin(const void *addr, size_t n)
{
	unsigned char	byte;

	while (n--)
	{
		byte = *(unsigned char *)(addr++);
		write(1, &BIN_BASE[!!(0x80 & byte)], 1);
		write(1, &BIN_BASE[!!(0x40 & byte)], 1);
		write(1, &BIN_BASE[!!(0x20 & byte)], 1);
		write(1, &BIN_BASE[!!(0x10 & byte)], 1);
		write(1, &BIN_BASE[!!(0x8 & byte)], 1);
		write(1, &BIN_BASE[!!(0x4 & byte)], 1);
		write(1, &BIN_BASE[!!(0x2 & byte)], 1);
		write(1, &BIN_BASE[!!(0x1 & byte)], 1);
		write(1, " ", 1);
	}
}
