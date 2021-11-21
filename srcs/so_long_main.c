/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:09:17 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/21 16:43:31 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int ac, char **av)
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	struct s_img	img;

	map = check_error(ac, av);
	if (map == NULL)
		return (1);
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, (int)ft_strlen((char const *)map[0]) * 32,
			(int)count_str((char const **)map) * 32, "Hello world!");
	img.img = mlx_new_image(mlx, (int)ft_strlen((char const *)map[0]) * 32,
			(int)count_str((char const **)map) * 32);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
				&img.endian);
	for (int i = 0; i < (int)ft_strlen((char const *)map[0]) * 32; i++)
	{
		my_mlx_pixel_put(&img, i, 70, 140);	
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	free_tab(map);
	mlx_destroy_window(mlx, mlx_win);
	return (0);
}
