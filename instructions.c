#include "push_swap.h"
#include <stdio.h>

void	push(char *instr, t_lst *lst_a, t_lst *lst_b)
{
	t_lnk   *tmp;

	if (*instr > 96) // si instr est minuscule, imprimer 
	{
		write(1, "p", 1);
		write(1, instr, 1);
		write(1, "\n", 1);
	}
	if (*instr == 'a' || 'A')
		push_item(pop(lst_a), lst_b);
	else if (*instr == 'b' || 'B')
		push_item(pop(lst_b), lst_a);
	else
		error_msg(NULL);
	if (*(++instr))
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
	if (instr > 96) // si instr est minuscule, imprimer 
	{
		write(1, "s", 1);
		write(1, instr, 1);
		write(1, "\n", 1);
	}
	if (*instr == 'a' || 'A')
		swap_lst(lst_a);
	else if (*instr == 'b' || 'B')
		swap_lst(lst_b);
	else if (*instr == 's' || 'S')
	{
		swap_lst(lst_a);
		swap_lst(lst_b);
	}
	else
		error_msg(NULL);
	if (*(++instr))
		error_msg(NULL);
}

void	apply_instruction(char *instr, t_lst *lst_a, t_lst *lst_b)  
{
	if (*instr == 's')
		swap(++instr, lst_a, lst_b);
	else if (*instr == 'p')
		push(++instr, lst_a, lst_b);
}

int main(int argc, char *argv[])
{
		char	*buff;
		t_lst  *lst_a; 
		t_lst  *lst_b; 

		lst_a = get_args(argc, argv);
		lst_b = new_lst();
		print_lst(lst_a, lst_b);
		write(1, "\n", 1);
		apply_instruction("pa", lst_a, lst_b);
		print_lst(lst_a, lst_b);
		// while ((buff = get_next_line(0)) != NULL)
		// {
		//		 apply_instruction(buff, lst_a, lst_b);
		// }
}
