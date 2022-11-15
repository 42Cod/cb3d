
// Here starts the actual raycasting. The raycasting loop is a for loop 
// that goes through every x,
// so there isn't a calculation for every pixel of the screen
//The ray starts at the position of the player (posX, posY).

//cameraX is the x-coordinate on the camera plane that the current x-coordinate
//of the screen represents, done this way so that the right side of the screen will
//get coordinate 1, the center of the screen gets coordinate 0, and the left side 
//of the screen gets coordinate -1. as the sum of the direction vector, and a 
//part of the plane vector. This has to be done both for the x and y coordinate of 
//the vector (since adding two vectors is adding their x-coordinates, and adding 
//their y-coordinates).

void    gameloop(int x, t_raycaster *frame)
{
    t_ray   *ray;

    //x-coordinate in camera space
    frame->camera_x = (double)(2 * x) / (double) WIDTH - 1;
    //initial direction vector
	//calculate ray position and direction
    frame->raydir_x = frame->dir_x + (frame->plane_x * frame->camera_x);
	frame->raydir_y = frame->dir_y + (frame->plane_y * frame->camera_x);
    ray = &frame->ray;
	//length of ray from one x or y-side to next x or y-side
    if (frame->raydir_x == 0)
		ray->delta_dist_x = INFINITY;
	else
		ray->delta_dist_x = fabs(1 / frame->raydir_x);
	if (frame->raydir_y == 0)
		ray->delta_dist_y = INFINITY;
	else
		ray->delta_dist_y = fabs(1 / frame->raydir_y);
	//which box of the map we're in
	ray->map_x = (int) frame->pos_x;
	ray->map_y = (int) frame->pos_y;
}

void    step_and_sidedist(t_raycaster *frame)
{
	t_ray	*ray;

	ray = &frame->ray;
	ray->hit = 0;
	ray->step_x = 1;
	 //length of ray from one x or y-side to next x or y-side
	ray->side_dist_x = (ray->map_x + 1.0 - frame->pos_x)
		* ray->delta_dist_x;
	if (frame->raydir_x < 0)
	{
		//what direction to step in x or y-direction (either +1 or -1)
		ray->step_x = -1;
		ray->side_dist_x = (frame->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	ray->step_y = 1;
	ray->side_dist_y = (ray->map_y + 1.0 - frame->pos_y) * ray->delta_dist_y;
	if (frame->raydir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (frame->pos_y - ray->map_y) * ray->delta_dist_y;
	}
}

// Now the actual DDA starts. It's a loop that increments the ray with 1 square 
// every time, until a wall is hit. Each time, either it jumps a square in the 
// x-direction (with stepX) or a square in the y-direction (with stepY), it always 
// jumps 1 square at once. If the ray's direction would be the x-direction, the loop 
// will only have to jump a square in the x-direction everytime, because the ray will 
// never change its y-direction. If the ray is a bit sloped to the y-direction, then 
// every so many jumps in the x-direction, the ray will have to jump one square in the
// y-direction. If the ray is exactly the y-direction, it never has to jump in the 
// x-direction, etc...

//sideDistX and sideDistY get incremented with deltaDistX with every jump in their 
//direction, and mapX and mapY get incremented with stepX and stepY respectively.
void	dda(char **map, t_raycaster *frame)
{
	t_ray	*ray;

	ray = &frame->ray;
 	//jump to next map square, either in x-direction, or in y-direction
	if (ray->side_dist_x < ray->side_dist_y)
	{
        ray->side_dist_x += ray->delta_dist_x;
		ray->map_x += ray->step_x;
		if (frame->raydir_x < 0)
			ray->side = NORTH;
		else
			ray->side = SOUTH;
	}
	else
	{
		ray->side_dist_y += ray->delta_dist_y;
		ray->map_y += ray->step_y;
		if (frame->raydir_y < 0)
			ray->side = WEST;
		else
			ray->side = EAST;
	}
    //Ray Wall Hit
	if (map[ray->map_x][ray->map_y] > '0')
		ray->hit = 1;
}


void	exec_dda(char **map, t_raycaster *frame)
{
    //Calculate distance projected
    //on camera direction (Euclidean distance would give fisheye effect!)
	t_ray	*ray;

	ray = &frame->ray;
	while (ray->hit == 0)
		dda_cases(map, frame);
	if (ray->side == NORTH || ray->side == SOUTH)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
}

void    raycaster(void *param)
{
	t_data		*data;
	t_ray	    *frame;
	int			x;

	data = (t_data *) param;
	frame = &data->window.frame;
	key_input(data);
	x = 0;
	while (x < WIDTH)
	{	
		gameloop(x, frame);
		step_and_sidedist(frame);
		dda(data->map, frame);
		draw_ray(x, data, frame);
		x++;
	}
}

void	init_win(t_data *data)
{
	t_window	*window;

	window = &data->window;
	window->enable = true;
	window->mlx = mlx_init(WIDTH, HEIGHT, "Cub3D!", false);
	data->txt_paths[0] = NULL;
	data->txt_paths[1] = NULL;
	data->txt_paths[2] = NULL;
	data->txt_paths[3] = NULL;
	if (!window->mlx)
		exit(-1);
	window->window = mlx_new_image(window->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(window->mlx, window->window, 0, 0);
}

void	closing(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->window.active = false;
}

void	ray_start(t_data *data)
{
	t_raycaster	*frame;

	frame = &data->window.frame;
	init_win(data);
	mlx_close_hook(data->window.mlx, &closing, data)
	while (data->window.active)
	{	
		mlx_loop_hook(data->window.mlx, &render, (data));
		mlx_loop(data->window.mlx);
	}
}