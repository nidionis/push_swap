#include "push_swap.h"

/*
int main(int argc, char *argv[])
{
	char	*line;
	int		ii;
	t_lst	*lst_a;
	t_lst	*lst_b;

	line = malloc(5);
	lst_a = get_args(argc, argv);
	lst_b = new_lst();
	ii = 0;
	while (ii < 5)
		line[ii++] = 0;
	line = get_next_line(line);
	while (line)
	{
		printf("[bonus main] : line %s,\taddr: %p\n", line, line);
		apply_instruction(line, lst_a, lst_b);
		print_lst(lst_a, lst_b);
		line = get_next_line(line);
	}
}
*/
