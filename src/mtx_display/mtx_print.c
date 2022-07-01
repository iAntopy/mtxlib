/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:22:27 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/30 21:26:42 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

#define BRKT_C CYAN_BC
#define DATA_C WHITE_BC

void	mtx_print_i(t_mtx *mtx)
{
//	int		*marr;
	int		i;
	int		j;

//	marr = mtx->arr;
	if (!mtx || !(mtx->arr) || mtx->dtype != DTYPE_I)
		return ;
	i = -1;
	if (mtx->ndims == 1)
	{
		printf(BRKT_C"[ ");
		while (++i < mtx->shape[0] - 1)
			printf(DATA_C"%5d"BRKT_C", ", *(int *)_mtx_idx(mtx->arr, mtx->strides, i, 0));
//			printf("%5d, ", marr[i]);
		printf(DATA_C"%5d "BRKT_C"]\n"WHITE_C, *(int *)_mtx_idx(mtx->arr, mtx->strides, i, 0));
	}
	else if (mtx->ndims == 2)
	{
		printf(BRKT_C"[");
		while (++i < mtx->shape[0])
		{
			j = -1;
			printf("%c[", " "[!i]);
			while (++j < mtx->shape[1] - 1)
				printf(DATA_C"%5d"BRKT_C", ", *(int *)_mtx_idx(mtx->arr, mtx->strides, i, j));
			printf(DATA_C"%5d"BRKT_C"]%c", *(int *)_mtx_idx(mtx->arr, mtx->strides, i, j), "\n"[i == (mtx->shape[0] - 1)]);
		}
		printf("]\n"WHITE_C);
	}
}

void	mtx_print_f(t_mtx *mtx)
{
//	float	*marr;
	int		i;
	int		j;

//	marr = mtx->arr;
	if (!mtx || !(mtx->arr) || mtx->dtype != DTYPE_F)
		return ;
	i = -1;
	if (mtx->ndims == 1)
	{
		printf(BRKT_C"[ ");
		while (++i < mtx->shape[0] - 1)
			printf(DATA_C"%6.3f"BRKT_C", ", *(float *)_mtx_idx(mtx->arr, mtx->strides, i, 0));

	//	printf("mtx_print_f : while over\n");
		printf(DATA_C"%6.3f "BRKT_C"]\n"WHITE_C, *(float *)_mtx_idx(mtx->arr, mtx->strides, i, 0));
	}
	else if (mtx->ndims == 2)
	{
		printf(BRKT_C"[");
		while (++i < mtx->shape[0])
		{
			j = -1;
			printf("%c[ ", " "[!i]);
			while (++j < mtx->shape[1] - 1)
				printf(DATA_C"%6.3f"BRKT_C", ", *(float *)_mtx_idx(mtx->arr, mtx->strides, i, j));
			printf(DATA_C"%6.3f "BRKT_C"]%c", *(float *)_mtx_idx(mtx->arr, mtx->strides, i, j),
				"\n"[i == (mtx->shape[0] - 1)]);
		}
		printf("]\n"WHITE_C);
	}
}

void	mtx_print(t_mtx *mtx)
{
	if (!mtx)
		return ;
	if (mtx->dtype == DTYPE_F)
		mtx_print_f(mtx);
	else if (mtx->dtype == DTYPE_I)
		mtx_print_i(mtx);
}
