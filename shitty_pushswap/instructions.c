/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: supersko <supersko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 16:54:06 by supersko          #+#    #+#             */
/*   Updated: 2022/05/16 14:59:54 by supersko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// bug avec les arguments passés
void	push(char *instr, t_lst *lst_a, t_lst *lst_b)
{
	if (*instr > 96)
	{
		write(1, "p", 1);
		write(1, instr, 1);
		write(1, "\n", 1);
	}
	if (*instr == 'a' || *instr == 'A')
		push_item(pop(lst_b), lst_a);
	else if (*instr == 'b' || *instr == 'B')
		push_item(pop(lst_a), lst_b);
	else
		error_msg(NULL);
	if (*(++instr) != '\n' && *instr != 0)
		error_msg(NULL);
}

void	swap(char *instr, t_lst *lst_a, t_lst *lst_b)
{
	if (*instr > 96)
	{
		write(1, "s", 1);
		write(1, instr, 1);
		write(1, "\n", 1);
	}
	if (*instr == 'a' || *instr == 'A')
		swap_lst(lst_a);
	else if (*instr == 'b' || *instr == 'B')
		swap_lst(lst_b);
	else if (*instr == 's' || *instr == 'S')
	{
		swap_lst(lst_a);
		swap_lst(lst_b);
	}
	else
		error_msg(NULL);
	if (*(++instr) != '\n' && *instr != 0)
		error_msg(NULL);
}

void	print_rotate_instr(char *instr)
{
	if (*instr > 96)
	{
		write(1, "r", 1);
		write(1, instr, 1);
		if (*instr == 'r')
			write(1, instr + 1, 1);
		write(1, "\n", 1);
	}
}

void	rotate(char *instr, t_lst *lst_a, t_lst *lst_b)
{
	int	reverse;

	reverse = 0;
	print_rotate_instr(instr);
	if (*instr == 'r' || *instr == 'R')
	{
		reverse = 1;
		instr++;
	}
	if (*instr == 'a' || *instr == 'A')
		rotate_lst(lst_a, reverse);
	else if (*instr == 'b' || *instr == 'B')
		rotate_lst(lst_b, reverse);
	else if (*instr == 'r' || *instr == 'R')
	{
		rotate_lst(lst_a, reverse);
		rotate_lst(lst_b, reverse);
	}
	else
		error_msg(NULL);
	if (*(++instr) != '\n' && *instr != 0)
		error_msg(NULL);
}
