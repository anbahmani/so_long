/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 19:31:16 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/01 11:39:35 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

# ifdef __APPLE__
#  define KEY_W 13
#  define KEY_D 2
#  define KEY_S 1
#  define KEY_A 0
#  define KEY_ESC 53
# elif __linux__
#  define KEY_W 119
#  define KEY_D 100
#  define KEY_S 115
#  define KEY_A 97	
#  define KEY_ESC 65307
# endif

# include "so_long.h"

void	catch_event(t_data *engine);
int		move(t_data *engine, int pos_x, int pos_y);

#endif