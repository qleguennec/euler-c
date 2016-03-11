/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problem1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 23:16:24 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/11 17:34:58 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <euler.h>

int			multiple_3_or_5
	(int x)
{
	return (!(x % 3) || !(x % 5));
}

int			problem_test
	(void **result, size_t result_size)
{
	int		test_return;

	if (!(*result))
		*result = malloc(result_size);
	test_return = sum_between(&multiple_3_or_5, 3, 9);
	memcpy(*result, &test_return, result_size);
	return (test_return == 23);
}

int			problem_solve
	(void)
{
	return (sum_between(&multiple_3_or_5, 3, 999));
}
