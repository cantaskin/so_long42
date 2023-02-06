/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataskin <ataskin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:40:11 by ataskin           #+#    #+#             */
/*   Updated: 2023/02/06 21:40:14 by ataskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLHEADER.h"

void	ft_create_matrix(t_data *data, char *str, int x, int y)
{
	int		fd;
	char	*temp;

	fd = open(str, O_RDONLY);
	data->mapstr = (char **)malloc(sizeof(char *) * 200);
	while (y < data->coord_y)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		data->mapstr[y] = (char *)malloc(ft_strlen(temp) + 1);
		x = 0;
		while (temp[x] != '\n')
		{
			if (temp[x] == '\0')
				break ;
			data->mapstr[y][x] = temp[x];
			x++;
		}
		data->mapstr[y][x] = '\0';
		y++;
		free(temp);
	}
	close(fd);
}
