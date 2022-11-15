void	free_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4) // 4 texures
	{
		free(data->txt_paths[i]);
		mlx_delete_texture(data->textures[i]);
		i++;
	}
}

void    free_map(char **ary)
{
    int i;

    i = 0;
    if(ary)
    {
		while (ary[i++])//array of the map del
		{
			free(arr[i]);
			ary[i] = NULL;
		}
		free(ary);
		ary = NULL;
	}
}

int exit_gg(t_data *data)
{
	free_textures(data); //4 tex
	free_map(data->free_map); //ary of map
	mlx_delete_image(data->window.mlx, data->window.window);
	mlx_close_window(data->window.mlx);
	mlx_terminate(data->window.mlx);
	return (EXIT_SUCCESS);
}