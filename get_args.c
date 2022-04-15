/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <ndionis@student.42mulhouse.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/04/09 21:01:10 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_msg(char *msg)
{
	size_t  msg_len;

	if (!msg)
	write(1, "Error\n", 6);
	else
	{
	msg_len = 0;
	while (msg[msg_len])
	msg_len++;
		write(1, msg, msg_len);
	}
	exit (0);
}

int	ft_atoi(char *str_nb)
{
	int	nb;
	int sign;
	int	loop_nb;

	sign = 1;
	nb = 0;
	loop_nb = 0;
	if (*str_nb == '-')
	{
		sign = -1;
		str_nb++;
	}
	while (*str_nb == '0')
		str_nb++;
	while (*str_nb && (*str_nb >= '0' && *str_nb <= '9') && loop_nb++ < 10)
		nb = (*str_nb++ - 48) + 10 * nb;
	if (nb != -2147483648) // already overflowed
		nb *= sign;
	if ((loop_nb > 9 && nb * sign < 0 && nb != -2147483648) || *str_nb != 0)
		error_msg(NULL);
	return (nb);
}

t_lst	*get_args(int argc, char *argv[])
{
	t_lst	*lst_a;
	t_lnk	*lnk;
	
	lst_a = new_lst();
	if (argc < 2)
		error_msg(NULL);
	argc--;
		argv = &argv[1];
	while (argc--)
	{
	 	lnk = new_lnk(ft_atoi(argv[argc]), argc, 0);
	 	lnk->ind = argc;
	 	push_item(lnk, lst_a);
	}
	lst_init_rank(lst_a);
	return (lst_a);
}


/*
#include <stdio.h>
int main()
{
	printf("%d\n", ft_atoi("0"));
	printf("%d\n", ft_atoi("-0"));
	printf("%d\n", ft_atoi("2147483646"));
	printf("%d\n", ft_atoi("2147483647"));
	printf("%d\n", ft_atoi("-2147483647"));
	printf("%d\n", ft_atoi("-2147483648"));
	printf("%d\n", ft_atoi("214748364s6"));
	printf("%d\n", ft_atoi("-2147483649"));
	printf("%d\n", ft_atoi("-999999999999999999999"));
}
*/
