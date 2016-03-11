/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problem2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 12:45:44 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/11 17:40:55 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <euler.h>

int				problem_test
	(void **result, size_t result_size)
{
	NOTEST;
	*result = NULL;
	return (0);
}

int			problem_solve
	(void)
{
	t_intlist	*fiblst;

	fiblst = fib(
		lambda(int, (int n, int fn),
		{
			return (fn < 4000000);
		}
	));
	return (cond_sum(fiblst, &even));
}
