/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:07:17 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/12 00:31:11 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <euler.h>

void			exit_msg
	(int ret, char *msg)
{
	write(0, msg, strlen(msg));
	exit(ret);
}

void			print_result
	(void *result, int result_type)
{
	switch (result_type)
	{
		case 0:
			printf("%d\n", *((int*)result));
			break;
		case 1:
			intlist_print(result);
			break;
		case 2:
			printf("%lu\n", *((t_int*)result));
			break;
		default:
			exit_msg(42, "type error");
	}
}

int				main
	(int argc, char **argv)
{
	void	*result;
	int		result_type;
	int		ret;

	result = NULL;
	if (argc != 2)
		exit_msg(1, "usage: euler {test, solve, info}");
	if (!(strcmp(argv[1], "test")))
	{
		if (problem_test(&result, &result_type))
		{
			OK;
			return (0);
		}
		else
		{
			NOK;
			if (!result)
				exit_msg(2, "got NULL result\n");
			write(0, "got result: ", 12);
			print_result(result, result_type);
			return (2);
		}
	}
	else if (!(strcmp(argv[1], "solve")))
	{
		ret = problem_solve(&result, &result_type);
		if (ret != 1)
		{
			printf("solver returned: %d, exiting", ret);
			return (ret);
		}
		print_result(result, result_type);
	}
	else
		exit_msg(1, "unknown command");
	return (0);
}
