#include "mtxlib.h"

t_mtx	*mtx_sin(t_mtx *a, t_mtx *out)
{
	return (mtx_apply_f(a, sinf, out));
}

t_mtx	*mtx_cos(t_mtx *a, t_mtx *out)
{
	return (mtx_apply_f(a, cosf, out));
}

t_mtx	*mtx_tan(t_mtx *a, t_mtx *out)
{
	return (mtx_apply_f(a, tanf, out));
}

t_mtx	*mtx_asin(t_mtx *a, t_mtx *out)
{
	return (mtx_apply_f(a, asinf, out));
}

t_mtx	*mtx_aacos(t_mtx *a, t_mtx *out)
{
	return (mtx_apply_f(a, acosf, out));
}
	
/*
static void	__apply_trig_func(float *a, float *b, size_t n_elems, float (*func)(float))
{
	while (n_elems--)
		*(a++) = (float)func(*(b++));
}

static t_mtx	*__apply_trig(t_mtx *mtx, float (*func)(float))
{
	t_mtx	*res;

	if (!mtx || mtx->dtype != DTYPE_F)
		return (fperror("mtx_trig : no input mtx or mtx->dtype != FLOAT"));
	res = mtx_dup_empty(mtx, DTYPE_F);
	if (!res)
		return (fperror("mtx_trig : malloc error"));
	__apply_trig_func(res->arr, mtx->arr, res->shape[0] * res->shape[1], func);
	return (res);
}

t_mtx	*mtx_trig(t_mtx *mtx, float (*func)(float))
{
	return (__apply_trig(mtx, func));
}
*/
