/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 00:39:03 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/12 01:57:59 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <euler.h>

size_t			digits_nb
	(t_int x, int base)
{
	t_int		a;
	size_t		i;

	if (!x)
		return (1);
	a = 1;
	i = 0;
	while (a <= x)
	{
		a *= base;
		i++;
	}
	return (i);
}

int			digit_n
	(int x, int n)
{
	return (x % (int)pow(10, (n + 1)) / (int)(pow(10, n)));
}
