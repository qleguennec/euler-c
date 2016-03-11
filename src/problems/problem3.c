/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problem3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:16:41 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/11 22:47:37 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <euler.h>

unsigned long		largest_prime_factor(unsigned long x)
{
	unsigned long	i;

	i = ceil(sqrt(x));
	while (42)
	{
		if (!(x % i) && isprime(i))
			return (i);
		i--;
	}
}

int					problem_test
	(void **result, int *type)
{
	t_intlist		*l_cmp;
	t_intlist		*l_primes;
	int				arr[] = {29, 13, 7, 5};

	*type = 1;
	l_cmp = from_array(arr, SIZE(arr));
	l_primes = prime_factors(13195);
	if (!l_primes)
		return (0);
	*result = malloc(sizeof(t_intlist));
	memcpy(*result, l_primes, sizeof(*l_primes));
	return (intlist_eq(l_cmp, l_primes));
}

int					problem_solve
	(void **result, int *type)
{
	unsigned long	x;

	*type = 2;
	x = 600851475143;
	x = largest_prime_factor(x);
	*result = malloc(sizeof(unsigned long));
	if (!*result)
		return (0);
	memcpy(*result, &x, sizeof(x));
	return (1);
}
