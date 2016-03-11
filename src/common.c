/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 23:32:00 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/11 22:04:02 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <euler.h>

int				sum_between
	(int (*f) (int), int a, int b)
{
	int			result;

	result = 0;
	while (a <= b)
	{
		if (f(a))
			result += a;
		a++;
	}
	return (result);
}

int				even
	(t_int x)
{
	return (!(x % 2));
}

int				true
	(t_int x)
{
	return (1);
}

t_intlist		*seq_fib
	(int (*f) (int, int), int f1, int f2, int n)
{
	t_intlist	*ret;

	ret = intlist_new(f1 + f2);
	if (!ret || !(f(n, ret->data)))
		return (NULL);
	ret->next = seq_fib(f, f2, ret->data, n + 1);
	return (ret);
}

t_intlist		*fib
	(int (*f) (int, int))
{
	return (seq_fib(f, 0, 1, 2));
}
