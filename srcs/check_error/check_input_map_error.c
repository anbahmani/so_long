/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_map_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 22:07:55 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/04 19:06:42 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

int	check_authorized_char(char **tab)
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
				&& tab[i][j] != 'C' && tab[i][j] != 'E')
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

static char	last_char(char *str)
{
	int	i;

	i = 0;
	while (str[i + 1])
		i++;
	return (str[i]);
}

static int	check_border_char(char **tab)
{
	int	i;
	int	j;

	if (count_str((char const **)tab) < 3)
		return (0);
	i = -1;
	while (tab[0][++i])
	{
		if (tab[0][i] != '1')
			return (0);
	}
	i = 0;
	while (tab[++i + 1] != NULL)
	{
		if (tab[i][0] != '1' || last_char(tab[i]) != '1')
			return (0);
	}
	j = -1;
	while (tab[i][++j])
	{
		if (tab[i][j] != '1')
			return (0);
	}
	return (1);
}

int	check_map(char **tab, int (*f)(char **tab))
{
	if (!(*f)(tab))
	{
		print_error("La map contient des un ou des caracteres non autorises.");
		return (0);
	}
	if (!check_map_is_rectangle(tab))
	{
		print_error("La map n'est pas rectangulaire ou pas assez grande.");
		return (0);
	}
	if (!check_border_char(tab))
	{
		print_error("La map n'est pas entouree de mur.");
		return (0);
	}
	return (1);
}
