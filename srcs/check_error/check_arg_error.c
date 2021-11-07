/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:17:59 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/06 18:48:27 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

int	check_arg_number_error(int argc)
{
	if (argc != 2)
	{
		ft_putstr_fd("Error\nLe nombre d'arguments est incorrectes.", 2);
		return (0);
	}
	return (1);
}
