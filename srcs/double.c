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
	if (double_abs(a - b) <= double_abs(b / 1000))
		return (true);
	return (false);
}
