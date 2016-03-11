/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intlist.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 12:20:44 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/11 17:06:04 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <euler.h>

t_intlist			*intlist_new
	(int data)
{
	t_intlist		*ret;

	if (!(ret = malloc(sizeof(*ret))))
		return (NULL);
	bzero(ret, sizeof(*ret));
	ret->data = data;
	return (ret);
}

t_intlist			*intlist_addfront
	(t_intlist **l, int data)
{
	t_intlist		*new;

	if (!(new = intlist_new(data)))
		return (NULL);
	new->next = *l;
	*l = new;
	return (new);
}

t_intlist			*intlist_addback
	(t_intlist **l, int data)
{
	t_intlist		*new;

	if (*l)
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
