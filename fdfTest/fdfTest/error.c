/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 22:17:36 by lorippin          #+#    #+#             */
/*   Updated: 2019/03/09 22:18:30 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	empty_error(void)
{
	write(1, "Usage: ./fdf [map file]\n", 24);
	exit(EXIT_FAILURE);
}

void	bad_file_error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	bad_map(void)
{
	write(1, "INVALID MAP\n", 12);
	exit(EXIT_FAILURE);
}
