/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:23:52 by addzikow          #+#    #+#             */
/*   Updated: 2021/10/21 15:37:01 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int render_visualizer(t_visualizer *visualizer)
{
    float zoom_x;
    float zoom_y;
    int x;
    int y;
    float c_r;
    float c_i;
    float z_r;
    float z_i;
    float tmp;
    int i;
    
    //define fractal
    visualizer->coord.x0 = -2.1;
    visualizer->coord.x1 = 0.6;
    visualizer->coord.y0 = -1.2;
    visualizer->coord.y1 = 1.2;


    //init zoom
    zoom_x = visualizer->resolution.x_res / (visualizer->coord.x1 - visualizer->coord.x0);
    zoom_y = visualizer->resolution.y_res / (visualizer->coord.y1 - visualizer->coord.y0);

    x = 0;
    while (x < visualizer->resolution.x_res)
    {
        y = 0;
        while (y < visualizer->resolution.y_res)
        {
            //init z_value c_value iteration
            c_r = x / zoom_x + visualizer->coord.x0;
            c_i = y / zoom_y + visualizer->coord.y0;
            z_r = 0;
            z_i = 0;
            i = 0;
            while ( (z_r * z_r - z_i * z_i < 4) && i < visualizer->i_max )
            {
                tmp = z_r;
                z_r = z_r * z_r - z_i * z_i + c_r;
                z_i = 2 * z_i * tmp + c_i;
                i = i + 1;
            }
            if (i == visualizer->i_max)
                my_mlx_pixel_put(visualizer->data, x, y, 0x0000000);
            else
                my_mlx_pixel_put(visualizer->data, x, y, 0x00FFFFFF);
            y++;
        }
        x++;
    }
    mlx_put_image_to_window(visualizer->mlx, visualizer->window, visualizer->data->img, 0, 0);
    return (0);
}

int main(int argc, char *argv[])
{
    t_visualizer *visualizer;


    visualizer = malloc(sizeof(t_visualizer));
    visualizer->data = malloc(sizeof(t_data));
    visualizer->hooks = malloc(sizeof(t_hooks));

    check_args(argc, argv);

    //init res
    visualizer->resolution.x_res = 1000;
    visualizer->resolution.y_res = 1000;
    visualizer->set = argv[1];
    visualizer->i_max = 100;

    visualizer->mlx = mlx_init();
    visualizer->window = mlx_new_window(visualizer->mlx, visualizer->resolution.x_res, visualizer->resolution.y_res, "My Window");
    visualizer->data->img = mlx_new_image(visualizer->mlx, visualizer->resolution.x_res, visualizer->resolution.y_res);
    visualizer->data->addr = mlx_get_data_addr(visualizer->data->img, &visualizer->data->bits_per_pixel, &visualizer->data->line_length, &visualizer->data->endian);
    register_keys_hooks(visualizer);
    mlx_loop_hook(visualizer->mlx, render_visualizer, visualizer);
    mlx_loop(visualizer->mlx);    
    return (0);
}