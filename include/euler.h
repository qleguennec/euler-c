/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euler.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 23:13:18 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/11 22:38:58 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EULER_H
# define EULER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <math.h>

typedef unsigned long	t_int;

static char				msg_ok[]		= "\033[0;32mOK\033[0m\n";
static char				msg_nok[]		= "\033[0;31mNOK\033[0m\n";
static char				msg_notest[]	= "no test enabled for this problem\n";

#define OK				write(0, msg_ok, sizeof(msg_ok));
#define NOK				write(0, msg_nok, sizeof(msg_nok));
#define NOTEST			write(0, msg_notest, sizeof(msg_notest));

#define SIZE(x)			sizeof(x)/sizeof(x[0])
#define lambda(l_ret_type, l_arguments, l_body)										\
({																			\
						l_ret_type l_anonymous_functions_name l_arguments	\
						l_body												\
					  	&l_anonymous_functions_name;						\
})

typedef struct			s_intlist
{
	t_int				data;
	struct s_intlist	*next;
}						t_intlist;

int						problem_test(void **result, int *result_type);
int						problem_solve(void **result, int *result_type);

// intlist.c
t_intlist				*intlist_new(t_int data);
t_intlist				*intlist_addback(t_intlist **l, t_int data);
t_intlist				*intlist_addfront(t_intlist **l, t_int data);
t_intlist				*from_array(int arr[], size_t arr_size);
int						intlist_eq(t_intlist *la, t_intlist *lb);
void					intlist_print(t_intlist *l);
t_int					sum(t_intlist *l);
t_int					cond_sum(t_intlist *l, int (*f) (t_int));

// common.c
int						sum_between(int (*f) (int), int a, int b);
int						even(t_int x);
int						true(t_int x);
t_intlist				*seq_fib(int (*f) (int, int), int f1, int f2, int n);
t_intlist				*fib(int (*f) (int, int));

// factors.c
int						isprime(t_int x);
t_intlist				*prime_factors(t_int x);

#endif
