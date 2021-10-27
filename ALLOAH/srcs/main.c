/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:17:33 by addzikow          #+#    #+#             */
/*   Updated: 2021/10/27 14:51:35 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_graphics(t_fract *fract)
{
	fract->mlx = mlx_init();
	fract->win = mlx_new_window(fract->mlx, 500, 500, "Fract-ol");
	fract->image = mlx_new_image(fract->mlx, 500, 500);
	fract->img = mlx_get_data_addr(fract->image, &fract->bits_per_pixel,
			&fract->line_length, &fract->endian);
	fract->move = 0;
	fract->color = 12899750;
}

int	main(int ac, char **av)
{
	t_fract	fract;
	int		control;

	control = 0;
	control = check_args(ac, av, &fract);
	if (control == 1)
		exit(0);
	init_graphics(&fract);
	check_init(av[1], &fract);
	mlx_key_hook(fract.win, move, &fract);
	mlx_hook(fract.win, 2, 0, color, &fract);
	mlx_mouse_hook(fract.win, zoom_set, &fract);
	mlx_hook(fract.win, 6, 7, motion, &fract);
	mlx_hook(fract.win, 17, 0, exit_win, &fract);
	mlx_put_image_to_window(fract.mlx, fract.win, fract.image, 0, 0);
	mlx_loop(fract.mlx);
	return (0);
}
