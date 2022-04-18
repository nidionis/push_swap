#include "push_swap.h"
#include <stdio.h>

// bug avec les arguments passés
void	push(char *instr, t_lst *lst_a, t_lst *lst_b)
{
	if (*instr > 96) // si instr est minuscule, imprimer 
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

int verif(t_lst *lst_a)
{
		t_lnk *lnk;

		lnk = lst_a->first;
		while (lnk->nb < (lnk->next)->nb && lnk != lst_a->last)
				lnk = lnk->next;
		if (lnk == lst_a->last)
				return (1);
		else
				return (0);
}

void	swap(char *instr, t_lst *lst_a, t_lst *lst_b)  
{
	if (*instr > 96) // si instr est minuscule, imprimer 
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

void	rotate(char *instr, t_lst *lst_a, t_lst *lst_b)  
{
	int	reverse;

	if (*instr > 96) // si instr est minuscule, imprimer 
	{
		write(1, "r", 1);
		write(1, instr, 1);
		if (*instr == 'r')
				write(1, instr + 1, 1);
		write(1, "\n", 1);
	}
	reverse = 0;
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

void	apply_instruction(char *instr, t_lst *lst_a, t_lst *lst_b)  
{
	if (*instr == 's')
		swap(++instr, lst_a, lst_b);
	else if (*instr == 'p')
		push(++instr, lst_a, lst_b);
	else if (*instr == 'r')
		rotate(++instr, lst_a, lst_b);
	else
		error_msg(NULL);
}

/*
int main(int argc, char *argv[])
{
		char	*buff;
		t_lst  *lst_a; 
		t_lst  *lst_b; 

		lst_a = get_args(argc, argv);
		lst_b = new_lst();
		write(1, "\n", 1);
		apply_instruction("pa", lst_a, lst_b);
		apply_instruction("pa", lst_a, lst_b);
		apply_instruction("pa", lst_a, lst_b);
		print_lst(lst_a, lst_b);
		apply_instruction("rrr", lst_a, lst_b);
		print_lst(lst_a, lst_b);
		// while ((buff = get_next_line(0)) != NULL)
		// {
		//		 apply_instruction(buff, lst_a, lst_b);
		// }
}
*/
