
#include "mtxlib.h"

int	mtx_isvalid_broadcast_dot(t_mtx *m1, t_mtx *m2)
{
	int	shapes_match;
	int	dtype_match;

	shapes_match = m1->shape[m1->ndims - 1] == m2->shape[0];
	dtype_match = (m1->dtype == m2->dtype);
	if (dtype_match && shapes_match)
		return (1);
	else if (!shapes_match)
		fperror("broadcast error : shapes mismatch : (%d vs %d)", SHAPE_STR(m1->shape[0], m1->shape[1]), SHAPE_STR(m2->shape[0], m2->shape[1]));
	else if (!shapes_match)
		fperror("broadcast error : dtype error : (%s vs %s)", (m1->dtype == DTYPE_I)?"INT":"FLOAT", (m2->dtype == DTYPE_I)?"INT":"FLOAT");
	return (0);
}
