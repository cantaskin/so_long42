/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataskin <ataskin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:40:36 by ataskin           #+#    #+#             */
/*   Updated: 2023/02/06 21:40:38 by ataskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLHEADER.h"

static void	img_init(t_data *data)
{
	data->img_backg = mlx_xpm_file_to_image
		(data->mlx, "assets/backg.xpm", &data->img_w, &data->img_h);
	data->img_wall = mlx_xpm_file_to_image
		(data->mlx, "assets/1.xpm", &data->img_w, &data->img_h);
	data->img_player = mlx_xpm_file_to_image
		(data->mlx, "assets/sf90.xpm", &data->img_w, &data->img_h);
	data->img_collect = mlx_xpm_file_to_image
		(data->mlx, "assets/coin.xpm", &data->img_w, &data->img_h);
	data->img_exit = mlx_xpm_file_to_image
		(data->mlx, "assets/exit11.xpm", &data->img_w, &data->img_h);
	data->img_player2 = mlx_xpm_file_to_image
		(data->mlx, "assets/player2.xpm", &data->img_w, &data->img_h);
}

void	map_init(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->coord_x * PIXEL,
			data->coord_y * PIXEL, "so_long");
	data->moves = 0;
	img_init(data);
	map_draw(data, 2);
}
