/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:59:46 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/11 14:39:26 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# define MONSTER_TEXTURE  "./textures/monster.xpm"
# define GOLD0_TEXTURE  "./textures/collectible/gold0.xpm"
# define GOLD1_TEXTURE  "./textures/collectible/gold1.xpm"
# define GOLD2_TEXTURE  "./textures/collectible/gold2.xpm"
# define GOLD3_TEXTURE  "./textures/collectible/gold3.xpm"
# define GOLD4_TEXTURE  "./textures/collectible/gold4.xpm"
# define GOLD5_TEXTURE  "./textures/collectible/gold5.xpm"
# define GOLD6_TEXTURE  "./textures/collectible/gold6.xpm"
# define GOLD7_TEXTURE  "./textures/collectible/gold7.xpm"

#include "so_long.h"
#include <math.h>


# define VITESSE 300

typedef struct s_gold
{
	char	**tab;
	int		curr;
}	t_gold;

typedef struct	s_bonus
{
	t_data	*engine;
	t_gold	gold;
	int		nb_monsters;
}	t_bonus;

int		end_game_bonus(t_bonus *bonus);
int		finish(t_bonus *bonus, char c);
int		move_bonus(t_bonus *bonus, int pos_x, int pos_y);
void	catch_event_bonus(t_bonus *bonus);
int		check_authorized_char_bonus(char **tab);
void	check_text_file_error_bonus(t_data *engine);
char	*get_path_bonus(char c);
double	range(int x1, int y1, int x2, int y2);
t_pos	*get_monsters_pos(t_bonus	*bonus);
int		count_monsters(char **map);
void	monster_movement(t_bonus *bonus);
int		is_player_space(char **map, int x, int y);

#endif