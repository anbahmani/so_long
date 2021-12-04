/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:59:46 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/04 19:50:58 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# define MONSTER_TEXTURE  "./textures/monster.xpm"
# define GOLD0_TEXTURE  "./textures/gold0.xpm"
# define GOLD1_TEXTURE  "./textures/gold1.xpm"
# define GOLD2_TEXTURE  "./textures/gold2.xpm"
# define GOLD3_TEXTURE  "./textures/gold3.xpm"
# define GOLD4_TEXTURE  "./textures/gold4.xpm"
# define GOLD5_TEXTURE  "./textures/gold5.xpm"
# define GOLD6_TEXTURE  "./textures/gold6.xpm"
# define GOLD7_TEXTURE  "./textures/gold7.xpm"

#include "so_long.h"

typedef struct s_gold
{
	char	**tab;
	int		curr;
}	t_gold;

typedef struct	s_bonus
{
	t_data	*engine;
	t_gold	gold;
}	t_bonus;

void	end_game_bonus(t_data *engine,t_gold gold);

#endif