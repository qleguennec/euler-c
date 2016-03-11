/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 12:20:44 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/11 19:27:28 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <euler.h>

t_intlist			*intlist_new
	(int data)
{
	t_intlist		*ret;

	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	ret->next = NULL;
	ret->data = data;
	return (ret);
}

t_intlist			*intlist_addfront
	(t_intlist **l, int data)
{
	t_intlist		*new;

	if (!(new = intlist_new(data)))
		return (NULL);
	if (!*l)
	{
		*l = new;
		return (new);
	}
	new->next = *l;
	*l = new;
	return (new);
}

t_intlist			*intlist_addback
	(t_intlist **l, int data)
{
	t_intlist		*new;

	if (!*l)
	{
		*l = intlist_new(data);
		if (!*l)
			return (NULL);
	}
	if ((*l)->next)
		return (intlist_addback(&(*l)->next, data));
	if (!(new = intlist_new(data)))
		return (NULL);
	(*l)->next = new;
	return (new);
}

int					cond_sum
	(t_intlist *l, int (*f) (int))
{
	int				result;
	t_intlist		*l1;

	result = 0;
	l1 = l;
	while (l1)
	{
		if (f(l1->data))
			result += l1->data;
		l1 = l1->next;
	}
	return (result);
}

int					sum
	(t_intlist *l)
{
	return (cond_sum(l, &true));
}

t_intlist			*from_array
	(int arr[], size_t arr_size)
{
	size_t			i;
	t_intlist		*l;

	i = 1;
	l = NULL;
	if (arr_size > 0)
		l = intlist_new(arr[0]);
	while (i < arr_size)
		intlist_addback(&l, arr[i++]);
	return (l);
}

int					intlist_eq
	(t_intlist *la, t_intlist *lb)
{
	if (!la && !lb)
		return (1);
	if (!la || !lb)
		return (0);
	if (la->data != lb->data)
		return (0);
	return (intlist_eq(la->next, lb->next));
}

void				intlist_print
	(t_intlist *l)
{
	write(0, "[", 1);
	while (l)
	{
		printf("%d", l->data);
		fflush(0);
		if (l->next)
			write(0, ", ", 2);
		l = l->next;
	}
	write(0, "]\n", 2);
}
