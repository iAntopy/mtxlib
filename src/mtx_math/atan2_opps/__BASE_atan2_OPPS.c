/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   __BASE_atan2_OPPS.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <iamongeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 03:05:11 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/02 08:53:51 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mtxlib.h"

// Function/file names should not be changed. The atan2 paterns will be replaced
// by the name in the OPPERATIONS_GENERATOR.sh script. You should only 
// create a directory with a copy of this file inside, 
// complet with the relevant function descriptions. 
// Opperations can opperate with only 1 opperand as in *out = sqrt(v1). The
// singular opperand should always be v1. Reverse opperation variants should be
// coded even if not arithmeticaly usefull (even for commutative opperations
// such as add/mul).

void	__mtx_std_atan2i(int *v1, int *v2, int *out)
{
	v1 = v2;
	v2 = out;
	out = v1;
	mtx_err((char *)__FUNCTION__, "Unsupported int type for atan2, Use float");
}

void	__mtx_std_atan2f(float *v1, float *v2, float *out)
{
	*out = atan2f(*v1, *v2);
}

void	__mtx_std_ratan2f(float *v1, float *v2, float *out)
{
	*out = atan2f(*v2, *v1);
}

void	__mtx_std_ratan2i(int *v1, int *v2, int *out)
{
	v1 = v2;
	v2 = out;
	out = v1;
	mtx_err((char *)__FUNCTION__, "Unsupported int type for atan2. Use float.");
}
