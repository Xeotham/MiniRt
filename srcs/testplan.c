#include "minirt.h"
#include <stdio.h>
#include <math.h>

t_matrix	set_matrix(t_vector3 axis, double angle)
{
	t_matrix	new;
	double		c = cos(angle);
	double		s = sin(angle);
	double		C = 1 - c;

	new = create_matrix(4, 4);
	if (!new)
		exit (1);
	identity_matrix(new);
	new[0][0] = axis.x * axis.x * C + c;
	new[0][1] = axis.x * axis.y * C - axis.z * s;
	new[0][2] = axis.x * axis.z * C + axis.y * s;
	new[1][0] = axis.y * axis.x * C + axis.z * s;
	new[1][1] = axis.y * axis.y * C + c;
	new[1][2] = axis.y * axis.z * C - axis.x * s;
	new[2][0] = axis.z * axis.x * C - axis.y * s;
	new[2][1] = axis.z * axis.y * C + axis.x * s;
	new[2][2] = axis.z * axis.z * C + c;
	return (new);
}

int	main(int argc, char **argv)
{
	if (argc != 4)
		return (1);
	t_vector3 plan = normalize_vector(set_vector(ft_atod(argv[1]), ft_atod(argv[2]), ft_atod(argv[3])));
	printf("Vector normalized: Px = %lf Py = %lf Pz = %lf\n", plan.x, plan.y, plan.z);
	t_vector3 z_axis = set_vector(0,0,1);
	double dot = dot_product(plan, z_axis);
	printf("dot_product: %lf\n", dot);
	double angle = acos(dot);
	printf("angle: %lf\n", angle);
	t_vector3 axis = normalize_vector(cross_product(plan, z_axis));
	printf("Axis: Ax = %lf Ay = %lf Az = %lf\n", axis.x, axis.y, axis.z);
	t_matrix rotation_m = set_matrix(axis, angle);
	t_vector3 new = matrix_to_vector(mat_vec_product(rotation_m, plan));
	printf("Checking\n%lf should be equal to %lf\n%lf should be equal to %lf\n%lf should be equal to %lf\n", new.x, z_axis.x, new.y, z_axis.y, new.z, z_axis.z);
	return (0);
}
