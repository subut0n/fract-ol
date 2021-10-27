/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 13:13:59 by addzikow          #+#    #+#             */
/*   Updated: 2021/10/27 15:07:23 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>
# include <pthread.h>
# include <stdio.h>

typedef struct s_fract
{
	double	x;
	double	y;
	double	z;
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	double	z_init;
	double	z_tmp;
	int		max;
	int		i;
	double	zoom;
	double	zoom_y;
	double	zoom_x;
	double	image_x;
	double	image_y;
	char	*img;
	double	c_r;
	double	c_i;
	double	c_r_arg;
	double	c_i_arg;
	double	z_r;
	double	z_i;
	double	temp;
	void	*mlx;
	void	*win;
	void	*image;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		color;
	int		fract;
	int		move;
	int		xindex;
	int		yindex;
	double	scale;
}					t_fract;

int		check_args(int ac, char **av, t_fract *fract);
void	check_init(char *arg, t_fract *fract);

void	choose_fract(t_fract *fract);
void	change_reset(int keycode, t_fract *fract);
int		exit_win(void);

int		move(int keycode, t_fract *fract);
int		color(int keycode, t_fract *fract);
int		zoom_set(int button, int x, int y, t_fract *fract);
void	zoom(int button, int x, int y, t_fract *fract);
int		motion(int x, int y, t_fract *fract);

void	init_graphics(t_fract *fract);

void	pixel_to_img(t_fract *fract, int color);
void	pix_color(t_fract *fract);

void	mandelbrot(t_fract *fract);
void	init_mandelbrot_values(t_fract *fract);
void	draw_mand(t_fract *fract);

void	init_julia_values(t_fract *fract);
void	julia(t_fract *fract);
void	draw_pixel_jul(t_fract *fract);
void	draw_jul(t_fract *fract);

int		error_args(int ac, char **av);

#endif