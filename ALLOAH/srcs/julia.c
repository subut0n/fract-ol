/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:43:24 by addzikow          #+#    #+#             */
/*   Updated: 2021/10/27 14:47:48 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	julia(t_fract *fract)
{
	init_julia_values(fract);
	if (fract->c_r_arg != 0 || fract->c_i_arg != 0)
	{
		fract->c_r = fract->c_r_arg;
		fract->c_i = fract->c_i_arg;
	}
	printf("value c_r = %f\n", fract->c_r);
	printf("value c_i = %f\n", fract->c_i);
	draw_jul(fract);
}

void	init_julia_values(t_fract *fract)
{
	fract->x = -1.1;
	fract->y = -1.1;
	fract->z = 2.2;
	fract->z_init = 2.2;
	fract->max = 50;
	fract->zoom = 1;
	fract->image_x = 500;
	fract->image_y = 500;
	fract->zoom_x = fract->image_x / fract->z;
	fract->zoom_y = fract->image_y / fract->z;
	fract->c_r = -0.4;
	fract->c_i = 0.6;
	fract->fract = 2;
}

void	draw_pixel_jul(t_fract *fract)
{
	if (fract->i == fract->max)
		pixel_to_img(fract, 0xFFFFFF);
	else
		pixel_to_img(fract, fract->i * fract->color);
}

void	draw_jul(t_fract *fract)
{
	fract->xindex = 0;
	while (fract->xindex < fract->image_x)
	{
		fract->yindex = 0;
		while (fract->yindex < fract->image_y)
		{
			fract->z_r = fract->xindex / fract->zoom_x + fract->x;
			fract->z_i = fract->yindex / fract->zoom_y + fract->y;
			fract->i = 0;
			while (fract->z_r * fract->z_r + fract->z_i * fract->z_i < 4
				&& fract->i < fract->max)
			{
				fract->temp = fract->z_r;
				fract->z_r = fract->z_r
					* fract->z_r - fract->z_i * fract->z_i + fract->c_r;
				fract->z_i = 2 * fract->z_i * fract->temp + fract->c_i;
				fract->i++;
				draw_pixel_jul(fract);
			}
			fract->yindex++;
		}
		fract->xindex++;
	}
}
