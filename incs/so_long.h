/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 21:36:35 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/01 12:06:45 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"
# include "../minilibx-macos/mlx.h"
# include "../minilibx-linux/mlx.h"
# include "get_map.h"
# include "free.h"
# include "check_error.h"
# include "ihm.h" 
# include "img.h"
# include "textures.h"
# include "event.h"

# ifdef __APPLE__
#  define OS 'm'
# elif __linux__
#  define OS 'l'
# endif


int		count_str(char const **tab);
void	print_error(char *msg);
void	end_game(t_data *engine);

#endif