
//the x_position of the wallhit
double	wall_x(t_raycaster *frame)
{
	double	wall_x;

	if (frame->ray.side == 0 || frame->ray.side == 1)
		wall_x = frame->pos_y + frame->ray.perp_wall_dist * frame->raydir_y;
	else
		wall_x = frame->pos_x + frame->ray.perp_wall_dist * frame->raydir_x;
	wall_x -= floor((wall_x));
	return (wall_x);
}

//x coordinate on the texture
int	    tex_x(t_raycaster *frame, mlx_texture_t *texture)
{
	int	tex_x;

	tex_x = (int)(get_wall_x(frame) * (double)texture->width);
	if ((frame->ray.side == 0 && frame->raydir_x > 0)
		|| (frame->ray.side == 1 && frame->raydir_y < 0))
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}
void    texture(t_data *data, int x, int draw_s, int draw_end)
{
	int				tex[2];
	int				line_h;
	double			step;
	double			tex_x;
	mlx_texture_t	*texture;

	texture = data->textures[data->window.frame.ray.side];
	tex[X] = tex_x(&data->window.frame, texture);
	line_h = draw_end - draw_start;
    // Starting texture coordinate
	tex_x = (draw_start - HEIGHT / 2 + line_h / 2) * step;
    // How much to increase the texture coordinate per screen pixel
	step = 1.0 * texture->height / line_h;
	while (draw_s < draw_end && data->window.enable)
	{
        // Cast the texture coordinate to integer, and mask with (texHeight - 1) in case of overflow
		tex[Y] = (int)tex_x & (texture->height - 1);
		tex_x += step;
		if (draw_s >= 0 && draw_s <= HEIGHT)
		{
            //make darker
			ft_memcpy(&data->window.window->pixels[
				((draw_s * data->window.window->width + x) * BPP)],
				&texture->pixels[((tex[Y]) * texture->height + (tex[X])) * BPP],
				BPP);
		}
		draw_start++;
	}
}

void    draw_ray(int x, t_data *data, t_raycaster *frame)
{
	int			line_h;
	int			draw_s;
	int			draw_end;
	int			i;
	t_window	*window;

	window = &data->window;
	line_h = 0;
    //calculate lowest and highest pixel to fill in current stripe
	if (frame->ray.perp_wall_dist > 0)
		line_h = (int)(HEIGHT / frame->ray.perp_wall_dist);
	draw_s = HEIGHT / 2 - line_h / 2;
	draw_end = line_h / 2 + HEIGHT / 2;
	if (draw_end >= HEIGHT)
		draw_end = HEIGHT - 1;
	texturize(data, x, draw_s, draw_end);
	i = -1;
	while (++i < HEIGHT && data->window.enable)
	{
		if (i < draw_s)
			mlx_put_pixel(window->window, x, i, window->c);
		if (i > draw_end)
			mlx_put_pixel(window->window, x, i, window->f);
	}
}
