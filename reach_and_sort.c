#include "push_swap.h"

t_lst	*reachSorting_rev_decr(t_lst *lst, int rank_inlst)
{
	if (lst && lst->size > 1 && rank_inlst < lst->size)
	{
		if ((lst->first)->rankinlist == ((lst->first)->next)->rankinlist)
			lst_init_rankinlist(lst);
		while ((lst->first)->rankinlist != rank_inlst)
		{
			if ((lst->first)->rankinlist > ((lst->first)->next)->rankinlist)
				swap("A", lst, NULL);
			if  ((lst->first)->rankinlist != rank_inlst)
				rotate("RA", lst, NULL);
		}
		return (lst);
	}
}

t_lst	*reachSorting_rev_incr(t_lst *lst, int rank_inlst)
{
	if (lst && lst->size > 1 && rank_inlst < lst->size)
	{
		if ((lst->first)->rankinlist == ((lst->first)->next)->rankinlist)
			lst_init_rankinlist(lst);
		while ((lst->first)->rankinlist != rank_inlst)
		{
			if ((lst->first)->rankinlist < ((lst->first)->next)->rankinlist)
				swap("A", lst, NULL);
			if  ((lst->first)->rankinlist != rank_inlst)
				rotate("RA", lst, NULL);
		}
		return (lst);
	}
}

t_lst	*reachSorting_incr(t_lst *lst, int rank_inlst)
{
	if (lst && lst->size > 1 && rank_inlst < lst->size)
	{
		if ((lst->first)->rankinlist == ((lst->first)->next)->rankinlist)
			lst_init_rankinlist(lst);
		while ((lst->first)->rankinlist != rank_inlst)
		{
			if ((lst->first)->rankinlist < ((lst->first)->next)->rankinlist)
				swap("A", lst, NULL);
			if  ((lst->first)->rankinlist != rank_inlst)
				rotate("A", lst, NULL);
		}
		return (lst);
	}
}

t_lst	*reachSorting_decr(t_lst *lst, int rank_inlst)
{
	if (lst && lst->size > 1 && rank_inlst < lst->size)
	{
		if ((lst->first)->rankinlist == ((lst->first)->next)->rankinlist)
			lst_init_rankinlist(lst);
		while ((lst->first)->rankinlist != rank_inlst)
		{
			if ((lst->first)->rankinlist > ((lst->first)->next)->rankinlist)
				swap("A", lst, NULL);
			if  ((lst->first)->rankinlist != rank_inlst)
				rotate("A", lst, NULL);
		}
		return (lst);
	}
}

t_lst *reachAndSort(t_lst *lst, int rank_inlst, int ordre_croissant)
{
	if (lst && rank_inlst < lst->size)
	{
		if (ordre_croissant)
		{
			if (rank_inlst > (lst->size / 2))
				reachSorting_rev_incr(lst, rank_inlst);
			else
				reachSorting_incr(lst, rank_inlst);
		}
		else
		{
			if (rank_inlst > (lst->size / 2))
				reachSorting_rev_decr(lst, rank_inlst);
			else
				reachSorting_decr(lst, rank_inlst);
		}
	}
}

int		getIndFromRank(t_lst *lst, int rank)
{
	t_lnk	*lnk;

	if (lst && rank < lst->size)
	{
		lnk = lst->first;
		while (lnk->rank != rank && lnk->next != lst->first)
			lnk = lnk->next;
		return (lnk->ind);
	}
}
//
//t_lst	*lst_init_indinlist(t_lst *lst)
//{
//	t_lnk	*lnk;
//	int		ii;
//
//	if (lst)
//	{
//		ii = 0;
//		lnk = lst->first;
//		while (ii < lst->size)
//		{
//			lnk->indinlist = ii++;
//			lnk = lnk->next;
//		}
//		return (lst);
//	}
//}

int		getIndFromRank_InList(t_lst *lst, int rank_inlst)
{
	t_lnk	*lnk;

	if (lst && rank_inlst < lst->size)
	{
		lnk = lst->first;
		if (lnk->rankinlist == (lnk->next)->rankinlist)
		{
			printf("GetIndFromRank] before lst_init_rankinLst");
			lst_init_rankinlist(lst);
			printf("GetIndFromRank] after lst_init_rankinLst");
		}
		if (lnk->indinlist == (lnk->next)->indinlist)
		{
			printf("GetIndFromRank] before lst_init_indinlist");
			lst_init_indinlist(lst);
			printf("GetIndFromRank] after lst_init_indinlist");
		}
		while (lnk->rankinlist != rank_inlst && lnk->next != lst->first)
			lnk = lnk->next;
		return (lnk->indinlist);
	}
	else
			error_msg("[In getIndFromRank_InList]: weird parameter\n");
}

t_lst *bubbleReachAndSort(t_lst *lst, int rank_inlst, int ordre_croissant)
{
	if (lst && lst->size > 1 && rank_inlst < lst->size)
	{
		return (NULL);
	}
}

int	main(int argc, char **argv)
{
	t_lst	*lst;
	t_lst	*tmp;
	t_lnk	*lnk;

	lst = get_args(argc, argv);
	tmp = malloc(sizeof(t_lst));
	push("A", tmp, lst);
	swap("A", lst, NULL);
	push("B", tmp, lst);
	rotate("RA", lst, NULL);
	print_lst(lst, tmp);
//	printf("rank %d,  ind %d\n", 0, getIndFromRank(lst, 0));
//	printf("rank %d,  ind %d\n", lst->size - 1, getIndFromRank(lst, lst->size - 1));
//	printf("rank %d,  ind %d\n", 1, getIndFromRank(lst, 1));
//	//printf("\n");
//	//printf("rankInlst %d,  ind %d\n", 0, getIndFromRank_InList(lst, 0));
	printf("rankInlst %d,  ind %d\n", lst->size - 1, getIndFromRank_InList(lst, lst->size - 1));
	//printf("rankInlst %d,  ind %d\n", 1, getIndFromRank_InList(lst, 1));
	
/*
	printf("going to the min value, decroissant:\n", lst->min_val);
	reachAndSort(lst, 0, 0);
	print_lst(lst, NULL);
	printf("going to the max value, croissant:\n", lst->max_val);
	reachAndSort(lst, lst->size - 1, 1);
	print_lst(lst, NULL);
	printf("going to the min value, croissant:\n", lst->min_val);
	reachAndSort(lst, 0, 1);
	print_lst(lst, NULL);
	printf("going to the max value, decroissant:\n", lst->max_val);
	reachAndSort(lst, lst->size - 1, 0);
	print_lst(lst, NULL);
	*/
}
