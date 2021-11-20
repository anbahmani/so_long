/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:09:17 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/08 16:20:08 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/so_long.h"

int main(int ac, char **av)
{
	char	**map;
	void	*mlx;
	void	*mlx_win;
	
	mlx = mlx_init();
	map = check_error(ac, av);
	if (map == NULL)
		return (1);
	free_tab(map);
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	return (0);
}