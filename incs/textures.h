/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:59:14 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/04 18:57:52 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# define PLAYER_TEXTURE  "./textures/player.xpm"
# define FLOOR_TEXTURE  "./textures/floor.xpm"
# define EXIT_TEXTURE  "./textures/exit.xpm"
# define WALL_TEXTURE  "./textures/wall.xpm"
# define COLLECTIBLE_TEXTURE  "./textures/collectible/gold0.xpm"
# define WIDTH_TEXTURES 32
# define HEIGHT_TEXTURES 32

# include "so_long.h"

char	*get_path(char c);
int		open_img_xpm(char *texture_name, t_data *engine);

#endif