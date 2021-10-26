/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 12:17:34 by addzikow          #+#    #+#             */
/*   Updated: 2021/10/26 12:19:30 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	choose_fract(t_fract *fract)
{
	if (fract->fract == 1)
		draw_mand(fract);
	if (fract->fract == 2)
		draw_jul(fract);
}

void	change_reset(int keycode, t_fract *fract)
{
	if (keycode == 18)
		mandelbrot(fract);
	if (keycode == 19)
		julia(fract);
}

int		exit_win(void)
{
	exit(0);
}