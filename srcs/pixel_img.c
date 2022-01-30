/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_img.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 14:06:40 by addzikow          #+#    #+#             */
/*   Updated: 2021/10/27 14:57:38 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	pixel_to_img(t_fract *fract, int color)
{
	int		i;

	i = (4 * fract->xindex) + (fract->yindex * fract->line_length);
	if (fract->xindex >= 0 && fract->yindex >= 0
		&& fract->xindex < fract->line_length / 4 && fract->yindex
		< fract->line_length / 4)
	{
		fract->img[i] = color;
		fract->img[i + 1] = color >> 8;
		fract->img[i + 2] = color >> 16;
	}
}

void	pix_color(t_fract *fract)
{
	if (fract->i == fract->max)
		pixel_to_img(fract, 0x000000);
	else
		pixel_to_img(fract, fract->i * fract->color);
}
/* permet de transmettre les pixels a l'image 
avant d'afficher l'image sur la fenetre
en effectuant les changements de couleurs 
pour differentes iterations. */