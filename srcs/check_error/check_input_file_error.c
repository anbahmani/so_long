/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_file_error.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 21:34:35 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/06 18:49:43 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

static int	check_input_file_name(char const *file_name)
{
	unsigned int	len;

	len = (int)ft_strlen(file_name);
	if (len < 4)
		return (0);
	if (file_name[len - 1] != 'r'
		|| file_name[len - 2] != 'e'
		|| file_name[len - 3] != 'b' \
		|| file_name[len - 4] != '.')
		return (0);
	return (1);
}

static int	check_input_file_existing(char const *file_name)
{
	int	fd;

	fd = open((char *)file_name, O_RDONLY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

static int	check_input_not_directory(char const *file_name)
{
	int	fd;

	fd = open((char *)file_name, O_DIRECTORY);
	if (fd != -1)
		return (0);
	close(fd);
	return (1);
}

int	check_input_file_error(char const *file_name)
{
	if (!check_input_file_name(file_name))
	{
		ft_putstr_fd("Error\nLe nom du fichier est incorrecte.\n", 2);
		return (0);
	}
	if (!check_input_file_existing(file_name))
	{
		ft_putstr_fd("Error\nLe fichier entré est inexistant.\n", 2);
		return (0);
	}
	if (!check_input_not_directory(file_name))
	{
		ft_putstr_fd("Error\nLe fichier entré est un dossier.\n", 2);
		return (0);
	}
	return (1);
}
