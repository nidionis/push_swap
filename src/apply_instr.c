/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nidionis <nidionis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 17:24:45 by supersko          #+#    #+#             */
/*   Updated: 2025/02/02 18:56:54 by nidionis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

//void	fucking_norminette(t_lnk **lst_a, t_lnk **lst_b, int instr)
//{
//	if (instr == sa)
//		swap_lst(lst_a);
//	else if (instr == sb)
//		swap_lst(lst_b);
//	else if (instr == ss)
//	{
//		swap_lst(lst_a);
//		swap_lst(lst_b);
//	}
//	else if (instr == ra)
//		rotate_lst(lst_a);
//	else if (instr == rb)
//		rotate_lst(lst_b);
//	else if (instr == rr)
//	{
//		rotate_lst(lst_b);
//		rotate_lst(lst_a);
//	}
//	else
//	{
//		ft_errmsg("[apply_instr] instruction probably wrong");
//	}
//}
//
//void	apply_instr(t_data *data, t_lnk **lst_a, t_lnk **lst_b, int instr, int to_print)
//{
//	if (instr == rra)
//		rrotate_lst(lst_a);
//	else if (instr == rrb)
//		rrotate_lst(lst_b);
//	else if (instr == rrr)
//	{
//		rrotate_lst(lst_b);
//		rrotate_lst(lst_a);
//	}
//	else if (instr == pa)
//	{
//		push(lst_b, lst_a);
//	}
//	else if (instr == pb)
//	{
//		push(lst_a, lst_b);
//	}
//	else
//		fucking_norminette(lst_a, lst_b, instr);
//	if (to_print)
//		i_to_instr(instr);
//	data_update(data, lst_a, lst_b);
//}
//
//int	fucking_normi_2(char *str)
//{
//	int	ret;
//
//	if (!ft_strncmp(str, "ra", 2))
//		ret = ra;
//	else if (!ft_strncmp(str, "rb", 2))
//		ret = rb;
//	else if (!ft_strncmp(str, "sa", 2))
//		ret = sa;
//	else if (!ft_strncmp(str, "sb", 2))
//		ret = sb;
//	else if (!ft_strncmp(str, "pa", 2))
//		ret = pa;
//	else if (!ft_strncmp(str, "pb", 2))
//		ret = pb;
//	else
//		ret = -1;
//	return (ret);
//}
//
//int	instr_to_i(char *str)
//{
//	int	ret;
//
//	ret = -1;
//	if (!(*str))
//		ret = 0;
//	else if (!ft_strncmp(str, "rrr", 3))
//		ret = rrr;
//	else if (!ft_strncmp(str, "rra", 3))
//		ret = rra;
//	else if (!ft_strncmp(str, "rrb", 3))
//		ret = rrb;
//	else if (!ft_strncmp(str, "rr", 2))
//		ret = rr;
//	else if (!ft_strncmp(str, "ss", 2))
//		ret = ss;
//	else
//		ret = fucking_normi_2(str);
//	if (ret == -1)
//		ft_errmsg("[instr_to_i] Error");
//	return (ret);
//}
//
//void	i_to_instr(int i)
//{
//	if (i == rrr)
//		printf("rrr");
//	else if (i == rra)
//		printf("rra");
//	else if (i == rrb)
//		printf("rrb");
//	else if (i == ra)
//		printf("ra");
//	else if (i == rb)
//		printf("rb");
//	else if (i == rr)
//		printf("rr");
//	else if (i == pa)
//		printf("pa");
//	else if (i == pb)
//		printf("pb");
//	else if (i == sa)
//		printf("sa");
//	else if (i == sb)
//		printf("sb");
//	else if (i == ss)
//		printf("ss");
//	else
//		ft_errmsg("[i_to_instr]: instruction non reconnue\n");
//	printf("\n");
//}

typedef struct s_instr_map
{
    char    *name;
    int     code;
}   t_instr_map;

typedef struct s_cmd_map
{
    int     code;
    void    (*func)(t_lnk **, t_lnk **);
}   t_cmd_map;

//void    swap_a(t_lnk **a, t_lnk **b) { (void)b; swap_lst(a); }
//void    swap_b(t_lnk **a, t_lnk **b) { (void)a; swap_lst(b); }
//void    swap_both(t_lnk **a, t_lnk **b) { swap_lst(a); swap_lst(b); }
//void    rotate_a(t_lnk **a, t_lnk **b) { (void)b; rotate_lst(a); }
//void    rotate_b(t_lnk **a, t_lnk **b) { (void)a; rotate_lst(b); }
//void    rotate_both(t_lnk **a, t_lnk **b) { rotate_lst(a); rotate_lst(b); }
//void    rrotate_a(t_lnk **a, t_lnk **b) { (void)b; rrotate_lst(a); }
//void    rrotate_b(t_lnk **a, t_lnk **b) { (void)a; rrotate_lst(b); }
//void    rrotate_both(t_lnk **a, t_lnk **b) { rrotate_lst(a); rrotate_lst(b); }
//void    push_a(t_lnk **a, t_lnk **b) { push(b, a); }
//void    push_b(t_lnk **a, t_lnk **b) { push(a, b); }

void    execute_command(t_lnk **lst_a, t_lnk **lst_b, int instr)
{
    int i = 0;
    static const t_cmd_map cmd_map[] = {
        {sa, swap_a}, {sb, swap_b}, {ss, swap_both},
        {ra, rotate_a}, {rb, rotate_b}, {rr, rotate_both},
        {rra, rrotate_a}, {rrb, rrotate_b}, {rrr, rrotate_both},
        {pa, push_a}, {pb, push_b}, {-1, NULL}
    };

    while (cmd_map[i].code != -1)
    {
        if (cmd_map[i].code == instr)
        {
            cmd_map[i].func(lst_a, lst_b);
            return;
        }
        i++;
    }
    ft_errmsg("[execute_command] Invalid instruction");
}

void    apply_instr(t_data *data, t_lnk **lst_a, t_lnk **lst_b, int instr, int to_print)
{
    execute_command(lst_a, lst_b, instr);
    if (to_print)
        i_to_instr(instr);
    data_update(data, lst_a, lst_b);
}

int     find_instr_code(const char *str, const t_instr_map *map)
{
    if (!map->name)
    {
        ft_errmsg("[find_instr_code] Error");
        return (-1);
    }
    if (!ft_strncmp(str, map->name, ft_strlen(map->name)))
        return (map->code);
    return find_instr_code(str, map + 1);
}

int     instr_to_i(char *str)
{
    static const t_instr_map instr_map[] = {
        {"sa", sa}, {"sb", sb}, {"ss", ss},
        {"ra", ra}, {"rb", rb}, {"rr", rr},
        {"rra", rra}, {"rrb", rrb}, {"rrr", rrr},
        {"pa", pa}, {"pb", pb}, {NULL, -1}
    };
    return find_instr_code(str, instr_map);
}

void    print_instr(int i, const t_instr_map *map)
{
    if (!map->name)
    {
        ft_errmsg("[i_to_instr]: instruction non reconnue\n");
        return;
    }
    if (map->code == i)
    {
        printf("%s\n", map->name);
        return;
    }
    print_instr(i, map + 1);
}

void    i_to_instr(int i)
{
    static const t_instr_map instr_map[] = {
        {"sa", sa}, {"sb", sb}, {"ss", ss},
        {"ra", ra}, {"rb", rb}, {"rr", rr},
        {"rra", rra}, {"rrb", rrb}, {"rrr", rrr},
        {"pa", pa}, {"pb", pb}, {NULL, -1}
    };
    print_instr(i, instr_map);
}
