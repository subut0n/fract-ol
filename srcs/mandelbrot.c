/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:57:32 by addzikow          #+#    #+#             */
/*   Updated: 2021/10/27 14:52:15 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	mandelbrot(t_fract *fract)
{
	init_mandelbrot_values(fract);
	draw_mand(fract);
}

void	init_mandelbrot_values(t_fract *fract)
{
	fract->x = -2;
	fract->y = -1.35;
	fract->z = 2.8;
	fract->z_init = 2.8;
	fract->image_x = 500;
	fract->image_y = 500;
	fract->max = 50;
	fract->zoom = 1;
	fract->zoom_x = fract->image_x / fract->z;
	fract->zoom_y = fract->image_y / fract->z;
	fract->fract = 1;
}

void	draw_mand(t_fract *fract)
{
	fract->xindex = 0;
	while (fract->xindex < fract->line_length / 4)
	{
		fract->yindex = 0;
		while (fract->yindex < fract->line_length / 4)
		{
			fract->c_r = fract->xindex / fract->zoom_x + fract->x;
			fract->c_i = fract->yindex / fract->zoom_y + fract->y;
			fract->z_r = 0;
			fract->z_i = 0;
			fract->i = 0;
			while (fract->z_r * fract->z_r + fract->z_i
				* fract->z_i < 4 && fract->i < fract->max)
			{
				fract->temp = fract->z_r;
				fract->z_r = fract->z_r * fract->z_r
					- fract->z_i * fract->z_i + fract->c_r;
				fract->z_i = 2 * fract->z_i * fract->temp + fract->c_i;
				fract->i++;
				pix_color(fract);
			}
			fract->yindex++;
		}
		fract->xindex++;
	}
}
