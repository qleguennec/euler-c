/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 18:49:48 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/11 21:57:31 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <euler.h>

int					isprime
	(unsigned long x)
{
	unsigned long	i;

	i = 2;
	while (i < x)
	{
		if (!(x % i))
			return (0);
		i++;
	}
	return (1);
}

t_intlist			*prime_factors
	(unsigned long x)
{
	unsigned long	i;
	t_intlist		*l;

	i = 2;
	l = NULL;
	while (i < x)
	{
		if (!(x % i) && isprime(i))
			intlist_addfront(&l, i);
		i++;
	}
	return (l);
}
