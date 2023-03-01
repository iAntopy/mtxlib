/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtxlib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 00:32:39 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 05:21:59 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTXLIB_H
# define MTXLIB_H

# define MAX_DIMS 2

# include <math.h>
# include <stdlib.h>
# include <limits.h>
# include <time.h>
# include <stdio.h>

# include "libft.h"

//# define SHAPE_STR(r, c) ({(c > 0) ? ("<"#r" x "#c">"):("<"#r" x 1>");})
# define MTX_ERROR(err) mtx_err((char *)__FUNCTION__, (char *)(err))
//# define MTX_ERR_CLR(e, m) mtx_e_clr((char *)__FUNCTION__, (char *)(e), (m))
# define UNUSED(x) (void)(x)

# include "mtx_types.h"
# include "mtx_core.h"
# include "mtx_ufuncs.h"
# include "mtx_trig.h"
# include "mtx_arithmetic.h"	//AUTO_GENERATED
# include "mtx_cumul_ufuncs.h"	//AUTO GENERATED
# include "mtx_linalg.h"
# include "mtx_quaternion.h"

#endif
