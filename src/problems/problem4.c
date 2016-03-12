/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   problem4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 00:27:33 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/12 03:23:57 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <euler.h>

int				prev_palindrome
	(int n)
{
	size_t		dig_nb;
	int			dig_n;
	int			dig;

	dig_nb = digits_nb(n, 10);
	if (n % (int)pow(10, dig_nb - 1) == 1)
		return (n - 2);
	dig = dig_nb / 2;
	if (!(dig_nb % 2))
		dig--;
	while (dig >= 0)
	{
		dig_n = digit_n(n, dig);
		if (!dig_n)
		{
			n += 9 * pow(10, dig);
			if (!((dig_nb % 2) && (size_t)dig == dig_nb / 2))
				n += 9 * pow(10, dig_nb - dig - 1);
		}
		else if (dig_n - 1 >= 0)
		{
			n -= pow(10, dig);
			if (!((dig_nb % 2) && (size_t)dig == dig_nb / 2))
				n -= pow(10, dig_nb - dig - 1);
			return (n);
		}
		dig--;
	}
	return (0);
}

int				problem_test
	(void **result, int *type)
{
	int			x;

	*type = 0;
	*result = malloc(sizeof(int));
	x = 897798;
	while ((x = prev_palindrome(x)))
		printf("%d\n", x);
	memcpy(*result, &x, sizeof(x));
	return (0);
}

int				problem_solve
	(void **result, int *type)
{
	return (42);
}
