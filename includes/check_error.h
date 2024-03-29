/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:14:49 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/04 19:09:39 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_ERROR_H
# define CHECK_ERROR_H

# include "so_long.h"

char	**check_error(int ac, char **av, int (*f)(char **tab));
int		check_arg_number_error(int argc);
int		check_input_file_error(char const *file_name);
int		check_map(char **tab, int (*f)(char **tab));
int		check_number_char(char **tab);
int		check_authorized_char(char **tab);
#endif