#include "mtxlib.h"

t_mtx	*mtx_dup_struct(t_mtx *mtx)
{
	t_mtx	*new;

	if (!mtx)
		return (fperror("mtx_dup_struct : no input mtx "));
	if (!malloc_free_p(sizeof(t_mtx), (void **)&new))
		return (fperror("mtx_dup_struct: malloc error "));
	ft_memcpy(new, mtx, sizeof(t_mtx));
	new->arr = NULL;
	new->out = NULL;
	new->is_view = mtx->is_view;
	return (new);
}

t_mtx	*mtx_dup_empty(t_mtx *mtx, int dtype)
{
	t_mtx	*new;
	size_t	arr_size;

	if (!mtx || (dtype && get_dsize(mtx->dtype) != get_dsize(dtype)))
		return (fperror("mtx_dup_empty : no mtx or dsize mismatch"));
	new = mtx_dup_struct(mtx);
	arr_size = mtx_sizeof_array(mtx);
	if (!new)
		return (NULL);
	if (!malloc_free_p(arr_size, (void **)&(new->arr)))
	{
		mtx_clear(&new);
		return (fperror("mtx_dup_empty : malloc error "));
	}
	mtx->dtype = dtype;
	return (new);
}

t_mtx	*mtx_copy(t_mtx *mtx, int dtype)
{
	t_mtx	*new;
	size_t	arr_size;

	if (!mtx || (dtype && get_dsize(mtx->dtype) != get_dsize(dtype)))
		return (fperror("mtx_dup_empty : no mtx or dsize mismatch"));
	new = mtx_dup_struct(mtx);
	arr_size = mtx_sizeof_array(mtx);
	if (!new)
		return (NULL);
	if (!malloc_free_p(arr_size, (void **)&(new->arr)))
	{
		mtx_clear(&new);
		return (fperror("mtx_dup_empty : malloc error "));
	}
	new->dtype = dtype + (!dtype * mtx->dtype);
	if (dtype == mtx->dtype)
		ft_memcpy(new->arr, mtx->arr, arr_size);
	else
		mtx_convert_arr_type(new, mtx);
	return (new);

}
