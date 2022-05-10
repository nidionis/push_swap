#include <libftprintf.h>

int get_args(int argc, char *argv[])
{
	while (--argc)
		ft_printf("%s\n", argv[argc]);
	return (0);
}

int main(int argc, char *argv[])
{
	get_args(argc, argv);
}
