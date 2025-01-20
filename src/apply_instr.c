/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/01/20 18:49:00 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	foret_de_ifs(int instr, t_lnk **lst_a, t_lnk **lst_b)
{
	if (instr == sa)
		swap_lst(lst_a);
	else if (instr == sb)
		swap_lst(lst_b);
	else if (instr == ss)
	{
		swap_lst(lst_a);
		swap_lst(lst_b);
	}
	else if (instr == ra)
		rotate_lst(lst_a);
	else if (instr == rb)
		rotate_lst(lst_b);
	else if (instr == rr)
	{
		rotate_lst(lst_b);
		rotate_lst(lst_a);
	}
	else
	{
		ft_errmsg("[instr_not_set]\n");
	}
}

void	apply_instr(int instr, t_lnk **lst_a, t_lnk **lst_b, int to_print)
{

	//if (lst_a)
	//	print_lst_byrank(*lst_a, "after : lst_a");
	//if (lst_b)
	//	print_lst_byrank(*lst_b, "after : lst_b");
	//printf("--------------------------------------------");
	if (instr == rra)
		rrotate_lst(lst_a);
	else if (instr == rrb)
		rrotate_lst(lst_b);
	else if (instr == rrr)
	{
		rrotate_lst(lst_b);
		rrotate_lst(lst_a);
	}
	else if (instr == pa)
		push(lst_b, lst_a);
	else if (instr == pb)
		push(lst_a, lst_b);
	else
		foret_de_ifs(instr, lst_a, lst_b);
	if (to_print)
		i_to_instr(instr);
}

int	foret_de_ifs_2(char *str)
{
	int	ret;

	if (!ft_strncmp(str, "ra\n", 3))
		ret = ra;
	else if (!ft_strncmp(str, "rb\n", 3))
		ret = rb;
	else if (!ft_strncmp(str, "sa\n", 3))
		ret = sa;
	else if (!ft_strncmp(str, "sb\n", 3))
		ret = sb;
	else if (!ft_strncmp(str, "pa\n", 3))
		ret = pa;
	else if (!ft_strncmp(str, "pb\n", 3))
		ret = pb;
	else
		ret = -1;
	return (ret);
}

int	instr_to_i(char *str)
{
	int	ret;

	ret = -1;
	if (!(*str))
		ret = 0;
	else if (!ft_strncmp(str, "rrr\n", 4))
		ret = rrr;
	else if (!ft_strncmp(str, "rra\n", 4))
		ret = rra;
	else if (!ft_strncmp(str, "rrb\n", 4))
		ret = rrb;
	else if (!ft_strncmp(str, "rr\n", 3))
		ret = rr;
	else if (!ft_strncmp(str, "ss\n", 3))
		ret = ss;
	else
		ret = foret_de_ifs_2(str);
	if (ret == -1)
		ft_errmsg("error\n");
	return (ret);
}

void	i_to_instr(int i)
{
	if (i == rrr)
		printf("rrr");
	else if (i == rra)
		printf("rra");
	else if (i == rrb)
		printf("rrb");
	else if (i == ra)
		printf("ra");
	else if (i == rb)
		printf("rb");
	else if (i == rr)
		printf("rr");
	else if (i == pa)
		printf("pa");
	else if (i == pb)
		printf("pb");
	else if (i == sa)
		printf("sa");
	else if (i == sb)
		printf("sb");
	else if (i == ss)
		printf("ss");
	else
		ft_errmsg("error\n");
	printf("\n");
}
