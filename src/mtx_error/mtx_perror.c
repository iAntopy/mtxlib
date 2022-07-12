/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_perror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 20:50:10 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/11 21:50:25 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

void	*mtx_err(char *origin, char *err)
{
	fprintf(stderr, RED_BC"[=> MTX ERROR : %s : %s <=]\n"WHITE_C, origin, err);
	return (NULL);
}

void	*mtx_e_clr(char *origin, char *err, t_mtx **mtx)
{
	mtx_err(origin, err);
	mtx_clear(mtx);
	return (NULL);
}
