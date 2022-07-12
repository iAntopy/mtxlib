/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_dot_tester.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iamongeo <marvin@42quebec.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:23:50 by iamongeo          #+#    #+#             */
/*   Updated: 2022/07/11 23:22:52 by iamongeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mtxlib.h"

float	arr[4][3] = {{1, 2, 3}, {5, 6, 7}, {9, 8, 7}, {6, 5, 4}};

int	unit_test_failure(char *origin)
{
	printf(RED_BC"\n ¡~^~ UNIT_TEST < "YELLOW_BC"%s"RED_BC" > FAILURE ~^~!\n"WHITE_C, origin);
	return (0);
}

int	unit_test_success(char *origin)
{
	printf(GREEN_BC"\n ¡~~~ UNIT_TEST < "YELLOW_BC"%s"GREEN_BC" > SUCCESS ~~~!\n"WHITE_C, origin);
	return (1);
}

int	test1_a_dot_b_malloc_out(int test_nb, char *title)
{
	t_mtx	*mtx;
	t_mtx	*eye;
	t_mtx	*res;
	
	printf(WHITE_BC"\n\n\n -> TEST %d : %s\n"WHITE_C, test_nb, title);

	mtx = mtx_create_array(arr, 4, 3, DTYPE_F);
	printf("Init A matrix :\n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	eye = mtx_identity(3, NULL, DTYPE_F);
	printf("Init B matrix :\n");
	mtx_print(eye);
	mtx_display_info(eye);

	res = mtx_dot(mtx, eye, NULL);
	if (!res)
		return (unit_test_failure(title));
	else
		printf("Resulting output array\n");
	mtx_print(res);
	mtx_display_info(res);

	mtx_clear_list(3, mtx, eye, res);
	return (unit_test_success(title));
}

int	test2_a_dot_b_initialized_out(int test_nb, char *title)
{
	t_mtx	*mtx;
	t_mtx	*eye;
	t_mtx	*res;
	
	printf(WHITE_BC"\n\n\n -> TEST %d : %s\n"WHITE_C, test_nb, title);

	mtx = mtx_create_array(arr, 4, 3, DTYPE_F);
	printf("Init A matrix :\n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	eye = mtx_identity(3, NULL, DTYPE_F);
	printf("Init B matrix :\n");
	mtx_print(eye);
	mtx_display_info(eye);

	res = mtx_create_empty(4, 3, DTYPE_F);
	
	if (!mtx_dot(mtx, eye, res))
		return (unit_test_failure(title));
	else
		printf("Resulting output array\n");
	mtx_print(res);
	mtx_display_info(res);
	mtx_clear_list(3, mtx, eye, res);
	return (unit_test_success(title));
}

int	test3_a_dot_b_init_mismatch_shape_out(int test_nb, char *title)
{
	t_mtx	*mtx;
	t_mtx	*eye;
	t_mtx	*res;
	
	printf(WHITE_BC"\n\n\n -> TEST %d : %s\n"WHITE_C, test_nb, title);

	mtx = mtx_create_array(arr, 4, 3, DTYPE_F);
	printf("Init A matrix :\n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	eye = mtx_identity(3, NULL, DTYPE_F);
	printf("Init B matrix :\n");
	mtx_print(eye);
	mtx_display_info(eye);

	res = mtx_create_empty(3, 4, DTYPE_F);

	if (!mtx_dot(mtx, eye, res))
		return (unit_test_success(title));
	
	mtx_clear_list(3, mtx, eye, res);
	printf("TEST SHOULD HAVE FAILED BUT DIDN'T\n");
	return (unit_test_failure(title));
}

int	test4_mismatch_input_mtx_malloc_out(int test_nb, char *title)
{
	t_mtx	*mtx;
	t_mtx	*eye;
	t_mtx	*res;
	
	printf(WHITE_BC"\n\n\n -> TEST %d : %s\n"WHITE_C, test_nb, title);

	mtx = mtx_create_array(arr, 4, 3, DTYPE_F);
	printf("Init A matrix :\n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	eye = mtx_identity(4, NULL, DTYPE_F);
	printf("Init B matrix :\n");
	mtx_print(eye);
	mtx_display_info(eye);

	res = mtx_dot(mtx, eye, NULL);
	if (!res)
		return (unit_test_success(title));

	mtx_clear_list(3, mtx, eye, res);
	printf("TEST SHOULD HAVE FAILED BUT DIDN'T\n");
	return (unit_test_failure(title));
}

int	test5_array_a_dot_array_b_output_to_view(int test_nb, char *title)
{
	t_mtx	*mtx;
	t_mtx	*eye;
	t_mtx	*res;
	t_mtx	*view;
	const int	slice[4] = {4, 4, 8, 7};
	
	printf(WHITE_BC"\n\n\n -> TEST %d : %s\n"WHITE_C, test_nb, title);

	mtx = mtx_create_array(arr, 4, 3, DTYPE_F);
	printf("Init A matrix :\n");
	mtx_print(mtx);
	mtx_display_info(mtx);

	eye = mtx_identity(3, NULL, DTYPE_F);
	printf("Init B matrix :\n");
	mtx_print(eye);
	mtx_display_info(eye);

	res = mtx_create_zeros(10, 10, DTYPE_F);
	if (!res)
		return (unit_test_failure(title));
	printf("Zeros filled 10x10 mtx\n");
	printf("res array ptr : %p\n", res->arr);
	mtx_print(res);
	mtx_display_info(res);

	view = mtx_slice_view(res, slice);
	if (!view)
		return (unit_test_failure(title));
	mtx_print(view);
	mtx_display_info(view);

	if (!mtx_dot(mtx, eye, view))
		return (unit_test_failure(title));

	printf("Resulting view output :\n");
	mtx_print(view);

	printf("Resulting 10x10 mtx :\n");
	mtx_clear_list(4, mtx, eye, res, view);
	return (unit_test_success(title));
}


int main()
{
	t_mtx	*mtx;
	t_mtx	*eye;
	t_mtx	*res;
	int		slice[4] = {0,0,3,3};

	t_mtx	*mtx_view;
	t_mtx	*eye_view;

	printf(YELLOW_BC"\n\n[[ @@@@@@ --- GENERIC DOT PRODUCT TEST SUITE --- @@@@@@ ]]\n"WHITE_C);

	test1_a_dot_b_malloc_out(1, "array a dot array b -> malloced out");
	test2_a_dot_b_initialized_out(2, "array a dot array b -> initialized out");
	test3_a_dot_b_init_mismatch_shape_out(3, "array a dot array b -> mismatched initialized out");
	test4_mismatch_input_mtx_malloc_out(4, "mismatch input mtx -> malloced out");
	test5_array_a_dot_array_b_output_to_view(5, "array a dot array b -> output to view");

/*
	printf(WHITE_BC"\n --- inplace test --- \n"WHITE_C);
	mtx = mtx_create_array(arr, 4, 3, DTYPE_F);
	mtx_print(mtx);
	mtx_display_info(mtx);
	
	eye = mtx_identity(3, NULL, DTYPE_F);
	printf("\nResulting eye mtx\n");
	mtx_print(eye);
	mtx_display_info(eye);

	res = mtx_dot(mtx, eye, NULL);

	mtx_print(res);
	mtx_display_info(res);
	
	*(float *)mtx_index(eye, 2, 2) = 10;

	printf("dot inplace result\n");
	mtx_dot(res, eye, res);
	mtx_print(res);
	mtx_display_info(res);

	printf(WHITE_BC"\n --- inplace through view test --- \n"WHITE_C);

	mtx_clear(&mtx);
	mtx_clear(&eye);
	mtx_clear(&res);
*/
	return (0);
}
