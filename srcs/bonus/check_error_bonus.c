/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 18:46:39 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/04 18:52:08 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

void	check_text_file_error_bonus(t_data *engine)
{
	check_text_file_error(engine);
	if (!open_img_xpm(MONSTER_TEXTURE, engine)
		|| !open_img_xpm(GOLD0_TEXTURE, engine)
		|| !open_img_xpm(GOLD1_TEXTURE, engine)
		|| !open_img_xpm(GOLD2_TEXTURE, engine)
		|| !open_img_xpm(GOLD3_TEXTURE, engine)
		|| !open_img_xpm(GOLD4_TEXTURE, engine)
		|| !open_img_xpm(GOLD5_TEXTURE, engine)
		|| !open_img_xpm(GOLD6_TEXTURE, engine)
		|| !open_img_xpm(GOLD7_TEXTURE, engine))
	{
		end_game(engine);
	}
}

int	check_authorized_char_bonus(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i] != NULL)
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] != '1' && tab[i][j] != '0' && tab[i][j] != 'P'
				&& tab[i][j] != 'C' && tab[i][j] != 'E' && tab[i][j] != 'M')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
