/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problem3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:16:41 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/11 20:39:36 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <euler.h>

int				problem_test
	(void **result, int *type)
{
	t_intlist	*l_cmp;
	t_intlist	*l_primes;
	int			arr[] = {29, 13, 7, 5};

	*type = 1;
	l_cmp = from_array(arr, SIZE(arr));
	l_primes = prime_factors(13195);
	if (!l_primes)
		return (0);
	*result = malloc(sizeof(t_intlist));
	memcpy(*result, l_primes, sizeof(*l_primes));
	return (intlist_eq(l_cmp, l_primes));
}

int				problem_solve
	(void)
{
	return (1);
}
