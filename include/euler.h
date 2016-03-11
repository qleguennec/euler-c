/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   euler.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qle-guen <qle-guen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 23:13:18 by qle-guen          #+#    #+#             */
/*   Updated: 2016/03/11 19:37:45 by qle-guen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EULER_H
# define EULER_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

static char				msg_ok[]		= "\033[0;32mOK\033[0m\n";
static char				msg_nok[]		= "\033[0;31mNOK\033[0m\n";
static char				msg_notest[]	= "no test enabled for this problem\n";

#define OK				write(0, msg_ok, sizeof(msg_ok));
#define NOK				write(0, msg_nok, sizeof(msg_nok));
#define NOTEST			write(0, msg_notest, sizeof(msg_notest));

#define SIZE(x)				sizeof(x)/sizeof(x[0])
#define lambda(l_ret_type, l_arguments, l_body)										\
({														\
	l_ret_type l_anonymous_functions_name l_arguments	\
	l_body												\
  	&l_anonymous_functions_name;						\
})

typedef struct			s_intlist
{
	int					data;
	struct s_intlist	*next;
}						t_intlist;

int						problem_test(void **result, int *result_type);
int						problem_solve(void);

// intlist.c
t_intlist				*intlist_new(int data);
t_intlist				*intlist_addback(t_intlist **l, int data);
t_intlist				*intlist_addfront(t_intlist **l, int data);
t_intlist				*from_array(int arr[], size_t arr_size);
int						intlist_eq(t_intlist *la, t_intlist *lb);
void					intlist_print(t_intlist *l);
int						sum(t_intlist *l);
int						cond_sum(t_intlist *l, int (*f) (int));

// common.c
int						sum_between(int (*f) (int), int a, int b);
int						even(int x);
int						true(int x);
t_intlist				*seq_fib(int (*f) (int, int), int f1, int f2, int n);
t_intlist				*fib(int (*f) (int, int));

// factors.c
int					isprime(int x);
t_intlist			*prime_factors(int x);

#endif
