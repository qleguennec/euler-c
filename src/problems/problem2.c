/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problem2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 12:45:44 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/11 22:17:41 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <euler.h>

int				problem_test
	(void **result, int *type)
{
	NOTEST;
	*result = NULL;
	return (0);
}

int			problem_solve
	(void **result, int *type)
{
	t_intlist	*fiblst;
	int			x;

	*type = 0;
	fiblst = fib(
		lambda(int, (int n, int fn),
		{
			return (fn < 4000000);
		}
	));
	x = cond_sum(fiblst, &even);
	*result = malloc(sizeof(int));
	if (!*result)
		return (0);
	memcpy(*result, &x, sizeof(x));
	return (1);
}
