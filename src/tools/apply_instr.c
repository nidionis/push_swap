/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/02/09 21:05:35 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_instr_map	*init_instr_map(void)
{
	t_instr_map *instr_map;
	
	instr_map = malloc(sizeof(t_instr_map) * 12);
	if (!instr_map)
		return (NULL);
	instr_map[0] = (t_instr_map){"sa", sa, swap_a};
	instr_map[1] = (t_instr_map){"sb", sb, swap_b};
	instr_map[2] = (t_instr_map){"ss", ss, swap_both};
	instr_map[3] = (t_instr_map){"ra", ra, rotate_a};
	instr_map[4] = (t_instr_map){"rb", rb, rotate_b};
	instr_map[5] = (t_instr_map){"rr", rr, rotate_both};
	instr_map[6] = (t_instr_map){"rra", rra, rrotate_a};
	instr_map[7] = (t_instr_map){"rrb", rrb, rrotate_b};
	instr_map[8] = (t_instr_map){"rrr", rrr, rrotate_both};
	instr_map[9] = (t_instr_map){"pa", pa, push_a};
	instr_map[10] = (t_instr_map){"pb", pb, push_b};
	instr_map[11] = (t_instr_map){NULL, -1, NULL};
	return (instr_map);
}

void	print_instr(t_data *data, int instr)
{
	t_instr_map	*instr_map;
	int			i;

	i = 0;
	instr_map = data->instr_map;
	while (instr_map[i].name)
	{
		if (instr_map[i].code == instr)
		{
			printf("%s\n", instr_map[i].name);
			return ;
		}
		i++;
	}
}

void	print_instr_from_int_heavy(int instr)
{
	t_instr_map	*instr_map;
	int			i;

	i = 0;
	instr_map = init_instr_map();
	while (instr_map[i].name)
	{
		if (instr_map[i].code == instr)
		{
			printf("%s\n", instr_map[i].name);
			return ;
		}
		i++;
	}
	free(instr_map);
}

void	execute_command(t_lnk **lst_a, t_lnk **lst_b, int instr, t_instr_map instr_map[])
{
	int					i;

	i = 0;
	while (instr_map[i].code != -1)
	{
		if (instr_map[i].code == instr)
		{
			instr_map[i].func(lst_a, lst_b);
			return ;
		}
		i++;
	}
	fprintf(stderr, "[execute_command] Invalid instruction %i\n", instr);
	//ft_errmsg("[execute_command] Invalid instruction");
}

int	is_rotating(int instr)
{
	if (instr == ra || instr == rb || instr == rra || instr == rrb || instr == rr || instr == rrr)
		return (TRUE);
	return (FALSE);
}

/**
 * @brief Applique une instruction aux piles et met à jour la structure de données
 *
 * @param data Structure contenant les données
 * @param instr Code de l'instruction à appliquer
 * @param to_print Indique si l'instruction doit être affichée
 * @return int Toujours 1 (succès)
 */
int	apply_instr(t_data *data, int instr, int to_print)
{
	/* Exécuter la commande sur les piles */
	execute_command(&(data->lst_a), &(data->lst_b), instr, data->instr_map);
	
	/* Afficher l'instruction si nécessaire */
	if (to_print == PRINT)
		print_instr(data, instr);
	
	/* Mettre à jour les données si l'instruction n'est pas une rotation */
	if (!is_rotating(instr))
		data_update(data, &data->lst_a, &data->lst_b);
		
	return (1);
}
