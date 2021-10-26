/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:13:49 by addzikow          #+#    #+#             */
/*   Updated: 2021/10/26 12:14:28 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom(int button, int x, int y, t_fract *fract)
{
	if (button > 0)
	{
		fract->z_tmp = fract->z;
		fract->z = (fract->z_init / fract->zoom);
		fract->x += (fract->z_tmp - fract->z) / 2;
		fract->y += (fract->z_tmp - fract->z) / 2;
		fract->scale = fract->z / (fract->line_length / 4);
		x = x - (fract->line_length / 4) / 2;
		y = y - (fract->line_length / 4) / 2;
		fract->x += (x * (fract->z_tmp / (fract->line_length / 4))) - (x * fract->scale);
		fract->y += (y * (fract->z_tmp / (fract->line_length / 4))) - (y * fract->scale);
		fract->zoom_x = (fract->line_length / 4) / fract->z;
		fract->zoom_y = (fract->line_length / 4) / fract->z;
		choose_fract(fract);
		mlx_put_image_to_window(fract->mlx, fract->win, fract->image, 0, 0);
	}
}

int		zoom_set(int button, int x, int y, t_fract *fract)
{
	if (button == 1 || button == 4)
	{
		fract->zoom *= 1.1;
		if (fract->max < 250)
			fract->max += 1;
	}
	else if (button == 2 || button == 5)
	{
		fract->zoom /= 1.1;
		if (fract->max > 50)
			fract->max -= 1;
	}
	zoom(button, x, y, fract);
	return (0);
}
