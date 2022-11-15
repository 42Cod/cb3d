#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <math.h>	
# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>

enum e_direction {
	NORTH,
	SOUTH,
	EAST,
	WEST
};

# define WIDTH 1280
# define HEIGHT 768
# define MOVE_SPEED 0.05
# define X 0
# define Y 1
# define BPP 4

typedef struct s_color
{
	int	red;
	int	green;
	int	blue;
}	t_color;

typedef struct s_ray
{
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
}	t_ray;

typedef struct s_raycaster
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	olddir_x;
	double	olddir_y;
	double	plane_x;
	double	oldplane_x;
	double	plane_y;
	double	oldplane_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	t_ray	ray;
}	t_raycaster;

typedef struct s_window
{
	bool		active;
	void		*mlx;
	mlx_image_t	*window;
	t_raycaster	frame;
	int			c;
	int			f;
}	t_window;

typedef struct s_data
{
	char			**free_map;
	char			**map;
	char			**env;
	char			*pwd;
	char			*txt_paths[4];
	mlx_texture_t	*textures[4];
	t_window		window;
}				t_data;

// WINDOW AND MLX
void	init_window(t_data *data);
void	key_input(t_data *data);
void	render(void *param);

//RAY CASTING AND PLAYER MOVEMENT
void	raycaster(t_data *data);
void	move(t_data *data);
void	rotate(t_data *data);

//draw
bool	load_texture(t_data *data);
void	draw_ray(int x, t_data *data, t_raycaster *frame);

#endif