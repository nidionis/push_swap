#include <stdio.h>
#include "push_swap.h"

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

void    apply_instruction(char *instr, t_lst lst_a, t_lst lst_b)  
{
        if (*instr == 's')
               {
                        if (*(++instr) == 'a')
                                return 0;
                                
               }
}

int main(int argc, char *argv[])
{
        char    *buff;
        t_lst  *lst_a; 

        lst_a = get_args(argc, argv);
        print_lst(lst_a);
        swap_lst(lst_a);
        print_lst(lst_a);
        // while ((buff = get_next_line(0)) != NULL)
        // {
        //         apply_instruction(buff, lst_a, lst_b);
        // }
}
