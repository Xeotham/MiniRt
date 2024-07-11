#include <stdio.h>
#include <libft.h>
#include <stdbool.h>

double	double_abs(double nb)
{
	if (nb < 0)
		return (nb * -1);
	return (nb);
}

bool	doubles_are_equals(double a, double b)
{
	if (double_abs(a - b) < double_abs(b / 1000))
		return (true);
	return (false);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		return (1);
	double	a = ft_atod(argv[1]);
	double	b = ft_atod(argv[2]);
	double c = double_abs(a - b);
	double d = double_abs(b / 1000);
	printf("a: %lf b: %lf\n a - b: %lf b / 1000: %lf\n", a, b, c, d);
	if (doubles_are_equals(a, b))
		printf("equal\n");
	else
		printf("inequal\n");
}
