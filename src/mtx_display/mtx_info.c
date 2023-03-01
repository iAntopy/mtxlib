/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 19:07:37 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 03:13:27 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtxlib.h"

#define TITLE_C YELLOW_BC
#define FRAME_C BLUE_BC
#define SUB_C CYAN_BC
#define DATA_C WHITE_BC
#define FRMT_C PURPLE_BC

static char	*int_float_str(t_mtx *mtx)
{
	if (mtx->dtype == DTYPE_I)
		return ("INT");
	else
		return ("FLOAT");
}

static char	*true_false_str(int test)
{
	if (test)
		return ("TRUE");
	else
		return ("FALSE");
}

void	mtx_display_info(t_mtx *mtx)
{
	if (!mtx)
		return ;
	printf(FRAME_C"@@_______[ "TITLE_C"Matrix info (%p)"FRAME_C" ]_______@@\n\
[[%-46s]]\n", mtx, " ");
	printf(FRAME_C"[["SUB_C"\t%-14s : "DATA_C"%-23d%s\n", "ndims",
		mtx->ndims, FRAME_C"]]"FRAME_C);
	printf(FRAME_C"[["SUB_C"\t%-14s : "DATA_C"%-23s%s\n", "dtype",
		int_float_str(mtx), FRAME_C"]]"FRAME_C);
	printf(FRAME_C"[["SUB_C"\t%-14s : "\
FRMT_C"<"DATA_C"%3d"FRMT_C" x "DATA_C"%-3d"FRMT_C">%28s\n",
		"shape <n x m>", mtx->shape[0], mtx->shape[1], FRAME_C"]]"FRAME_C);
	printf(FRAME_C"[["SUB_C"\t%-14s : "\
FRMT_C"("DATA_C"%3d"FRMT_C", "DATA_C"%-3d"FRMT_C" )%28s\n",
		"strides (r, c)", mtx->strides[0], mtx->strides[1], FRAME_C"]]"FRAME_C);
	printf(FRAME_C"[["SUB_C"\t%-14s : "DATA_C"%-23p%s\n", "array at",
		_mtx_arr(mtx), FRAME_C"]]"FRAME_C);
	printf(FRAME_C"[["SUB_C"\t%-14s : "DATA_C"%-23p%s\n", "swap at",
		mtx->swap, FRAME_C"]]"FRAME_C);
	printf(FRAME_C"[["SUB_C"\t%-14s : "DATA_C"%-23s%s\n", "is transposed",
		true_false_str(mtx_istransposed(mtx)), FRAME_C"]]"FRAME_C);
	printf(FRAME_C"[["SUB_C"\t%-14s : "DATA_C"%-23s%s\n",
		"is view", true_false_str(mtx->is_view), FRAME_C"]]"FRAME_C);
	printf(FRAME_C"[["SUB_C"\t%-14s : "DATA_C"%-23zu%s\n",
		"offset", mtx->offset, FRAME_C"]]"FRAME_C);
	printf(FRAME_C"@@______________________________________________@@\n"WHITE_C);
}
