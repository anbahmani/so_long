/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 00:18:54 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/12 19:52:51 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

void	free_mlx(t_data *engine)
{
	free_tab(engine->map->map);
	if (engine->data->img.img)
		mlx_destroy_image(engine->data->mlx, engine->data->img.img);
	if (engine->data->mlx_win)
		mlx_destroy_window(engine->data->mlx, engine->data->mlx_win);
	mlx_destroy_display(engine->data->mlx);
	free(engine->data->mlx);
	exit(0);
}
