/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abahmani <abahmani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:25:45 by abahmani          #+#    #+#             */
/*   Updated: 2021/12/01 13:14:14 by abahmani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "so_long.h"
# include "ihm.h"

# ifdef __APPLE__
#  define MLX_DESTROY
# elif __linux__
#  define MLX_DESTROY mlx_destroy_display(engine->data->mlx);
# endif

char	**free_tab(char **tab);
void	free_mlx(t_data *engine);
#endif