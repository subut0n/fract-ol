/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:15:52 by addzikow          #+#    #+#             */
/*   Updated: 2021/10/27 14:43:13 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	color(int keycode, t_fract *fract)
{
	if (keycode == 69)
	{
		ft_bzero(fract->img, (500 * 500) * 4);
		fract->color += 1000;
		choose_fract(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	}
	else if (keycode == 78)
	{
		ft_bzero(fract->img, (500 * 500) * 4);
		fract->color -= 1000;
		choose_fract(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	}
	else if (keycode == 53)
		exit(0);
	return (0);
}
// permet de modifier les jeux de couleurs des fractales avec [-] et [+]