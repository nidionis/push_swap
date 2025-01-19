/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/19 06:49:55 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int ft_isspace(char c)
{
	return (!(!ft_strchr(ISSPACE, c)));
}

int c_to_i(char c)
{
	if (ft_isdigit(c))
		return (c - '0');
	return (INT_MIN);
}

long int       ft_atoi_err(char *str)
{
	long int        sign;
	long int        nbr;

	sign = 1;
	while (ft_isspace(*str))
	        str++;
	if (*str == '-' || *str == '+')
	        if (*str++ == '-')
	                sign *= -1;
	nbr = 0;
	if (!ft_isdigit(*str))
	        return (2147483649);
	while (ft_isdigit(*str))
	{
	        nbr *= 10;
	        nbr += (long int) c_to_i(*str++);
	        if (nbr > 2147483648)
	                return (nbr);
	}
	if (*str)
	        return (2147483649);
	nbr *= sign;
	return (nbr);
}

void	select_algo(t_lnk *lst_a, t_lnk *lst_b, int ind_max)
{
	if (ind_max == 0)
		del_lst(&lst_a);
	else if (ind_max == 1)
		sort_2_nb(&lst_a);
	else if (ind_max == 2)
		sort_3_nb(&lst_a, ind_max);
	else if (ind_max == 3)
		sort_4_nb(&lst_a, &lst_b);
	else if (ind_max == 4)
		sort_5_nb(&lst_a, &lst_b);
	else
	{
		load_b(&lst_a, &lst_b, ind_max);
		//b_dump(&lst_a, &lst_b);
	}
	reach_rank(&lst_a, 0, get_shortestway(lst_a, 0), PRINT);
}

int	pusw_swpap(int argc, char **argv)
{
	t_lnk	*lst_a;
	t_lnk	*lst_b;
	int		ind_max;

	lst_b = NULL;
	if (argc < 2)
		return (1);
	else if (argc == 2)
	{
	//	if (!(*argv[1]))
			return (0);
		//lst_a = get_args_allinone(argv[1]);
	}
	lst_a = get_args(argc, argv);
	print_lst_byrank(lst_a, "aaa");
	if (!lst_a)
		return (1);
	ind_max = lst_init_ranks(&lst_a);
	if (ft_duplicate(lst_a))
		return (ft_errmsg("error\n"), 1);
	if (!is_sorted(lst_a))
		select_algo(lst_a, lst_b, ind_max);
	del_lst(&lst_a);
	del_lst(&lst_b);
	return (0);
}


int	main(int argc, char *argv[])
{
	t_lnk	*lst;
	t_lnk	*lnk_ind;
	int		i;

	lst = NULL;
	i = 1;
	while (i < argc)
	{
		lnk_ind = ft_new_lnk(ft_atoi(argv[i]), i, 0);
		push_item(lnk_ind, &lst);
		i++;
	}
	printf("is_in_lst ? %d\n", is_in_lst(lst));
	return (0);
}
