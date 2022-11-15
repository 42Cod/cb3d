bool    move_player(float m_dir_x, float m_dir_y, t_data *data)
{
	t_raycaster		*frame;
	char			**map;
    char            **map;
    int             i;

	frame = &data->window.frame;
    i = 1;
	map = data->map;
    while(i < 5)
    {   
        if ((map[(int)(frame->pos_x + move_dir_x * i * MOVE_SPEED)] //ccheck wall
                [(int)frame->pos_y] != '1')
                || (map[(int)(frame->pos_x)]
                [(int)(frame->pos_y + move_dir_y * i * MOVE_SPEED)] != '1'))
        {
            frame->pos_x += move_dir_x * MOVE_SPEED; //move Player
            frame->pos_y += move_dir_y * MOVE_SPEED;
        }
        i++;
    }
}

void	move(t_data *data)
{
	float		dir_x;
	float		dir_y;
	mlx_t		*mlx;
	double		rot_speed;
	t_raycaster	*frame;

	mlx = data->window.mlx;
	dir_x = data->window.frame.dir_x;
	dir_y = data->window.frame.dir_y;
	frame = &data->window.frame;
	if (mlx_is_key_down(mlx, KEY_D))
		move_player(dir_y, -dir_x, data);
	if (mlx_is_key_down(mlx, KEY_A))
		move_player(-dir_y, dir_x, data);
	if (mlx_is_key_down(mlx, KEY_S))
		move_player(-dir_x, -dir_y, data);
	if (mlx_is_key_down(mlx, KEY_W))
		move_player(dir_x, dir_y, data);
}

void	rotate(t_data *data)
{
	t_window	*window;
	t_raycaster	*frame;
	double		rot_speed;

	window = &data->window;
	frame = &window->frame;
	if (mlx_is_key_down(window->mlx, KEY_RIGHT)) //rotation speed set to positive
		rot_speed = 0.05;
	else if (mlx_is_key_down(window->mlx, KEY_LEFT))
		rot_speed = -0.05;
	else
		return ;
    //both camera direction and camera plane must be rotated
	frame->olddir_x = frame->dir_x;
	frame->dir_x = frame->dir_x
		* cos(-rot_speed) - frame->dir_y * sin(-rot_speed);
	frame->dir_y = frame->olddir_x
		* sin(-rot_speed) + frame->dir_y * cos(-rot_speed);
	frame->oldplane_x = frame->plane_x;
	frame->plane_x = frame->plane_x
		* cos(-rot_speed) - frame->plane_y * sin(-rot_speed);
	frame->plane_y = frame->oldplane_x
		* sin(-rot_speed) + frame->plane_y * cos(-rot_speed);
}
