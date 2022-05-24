/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2022/05/24 19:17:09 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	fucking_norminette(int instr, t_lnk **lst_a, t_lnk **lst_b)
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
		error_msg("[apply_instr] instruction probably wrong");
	}
}

void	apply_instr(int instr, t_lnk **lst_a, t_lnk **lst_b, int to_print)
{
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
		fucking_norminette(instr, lst_a, lst_b);
	if (to_print)
		i_to_instr(instr);
}

int	fucking_normi_2(char *str)
{
	int	ret;

	if (!ft_strncmp(str, "ra", 2))
		ret = ra;
	else if (!ft_strncmp(str, "rb", 2))
		ret = rb;
	else if (!ft_strncmp(str, "sa", 2))
		ret = sa;
	else if (!ft_strncmp(str, "sb", 2))
		ret = sb;
	else if (!ft_strncmp(str, "pa", 2))
		ret = pa;
	else if (!ft_strncmp(str, "pb", 2))
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
	else if (!ft_strncmp(str, "rrr", 3))
		ret = rrr;
	else if (!ft_strncmp(str, "rra", 3))
		ret = rra;
	else if (!ft_strncmp(str, "rrb", 3))
		ret = rrb;
	else if (!ft_strncmp(str, "rr", 2))
		ret = rr;
	else if (!ft_strncmp(str, "ss", 2))
		ret = ss;
	else
		ret = fucking_normi_2(str);
	if (ret == -1)
		error_msg("[instr_to_i] Error");
	return (ret);
}

void	i_to_instr(int i)
{
	if (i == rrr)
		ft_printf("rrr");
	else if (i == rra)
		ft_printf("rra");
	else if (i == rrb)
		ft_printf("rrb");
	else if (i == ra)
		ft_printf("ra");
	else if (i == rb)
		ft_printf("rb");
	else if (i == rr)
		ft_printf("rr");
	else if (i == pa)
		ft_printf("pa");
	else if (i == pb)
		ft_printf("pb");
	else if (i == sa)
		ft_printf("sa");
	else if (i == sb)
		ft_printf("sb");
	else if (i == ss)
		ft_printf("ss");
	else
		error_msg("[i_to_instr]: instruction non reconnue\n");
	ft_printf("\n");
}
