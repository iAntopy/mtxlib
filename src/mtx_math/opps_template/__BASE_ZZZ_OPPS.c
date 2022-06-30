/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FFF                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:05:11 by iamongeo          #+#    #+#             */
/*   Updated: 2022/06/23 21:57:27 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// Function/file names should not be changed. The ZZZ paterns will be replaced
// by the name in the OPPERATIONS_GENERATOR.sh script. You should only 
// create a directory with a copy of this file inside, complet with the relevant 
// function descriptions. 
// Opperations can opperate with only 1 opperand as in *out = sqrt(v1). The
// singular opperand should always be v1. Reverse opperation variants should be
// coded even if not arithmeticaly usefull (even for commutative opperations
// such as add/mul).

void	__mtx_std_ZZZi(int *v1, int *v2, int *out)
{
	//WRITE INDIVIDUAL OPPERATION CODE HERE : DTYPE_I
}

void	__mtx_std_ZZZf(float *v1, float *v2, float *out)
{
	//WRITE INDIVIDUAL OPPERATION CODE HERE : DTYPE_F
}

void	__mtx_std_rZZZf(float *v1, float *v2, float *out)
{
	//WRITE INDIVIDUAL OPPERATION CODE HERE : DTYPE_F, REVERSE (eg.: 5 - mtx vs regular mtx - 5)
}

void	__mtx_std_rZZZi(int *v1, int *v2, int *out)
{
	//WRITE INDIVIDUAL OPPERATION CODE HERE : DTYPE_I, REVERSE
}
