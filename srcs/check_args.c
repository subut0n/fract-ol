/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:34:11 by addzikow          #+#    #+#             */
/*   Updated: 2021/08/09 15:56:21 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int check_args(int ac, char **av)
{
    if (ac != 2)
    {
        ft_putstr("ERROR : It should have 2 arguments.\n");
        return (1);
    }
    if (ft_strncmp(av[1],"mandelbrot", ft_strlen("mandelbrot")) 
        && ft_strncmp(av[1],"julia", ft_strlen("julia")))
    {
        ft_putstr("The argument is not valid : it should be 'mandelbrot' or 'julia'.");
        return (1);
    }
    return (0);
}