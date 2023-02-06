/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyprocess.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataskin <ataskin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:40:59 by ataskin           #+#    #+#             */
/*   Updated: 2023/02/06 21:41:01 by ataskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLHEADER.h"

int	keyprocessing(int keyevent, t_data *data)
{
	if (keyevent == W || keyevent == UP)
	{
		data->player_y -= 1;
		player_w(data);
	}
	else if (keyevent == A || keyevent == LEFT)
	{
		data->player_x -= 1;
		player_a(data);
	}
	else if (keyevent == D || keyevent == RIGHT)
	{
		data->player_x += 1;
		player_d(data);
	}
	else if (keyevent == S || keyevent == DOWN)
	{
		data->player_y += 1;
		player_s(data);
	}
	return (1);
}
