/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/04/03 18:02:16 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main_algo(t_data d, int coef_turk, int r_x, int verbose)
{
	int	r_instr[12];
	int	nb_instr;

	init_r_instr_load_b_turk_(r_instr);
	nb_instr = load_b_opti_turk(&d, coef_turk, r_x, verbose);
	nb_instr += dump_b_basic(&d, r_instr, verbose);
	nb_instr += reach_rank_a(&d, 0, verbose);
	return (nb_instr);
}

void	parsing(t_data *d, int argc, char **argv)
{
	ft_bzero(d, sizeof(t_data));
	init_instr_map(&d->instr_map);
	d->a.lst = get_args(d, argc, argv);
	d->rank_max = lst_init_ranks(&d->a.lst);
	d->b.lst = NULL;
	if (!ft_no_duplicate(d->a.lst))
		ft_errmsg("Error: duplicated items");
	init_data(d, &d->a.lst, &d->b.lst);
}

int	main(int argc, char **argv)
{
	t_data	d;
	int		best_coef;

	if (argc < 2)
	{
		ft_errmsg(NULL);
		exit(0);
	}
	parsing(&d, argc, argv);
	best_coef = find_best_coef_turk(d);
	main_algo(d, best_coef, ra, PRINT_DISPLAY);
	del_lst(&d.a.lst);
	del_lst(&d.b.lst);
}
