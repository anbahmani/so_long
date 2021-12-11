/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:27:11 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/06 10:27:55 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

int	finish(t_bonus *bonus, char c)
{
	if (c == 'E')
		printf("Bravo ! Vous avez gagne !\n");
	else if (c == 'M')
		printf("Dommage ... Vous avez perdu.\n");
	return (end_game_bonus(bonus));
}
