/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 21:22:27 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 02:46:22 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

#define BRKT_C CYAN_BC
#define DATA_C WHITE_BC

static void	mtx_print_single_row_1d(t_mtx *mtx)
{
	int	*marr;
	int	i;

	marr = _mtx_arr(mtx);
	i = -1;
	printf(BRKT_C"[ ");
	if (mtx->dtype == DTYPE_I)
	{
		while (++i < mtx->shape[0] - 1)
			printf(DATA_C"%5d"BRKT_C", ",
				*(int *)_mtx_idx(marr, mtx->strides, i, 0));
		printf(DATA_C"%5d ", *(int *)_mtx_idx(marr, mtx->strides, i, 0));
	}
	else
	{
		while (++i < mtx->shape[0] - 1)
			printf(DATA_C"%6.3f"BRKT_C", ",
				*(float *)_mtx_idx(marr, mtx->strides, i, 0));
		printf(DATA_C"%6.3f ", *(float *)_mtx_idx(marr, mtx->strides, i, 0));
	}
	printf(BRKT_C"]");
}

static void	mtx_print_single_row_2d(t_mtx *mtx, int row)
{
	int	*marr;
	int	i;

	marr = _mtx_arr(mtx);
	i = -1;
	printf("%c[ ", " "[row == 0]);
	if (mtx->dtype == DTYPE_I)
	{
		while (++i < mtx->shape[1] - 1)
			printf(DATA_C"%5d"BRKT_C", ",
				*(int *)_mtx_idx(marr, mtx->strides, row, i));
		printf(DATA_C"%5d ", *(int *)_mtx_idx(marr, mtx->strides, row, i));
	}
	else
	{
		while (++i < mtx->shape[1] - 1)
			printf(DATA_C"%6.3f"BRKT_C", ",
				*(float *)_mtx_idx(marr, mtx->strides, row, i));
		printf(DATA_C"%6.3f ", *(float *)_mtx_idx(marr, mtx->strides, row, i));
	}
	printf(BRKT_C"]");
	if (row == (mtx->shape[0] - 1))
		printf("\n");
}

void	mtx_print(t_mtx *mtx)
{
	int	row;

	if (!mtx)
		return ;
	if (mtx->shape[1] == 1)
		mtx_print_single_row_1d(mtx);
	else
	{
		row = -1;
		printf(BRKT_C"[");
		while (++row < mtx->shape[0])
			mtx_print_single_row_2d(mtx, row);
		printf(BRKT_C"]");
	}
	printf("\n"WHITE_C);
}
