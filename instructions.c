#include "push_swap.h"

void    p(char action, t_lst *lst_a, t_lst *lst_b)
{
    t_lnk   *tmp;

    if (action == 'a' || 'A')
        push_item(pop(lst_a), lst_b);
    else if (action == 'b' || 'B')
        push_item(pop(lst_b), lst_a);
    else
        error_msg("error in push function\n");
    if (action > 96) // si action est minuscule, imprimer 
    {
        write(1, "p", 1);
        write(1, &action, 1);
        write(1, "\n", 1);
    }
}
