/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ihm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:37:35 by abahmani          #+#    #+#             */
/*   Updated: 2021/11/27 15:44:27 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IHM_H
# define IHM_H

# include "so_long.h"
# include "img.h"

typedef struct s_ihm
{
	void	*mlx;
	void	*mlx_win;
	t_img	img;
}	t_ihm;

void	init_ihm(t_map_data map, t_ihm *data);

#endif