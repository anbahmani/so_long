/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 21:36:35 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/28 11:21:58 by abahmani         ###   ########.fr       */
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

int		count_str(char const **tab);
void	print_error(char *msg);


#endif