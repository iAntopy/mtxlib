/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_ufuncs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 18:22:40 by iamongeo          #+#    #+#             */
/*   Updated: 2023/03/01 04:51:11 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MTX_UFUNCS_H
# define MTX_UFUNCS_H

# include "mtx_types.h"

t_mtx	*mtx_apply_f(t_mtx *mtx, float (*func)(float), t_mtx *out);
t_mtx	*mtx_apply_i(t_mtx *mtx, int (*func)(int), t_mtx *out);

void	__mtx_isqrtf(float *arr, size_t n_elem);// Unusable with views
void	__mtx_sqrtf(float *arr, float *out, size_t n_elem);// idem
t_mtx	*mtx_sqrtf(t_mtx *mtx, t_mtx *out);

t_mtx	*mtx_normalize(t_mtx *mtx, t_mtx *out);
t_mtx	*mtx_inormalize(t_mtx *mtx);
void	_mtx_norm_apply(t_mtx *mtx, t_mtx *out, float len);

#endif
