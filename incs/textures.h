/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:59:14 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/02 00:14:22 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# define PLAYER_TEXTURE  "./textures/player.xpm"
# define FLOOR_TEXTURE  "./textures/floor.xpm"
# define EXIT_TEXTURE  "./textures/exit.xpm"
# define WALL_TEXTURE  "./textures/wall.xpm"
# define COLLECTIBLE_TEXTURE  "./textures/collectible/Gold0.xpm"
# define WIDTH_TEXTURES 32
# define HEIGHT_TEXTURES 32

# include "so_long.h"

char	*get_path(char c);

#endif