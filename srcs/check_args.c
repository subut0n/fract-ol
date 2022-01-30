/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:34:11 by addzikow          #+#    #+#             */
/*   Updated: 2021/10/27 15:47:03 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_arg_julia(t_fract *fract)
{
	fract->c_r_arg = 0;
	fract->c_i_arg = 0;
}

int	isasciianumber(char *ascii)
{
	int	i;
	int	nb_dot;

	i = 0;
	nb_dot = 0;
	while (ascii[i])
	{
		if (ascii[0] == '-')
			i++;
		if ((ascii[i] < '0' || ascii[i] > '9') && ascii[i] != '.')
			return (0);
		if (ascii[i] == '.')
			nb_dot += 1;
		if (nb_dot > 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av, t_fract *fract)
{
	int	error;

	error = error_args(ac, av);
	if (error == 1)
		return (1);
	init_arg_julia(fract);
	if (ac == 4)
	{
		if (!isasciianumber(av[2]) || !isasciianumber(av[3]))
		{
			ft_putstr("ERROR : julia args should be numbers.");
			return (1);
		}
		fract->c_r_arg = ft_atof(av[2]);
		fract->c_i_arg = ft_atof(av[3]);
	}
	return (0);
}

void	check_init(char *av, t_fract *fract)
{
	if (ft_strcmp(av, "mandelbrot") == 0)
		mandelbrot(fract);
	if (ft_strcmp(av, "julia") == 0)
		julia(fract);
}
