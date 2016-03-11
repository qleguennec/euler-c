/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:07:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/11 17:36:27 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <euler.h>

void			exit_msg
	(int ret, char *msg)
{
	write(0, msg, strlen(msg));
	exit(ret);
}

int				main
	(int argc, char **argv)
{
	int		*result;

	if (argc != 2)
		exit_msg(1, "usage: euler {test, solve, info}");
	result = malloc(sizeof(*result));
	if (!(strcmp(argv[1], "test")))
	{
		if (problem_test((void **)&result, sizeof(*result)))
		{
			OK;
			return (0);
		}
		else
		{
			if (!result)
				return (2);
			NOK;
			printf("got result: %d\n", *result);
			return (2);
		}
	}
	else if (!(strcmp(argv[1], "solve")))
	{
		*result = problem_solve();
		printf("%d\n", *result);
	}
	else
		exit_msg(1, "unknown command");
	return (0);
}
