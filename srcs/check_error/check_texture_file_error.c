/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_file_error.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:33:44 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/12 19:52:51 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_img_xpm(char *texture_name, t_data *engine)
{
	void	*tmp;
	int		width;
	int		height;
	char	*msg;

	tmp = mlx_xpm_file_to_image(engine->data->mlx, texture_name,
			&height, &width);
	if (!tmp || width != WIDTH_TEXTURES || height != HEIGHT_TEXTURES)
	{
		if (!tmp)
			msg = ft_strjoin("Le fichier texture est errone : ",
					texture_name);
		else
			msg = ft_strjoin("La taille de la texture n'est pas bonne : ",
					texture_name);
		print_error(msg);
		free(msg);
		return (0);
	}
	mlx_destroy_image(engine->data->mlx, tmp);
	return (1);
}

void	check_text_file_error(t_data *engine)
{
	if (!open_img_xpm(WALL_TEXTURE, engine)
		|| !open_img_xpm(FLOOR_TEXTURE, engine)
		|| !open_img_xpm(PLAYER_TEXTURE, engine)
		|| !open_img_xpm(COLLECTIBLE_TEXTURE, engine)
		|| !open_img_xpm(EXIT_TEXTURE, engine))
	{
		end_game(engine);
	}
}
