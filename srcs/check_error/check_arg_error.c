/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 20:17:59 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/07 14:52:37 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/so_long.h"

int	check_arg_number_error(int argc)
{
	if (argc != 2)
	{
		print_error("Le nombre d'arguments est incorrectes.");
		return (0);
	}
	return (1);
}
