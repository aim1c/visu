/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 20:52:44 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/17 20:54:21 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1024

# define MAX_FD 4096
# define MERROR(e) if (!e) return (-1);
# define CHECKEND(car) if (car == 0) return (0);
# define CHECKMEM(rest) if (!rest) rest = ft_strnew(1);

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

int	get_next_line(const int fd, char **line);

#endif
