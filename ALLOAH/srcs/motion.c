/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:16:55 by addzikow          #+#    #+#             */
/*   Updated: 2021/10/26 12:17:10 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int		motion(int x, int y, t_fract *fract)
{
	if (fract->fract == 2 && fract->move == 1)
	{
		if (x >= 0 && x <= 250)
			fract->c_i = ((double)x - 250) / 250;
		if (x <= 500 && x >= 250)
			fract->c_i = ((double)x - 250) / 250;
		if (y >= 0 && y <= 250)
			fract->c_r = -((double)y - 250) / 250;
		if (y <= 500 && y >= 250)
			fract->c_r = -((double)y - 250) / 250;
		if (fract->fract == 2)
			draw_jul(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	}
	return (0);
}