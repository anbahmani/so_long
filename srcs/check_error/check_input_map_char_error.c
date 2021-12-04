/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_map_char_error.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 16:50:49 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/04 18:34:46 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static int	check_number_player(char **tab)
{
	int	nb_p;
	int	i;
	int	j;

	nb_p = 0;
	i = 1;
	while (tab[i] != NULL)
	{
		j = 1;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P')
				nb_p++;
			j++;
		}
		i++;
	}
	return (nb_p == 1);
}

static int	check_number_collectible(char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i] != NULL)
	{
		j = 1;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_number_exit(char **tab)
{
	int	i;
	int	j;

	i = 1;
	while (tab[i] != NULL)
	{
		j = 1;
		while (tab[i][j])
		{
			if (tab[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_number_char(char **tab)
{
	if (!check_number_player(tab))
	{
		print_error("Le nombre de joueur dans la map est invalide.");
		return (0);
	}
	if (!check_number_collectible(tab))
	{
		print_error("Le nombre de colectible dans la map est invalide.");
		return (0);
	}
	if (!check_number_exit(tab))
	{
		print_error("Le nombre de sortie dans la map est invalide.");
		return (0);
	}
	return (1);
}
