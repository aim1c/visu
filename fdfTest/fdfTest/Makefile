# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorippin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/22 18:56:27 by lorippin          #+#    #+#              #
#    Updated: 2019/03/06 20:14:24 by lorippin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCc = libft/ft_lstdelone.c	libft/ft_memset.c	libft/ft_strclr.c	libft/ft_strmap.c	libft/ft_strsub.c \
	   libft/ft_atoi.c libft/ft_lstiter.c libft/ft_putchar.c libft/ft_strcmp.c libft/ft_strmapi.c libft/ft_strtrim.c \
	   libft/ft_bzero.c libft/ft_lstmap.c libft/ft_putchar_fd.c libft/ft_strcpy.c libft/ft_strncat.c libft/ft_tolower.c \
	   libft/ft_isalnum.c libft/ft_lstnew.c libft/ft_putendl.c libft/ft_strdel.c libft/ft_strncmp.c libft/ft_toupper.c \
	   libft/ft_isalpha.c libft/ft_memalloc.c libft/ft_putendl_fd.c libft/ft_strdup.c libft/ft_strncpy.c \
	   libft/ft_isascii.c libft/ft_memccpy.c libft/ft_putnbr.c libft/ft_strequ.c libft/ft_strnequ.c \
	   libft/ft_isdigit.c libft/ft_memchr.c libft/ft_putnbr_fd.c libft/ft_striter.c libft/ft_strnew.c \
	   libft/ft_isprint.c libft/ft_memcmp.c libft/ft_putstr.c libft/ft_striteri.c libft/ft_strnstr.c \
	   libft/ft_itoa.c libft/ft_memcpy.c libft/ft_putstr_fd.c libft/ft_strjoin.c libft/ft_strrchr.c \
	   libft/ft_lstadd.c libft/ft_memdel.c libft/ft_strcat.c libft/ft_strlcat.c libft/ft_strsplit.c \
	   libft/ft_lstdel.c libft/ft_memmove.c libft/ft_strchr.c libft/ft_strlen.c libft/ft_strstr.c \

SRCo = *.o

FSRC = events.c init.c  projection.c validation.c read_map.c vectors.c draw.c  get_next_line.c main.c  rotation.c \
	   error.c  tmpfunc.c hello_norm.c

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRCc) -I.
	ar rc $(NAME) $(SRCo)
	ranlib $(NAME)
	gcc -Wall -Wextra -Werror -o FDF -framework OpenGL -framework Appkit  $(FSRC) $(NAME) mlx/libmlx.a

all: $(NAME)

clean:
	/bin/rm -f *.o
fclean: clean
		/bin/rm -f $(NAME)
		/bin/rm -f FDF
re: fclean $(NAME)
