/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapUtils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:15:02 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/07 17:40:30 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

int	count_str(char const **tab)
{
	int	cmp;

	cmp = 0;
	while (tab[cmp] != NULL)
		cmp++;
	return (cmp);
}

static int	count_file_line(char const *file_name)
{
	int		fd;
	int		cmp;
	char	*line;

	fd = open(file_name, O_RDONLY);
	cmp = 0;
	while (get_next_line(fd, &line))
		cmp++;
	close(fd);
	return (cmp + 1);
}

// test d'affichage de la map
/*static void	print_map(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != NULL)
	{
		ft_putstr_fd(tab[i], 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}*/

char	**file_to_tab(char const *file_name)
{
	char	**tab;
	int		nb_line;
	int		fd;
	int		i;
//	char	*line;

	nb_line = count_file_line(file_name);
	i = 0;
	fd = open(file_name, O_RDONLY);
	tab = malloc(sizeof(char *) * (nb_line + 1));
	if (tab == NULL)
		return (NULL);
	while (i < nb_line)
	{
		get_next_line(fd, &tab[i]);
		i++;
	}
	tab[nb_line] = NULL;
	close(fd);
	return (tab);
}
