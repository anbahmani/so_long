/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_map_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 22:07:55 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/06 18:52:21 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static int	check_authorized_char(char **tab)
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
				&& tab[i][j] != 'C' && tab[i][j] != 'M')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_map_is_rectangle(char **tab)
{
	int	width;
	int	i;

	if (tab == NULL || tab[0] == NULL)
		return (0);
	width = (int)ft_strlen(tab[0]);
	if (width < 3)
		return (0);
	i = 1;
	while (tab[i] != NULL)
	{
		if (width != (int)ft_strlen(tab[i]))
			return (0);
		i++;
	}
	return (i >= 3);
}

static int	check_border_char(char **tab)
{
	int	i;
	int	j;

	if (count_str((char const **)tab) < 3)
		return (0);
	i = 0;
	while (tab[0][i])
	{
		if (tab[0][i] != '1')
			return (0);
	}
	i = 1;
	while (tab[i + 1] != NULL)
	{
		if (tab[i][0] != '1' || tab[i][ft_strlen(tab[i] - 1)] != '1')
			return (0);
	}
	j = 0;
	if (tab[i][j])
	{
		if (tab[i][j] != '1')
			return (0);
	}
	return (1);
}

int	check_map(char **tab)
{
	if (!check_map_is_rectangle(tab) || check_authorized_char(tab)
		|| !check_border_char(tab))
		return (0);
	return (1);
}
