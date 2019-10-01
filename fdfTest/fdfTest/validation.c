/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 21:44:46 by lorippin          #+#    #+#             */
/*   Updated: 2019/03/09 21:48:05 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	valid_map(const int fd)
{
	char	*line;
	int		i;

	while (get_next_line(fd, &line))
	{
		i = 0;
		while (line[i])
		{
			if ((line[i] == ' ' || (line[i] >= '0' ||
							line[i] <= 9) || line[i] == '-'))
				i++;
			else
				bad_map();
		}
		ft_strdel(&line);
	}
	return (1);
}
