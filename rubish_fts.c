
int	step_counter(int rank, t_lnk *lst)
{
	int		step_nb;
	t_lnk	*link_ind;

	if (!lst)
		error_msg("[get_shortestway] empty list passed");
	step_nb = -1;
	link_ind = lst;
	if (link_ind->rank == rank)
		return (-1);
	link_ind = link_ind->next;
	while (link_ind != lst)
	{
		step_nb++;
		if (link_ind->rank == rank)
			return (step_nb);
		link_ind = link_ind->next;
	}
	return (-2);
}

int	step_counter(int rank, t_lnk *lst)
{
	int		step_nb;
	t_lnk	*link_ind;

	if (!lst)
		error_msg("[get_shortestway] empty list passed");
	step_nb = -1;
	link_ind = lst;
	if (link_ind->rank == rank)
		return (-1);
	link_ind = link_ind->next;
	while (link_ind != lst)
	{
		step_nb++;
		if (link_ind->rank == rank)
			return (step_nb);
		link_ind = link_ind->next;
	}
	return (-2);
}

// something must be already pushed in lst_b
void	push_reachwise_relMin(t_lnk **lst_a, t_lnk **lst_b, int *relMin)
{
	if (!(*lst_b))
		error_msg("[push_reachwise_] lst_b is empty when used");
	while ((*lst_a)->prev->rank != *relMin)
	{
		while ((*lst_a)->prev->rank != *relMin && (*lst_a)->rank > (*lst_b)->rank)
			apply_instr(pb, lst_a, lst_b, 1);
		if ((*lst_a)->prev->rank > *relMin)
			apply_instr(rra, lst_a, lst_b, 1);
	}
}

/*
void	bubble_loop_nb(t_lst *lst, t_lst *dest_lst)
{
	if (lst->size && (lst->last)->nb == lst->max_val)
		rotate("ra", lst, NULL);
	if (lst->size && (lst->first)->nb == lst->max_val)
		while (lst->first && (lst->first)->nb == lst->max_val)
			push("a", dest_lst, lst);
	if (lst->size && (lst->first)->nb > ((lst->first)->next)->nb)
		swap("a", lst, NULL);
	if (lst->size > 1)
		rotate("a", lst, NULL);
}

t_lst	*bubble_sort_decr_nb(t_lst *lst, t_lst *dest_lst)
{
	int		step;

	step = 0;
	while (lst->size > 1)
	{
		while (step + 2 < lst->size)
		{
			bubble_loop_nb(lst, dest_lst);
			step++;
		}
		if (lst->size > 1 && (lst->first)->nb != lst->max_val)
			rotate("A", lst, NULL);
		else if (lst->size > 1)
			push("A", dest_lst, lst);
		step = 0;
	}
	if (lst->size)
		push("A", dest_lst, lst);
	return (dest_lst);
}

void	swap_loc(t_lnk *lnk)
{
	t_lnk	*second_lnk;

	if (lnk && lnk->next != lnk)
	{	
		second_lnk = lnk->next;
		(second_lnk->next)->prev = lnk;
		(lnk->prev)->next = second_lnk;
		lnk->next = second_lnk->next;
		second_lnk->prev = lnk->prev;
		lnk->prev = second_lnk;
		second_lnk->next = lnk;
	}
	else
		error_msg("error at swap_loc");
}
*/

/*
t_lst	*inplace_sort_incr(t_lst *lst)
{
	int		ii;
	t_lnk	*lnk_ind;

	if (lst)
	{
		lst_init_rankinlist(lst);
		lst_init_indinlist(lst);
		ii = 0;
	}

}
*/

/*
int main(int argc, char **argv)
{
	t_lst *lst_ini;

	lst_ini = get_args(argc, argv);
	print_lst(lst_ini, NULL);
	write(1, "\n", 1);
	reachSorting_up_incr(lst_ini, lst_ini->size - 1);
	write(1, "\n", 1);
	print_lst(lst_ini, NULL);
}
*/

