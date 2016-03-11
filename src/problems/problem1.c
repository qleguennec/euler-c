/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problem1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 23:16:24 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/11 22:17:30 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <euler.h>

int			multiple_3_or_5
	(int x)
{
	return (!(x % 3) || !(x % 5));
}

int			problem_test
	(void **result, int *type)
{
	int		test_return;

	*type = 0;
	if (!(*result))
		*result = malloc(sizeof(int));
	test_return = sum_between(&multiple_3_or_5, 3, 9);
	memcpy(*result, &test_return, sizeof(int));
	return (test_return == 23);
}

int			problem_solve
	(void **result, int *type)
{
	int		x;

	*type = 0;
	*result = malloc(sizeof(int));
	if (!*result)
		return (0);
	x = sum_between(&multiple_3_or_5, 3, 999);
	memcpy(*result, &x, sizeof(x));
	return (1);
}
