/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:12:35 by addzikow          #+#    #+#             */
/*   Updated: 2021/10/26 12:13:24 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		move(int keycode, t_fract *fract)
{
	if (keycode == 1)
		fract->y -= 0.1 / fract->zoom;
	if (keycode == 13)
		fract->y += 0.1 / fract->zoom;
	if (keycode == 2)
		fract->x -= 0.1 / fract->zoom;
	if (keycode == 0)
		fract->x += 0.1 / fract->zoom;
	if (keycode == 71)
	{
		if (fract->move == 0)
			fract->move = 1;
		else
			fract->move = 0;
		ft_putnbr(fract->move);
	}
	if (keycode == 18 || keycode == 19)
		change_reset(keycode, fract);
	else
		choose_fract(fract);
	mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	return (0);
}