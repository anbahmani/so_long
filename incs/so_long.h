/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 21:36:35 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/07 14:54:48 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft.h"

char	**check_error(int ac, char **av);
int		check_arg_number_error(int argc);
int		check_input_file_error(char const *file_name);
int		check_map(char **tab);
int		check_number_char(char **tab);
int		get_next_line(int fd, char **line);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len, int f);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	**file_to_tab(char const *file_name);
char	**free_tab(char **tab);
int		count_str(char const **tab);
void	print_error(char *msg);


#endif