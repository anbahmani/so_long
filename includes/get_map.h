/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:18:03 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/05 20:21:00 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_MAP_H
# define GET_MAP_H

# include "so_long.h"

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_map_data
{
	char	**map;
	int		width;
	int		height;
	t_pos	player;
}	t_map_data;

int		get_next_line(int fd, char **line);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len, int f);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	**file_to_tab(char const *file_name);
int		get_player_position(t_map_data *map);

#endif