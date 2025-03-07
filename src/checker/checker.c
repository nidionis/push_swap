/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 20:28:38 by nidionis          #+#    #+#             */
/*   Updated: 2025/03/07 20:28:38 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

/**
 * @brief Cherche l'instruction correspondante dans la map d'instructions
 * 
 * @param data La structure de données contenant la map d'instructions
 * @param cmd La commande à chercher
 * @return int Le code de l'instruction ou -1 si non trouvée
 */
static int	get_instruction_code(t_data *data, char *cmd)
{
	int	i;

	if (!data || !data->instr_map)
		return (-1);

	i = 0;
	while (data->instr_map[i].name)
	{
		if (!ft_strcmp(data->instr_map[i].name, cmd))
			return (data->instr_map[i].code);
		i++;
	}
	return (-1);
}

/**
 * @brief Exécute les instructions depuis l'entrée standard
 * 
 * @param data La structure de données contenant les piles
 * @return int 0 si réussi, 1 en cas d'erreur
 */
static int	execute_instructions(t_data *data)
{
	char	*line;
	int		instr_code;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break;
		
		// Supprimer le caractère de nouvelle ligne s'il est présent
		if (ft_strlen(line) > 0 && line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
			
		// Si la ligne est vide après suppression du saut de ligne, passer à la suivante
		if (!*line)
		{
			free(line);
			continue;
		}
		
		// Trouver le code d'instruction correspondant
		instr_code = get_instruction_code(data, line);
		free(line);
		
		// Si l'instruction n'est pas reconnue, signaler une erreur
		if (instr_code == -1)
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		
		// Appliquer l'instruction en mode silencieux
		apply_instr(data, instr_code, QUIET);
	}
	return (0);
}

/**
 * @brief Vérifie si la pile B est vide et la pile A est triée
 * 
 * @param data La structure de données contenant les piles
 * @return int 1 si les piles sont correctement triées, 0 sinon
 */
static int	is_stack_sorted(t_data *data)
{
	// Vérification manuelle des piles
	t_lnk *lst_a;
	
	// Vérifier que la pile B est vide
	if (data->lst_b)
		return (0);
	

	
	// Si la pile A est vide, elle est considérée comme triée
	if (!data->lst_a)
		return (1);
		
	// Vérification manuelle pour éviter les segfaults
	lst_a = data->lst_a;
	while (lst_a && lst_a->next && lst_a->next != data->lst_a)
	{
		if (lst_a->rank > lst_a->next->rank)
		{
			return (0);
		}
		lst_a = lst_a->next;
	}
	
	return (1);
}

/**
 * @brief Programme principal
 * 
 * @param argc Nombre d'arguments
 * @param argv Tableau d'arguments
 * @return int 0 si succès, 1 si erreur
 */
int	main(int argc, char **argv)
{
	t_data	data;

	// Initialisation
	ft_bzero(&data, sizeof(t_data));
	
	// Vérifier qu'il y a des arguments
	if (argc < 2)
		return (0);
	
	// Charger les arguments dans la pile A
	data.lst_a = get_args(&data, argc, argv);
	data.rank_max = lst_init_ranks(&data.lst_a);
	data.lst_b = NULL;
	
	// Vérifier qu'il n'y a pas de duplications
	if (!ft_no_duplicate(data.lst_a))
	{
		ft_putstr_fd("Error\n", 2);
		del_lst(&data.lst_a);
		return (1);
	}
	
	// Initialiser les structures de données
	init_data(&data, &data.lst_a, &data.lst_b);
	data.instr_map = init_instr_map();
	
	// Exécuter les instructions
	if (execute_instructions(&data))
	{
		// En cas d'erreur, nettoyer et quitter
		del_lst(&data.lst_a);
		del_lst(&data.lst_b);
		free(data.instr_map);
		return (1);
	}
	
	// Afficher l'état final des piles pour faciliter le débogage
	ft_putstr_fd("\n===== État final des piles =====\n", 1);
	ft_putstr_fd("Pile A: ", 1);
	print_lst_inline(data.lst_a);
	ft_putstr_fd("\nPile B: ", 1);
	print_lst_inline(data.lst_b);
	ft_putstr_fd("\n\n", 1);

	// Vérifier si la pile est triée
	if (is_stack_sorted(&data))
	{
		ft_putstr_fd("OK\n", 1);
	}
	else
	{
		ft_putstr_fd("KO\n", 1);
	}
	
	// Nettoyer
	del_lst(&data.lst_a);
	del_lst(&data.lst_b);
	free(data.instr_map);
	
	return (0);
}
