/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:42:35 by addzikow          #+#    #+#             */
/*   Updated: 2021/10/21 16:57:12 by addzikow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	on_key_hooked(t_hooks *hooks, int key, bool pressed)
{
    // printf("key: %d\n", key);
    if (key == SCROLL_UP)
        hooks->scroll_up = pressed;
    else if (key == SCROLL_DOWN)
        hooks->scroll_down = pressed;
}

int	on_key_pressed(int key, t_visualizer *visualizer)
{
    on_key_hooked(visualizer->hooks, key, true);
	printf("pressed");
	return (true);
}

int	on_key_released(int key, t_visualizer *visualizer)
{
    on_key_hooked(visualizer->hooks, key, false);
	printf("released");
	return (true);
}

void		register_keys_hooks(t_visualizer *visualizer)
{
    printf("%d\n", visualizer->hooks->scroll_up);
	mlx_hook(visualizer->window, 2, 1L<<0, on_key_pressed, visualizer);
	mlx_hook(visualizer->window, 3, 1L<<1, on_key_released, visualizer);
    mlx_hook(visualizer->window, 5, 1L<<2, on_key_pressed, visualizer);
}