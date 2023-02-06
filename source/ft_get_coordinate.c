/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_coordinate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataskin <ataskin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:40:51 by ataskin           #+#    #+#             */
/*   Updated: 2023/02/06 21:40:53 by ataskin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "SLHEADER.h"

int	ft_get_mapsx(char *str)
{
	int			fd;
	int			counter;
	int			byte;
	char		p;

	byte = 1;
	fd = open(str, O_RDONLY);
	counter = 0;
	while (byte != 0)
	{
		byte = read(fd, &p, 1);
		if (p == '\n')
			break ;
		counter++;
	}
	return (counter);
}

int	ft_get_mapsy(char *str)
{
	int			fd;
	int			counter;
	int			byte;
	char		c;

	byte = 1;
	counter = 0;
	fd = open(str, O_RDONLY);
	while (byte != 0)
	{
		byte = read(fd, &c, 1);
		if (c == '\n')
			counter++;
		else if (c == '\0')
			break ;
	}
	close(fd);
	return (counter - 1);
}
