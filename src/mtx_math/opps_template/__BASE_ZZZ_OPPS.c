/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_ZZZ_OPPS.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:05:11 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 04:31:47 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// Function/file names should not be changed. The zzz paterns will be replaced
// by the name in the OPPERATIONS_GENERATOR.sh script. You should only 
// create a directory with a copy of this file inside,
// complet with the relevant function descriptions. 
// Opperations can opperate with only 1 opperand as in *out = sqrt(v1). The
// singular opperand should always be v1. Reverse opperation variants should be
// coded even if not arithmeticaly usefull (even for commutative opperations
// such as add/mul).

//WRITE INDIVIDUAL OPPERATION CODE INSIDE : DTYPE_I
void	__mtx_std_zzzi(int *v1, int *v2, int *out)
{
}

//WRITE INDIVIDUAL OPPERATION CODE INSIDE : DTYPE_F
void	__mtx_std_zzzf(float *v1, float *v2, float *out)
{
}

//WRITE INDIVIDUAL OPPERATION CODE INSIDE : DTYPE_F,
//REVERSE (eg.: 5 - mtx vs regular mtx - 5)
void	__mtx_std_rzzzf(float *v1, float *v2, float *out)
{
}

//WRITE INDIVIDUAL OPPERATION CODE INSIDE : DTYPE_I, REVERSE
void	__mtx_std_rzzzi(int *v1, int *v2, int *out)
{
}
