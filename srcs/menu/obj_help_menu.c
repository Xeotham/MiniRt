/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_help_menu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhaouas <mhaouas@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:50:57 by mhaouas           #+#    #+#             */
/*   Updated: 2024/08/26 14:53:35 by mhaouas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

void	print_sphere_help_menu(void)
{
	printf("==========\n");
	printf("Keys:\n");
	printf("Sphere Mod:\n");
	printf("\t- ←: Decrease selected value.\n");
	printf("\t- →: Increase selected value.\n");
	printf("\t- Hold Z: Select Z Axis modification.\n");
	printf("\t- Hold X: Select X Axis modification.\n");
	printf("\t- Hold C: Select Y Axis modification.\n");
	printf("\t- Hold R: Select radius modification.\n");
	printf("\t- Hold 1: Select Red modification.\n");
	printf("\t- Hold 2: Select Green modification.\n");
	printf("\t- Hold 3: Select Blue modification.\n");
	printf("\nMods:\n");
	printf("\t- L: Unable/Disable Light Mod.\n");
	printf("\t- O: Unable/Disable Object Mod.\n");
	printf("\t- <: Switch to previous object.\n");
	printf("\t- >: Switch to next object.\n");
	printf("\t- Enter: Render the scene\n");
}

void	print_plane_help_menu(void)
{
	printf("==========\n");
	printf("Keys:\n");
	printf("Plane Mod:\n");
	printf("\t- M: Switch to coord/normal modification.\n");
	printf("\t- ←: Decrease selected value.\n");
	printf("\t- →: Increase selected value.\n");
	printf("\t- Hold Z: Select Z Axis modification.\n");
	printf("\t- Hold X: Select X Axis modification.\n");
	printf("\t- Hold C: Select Y Axis modification.\n");
	printf("\t- Hold 1: Select Red modification.\n");
	printf("\t- Hold 2: Select Green modification.\n");
	printf("\t- Hold 3: Select Blue modification.\n");
	printf("\nMods:\n");
	printf("\t- L: Unable/Disable Light Mod.\n");
	printf("\t- O: Unable/Disable Object Mod.\n");
	printf("\t- <: Switch to previous object.\n");
	printf("\t- >: Switch to next object.\n");
	printf("\t- Enter: Render the scene\n");
}

void	print_cylinder_help_menu(void)
{
	printf("==========\n");
	printf("Keys:\n");
	printf("Cylinder Mod:\n");
	printf("\t- M: Switch to coord/normal modification.\n");
	printf("\t- ←: Decrease selected value.\n");
	printf("\t- →: Increase selected value.\n");
	printf("\t- Hold Z: Select Z Axis modification.\n");
	printf("\t- Hold X: Select X Axis modification.\n");
	printf("\t- Hold C: Select Y Axis modification.\n");
	printf("\t- Hold R: Select radius modification.\n");
	printf("\t- Hold H: Select height modification.\n");
	printf("\t- Hold 1: Select Red modification.\n");
	printf("\t- Hold 2: Select Green modification.\n");
	printf("\t- Hold 3: Select Blue modification.\n");
	printf("\nMods:\n");
	printf("\t- L: Unable/Disable Light Mod.\n");
	printf("\t- O: Unable/Disable Object Mod.\n");
	printf("\t- <: Switch to previous object.\n");
	printf("\t- >: Switch to next object.\n");
	printf("\t- Enter: Render the scene\n");
}
