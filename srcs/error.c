/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:37:58 by addzikow          #+#    #+#             */
/*   Updated: 2021/10/27 14:42:45 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	error_args(int ac, char **av)
{
	if (ac == 1)
	{
		ft_putstr("ERROR : Precise 'julia' or 'mandelbrot'.");
		return (1);
	}
	if (ac != 2 && ft_strcmp(av[1], "julia"))
	{
		ft_putstr("ERROR : it should have 2 arguments.\n");
		return (1);
	}
	if (ft_strcmp(av[1], "mandelbrot") && ft_strcmp(av[1], "julia"))
	{
		ft_putstr("ERROR : arg should be 'mandelbrot' or 'julia'.");
		return (1);
	}
	else if (ac != 4 && ac != 2)
	{
		ft_putstr("ERROR : Julia set start: ./fractol julia c_r c_i.");
		return (1);
	}
	return (0);
}
