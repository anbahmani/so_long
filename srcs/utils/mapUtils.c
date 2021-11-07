/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapUtils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:15:02 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/07 18:05:52 by abahmani         ###   ########.fr       */
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
	if (fd == -1)
		return (-1);
	cmp = 0;
	while (get_next_line(fd, &line))
	{
		free(line);
		cmp++;
	}
	free(line);
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

	nb_line = count_file_line(file_name);
	if (nb_line == -1)
		return (NULL);
	i = -1;
	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tab = malloc(sizeof(char *) * (nb_line + 1));
	if (tab == NULL)
		return (NULL);
	while (++i < nb_line)
		get_next_line(fd, &tab[i]);
	tab[nb_line] = NULL;
	close(fd);
	return (tab);
}
