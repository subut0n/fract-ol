#ifndef _FRACTOL_H_
# define _FRACTOL_H_

# include "mlx.h"
# include <stdio.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define SCROLL_UP 5
# define SCROLL_DOWN 4

/*
** Data (image)
*/

/*
** img            — image identifier
** data_addr      — image
** bits_per_pixel — depth of image
** line_length    — number of bytes used to store one line of image
** endian         — little or big endian
*/

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_hooks {
	bool scroll_up;
	bool scroll_down;
}				t_hooks;

typedef struct	s_resolution
{
	int x_res;
	int y_res;
}				t_resolution;

typedef struct s_coordinates
{
	float x0;
	float x1;
	float y0;
	float y1;
}				t_coordinates;

/*
** Visualizer
*/

/*
** mlx            - connection identifier
** window         - window identifier
** data			  - image data
** resolution	  - window resolution
** coord		  -
*/

typedef struct s_visualizer
{
	void		*mlx;
	void		*window;
	t_data 			*data;
	t_hooks 		*hooks;
	t_resolution	resolution;
	t_coordinates	coord;
	int				i_max;
	char 			*set;
}				t_visualizer;

int check_args(int ac, char **av);
void		register_keys_hooks(t_visualizer *visualizer);

#endif