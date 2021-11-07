/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapUtils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 22:15:02 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/06 18:46:03 by abahmani         ###   ########.fr       */
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

static char	**add_line(char **tab, char **line)
{
	int		size;
	char	**new;
	int		i;

	size = count_str((const char **) tab);
	new = malloc(sizeof(char *) * size + 1);
	if (new == NULL)
	{
		free_tab(tab);
		free(line);
		return (NULL);
	}
	i = 0;
	while (tab[i] != NULL)
	{
		new[i] = tab[i];
		i++;
	}
	new[i] = *line;
	free_tab(tab);
	return (new);
}

char	**file_to_tab(char const *file_name)
{
	char	**tab;
	int		fd;
	int		gnl;
	char	**line = NULL;

	fd = open(file_name, O_RDONLY);
	tab = malloc(sizeof(char *));
	if (tab == NULL)
		return (NULL);
	tab[0] = NULL;
	gnl = get_next_line(fd, line);
	while (gnl != -1)
	{
		tab = add_line(tab, line);
		if (tab == NULL)
			return (NULL);
		gnl = get_next_line(fd, line);
	}
	return (tab);
}
