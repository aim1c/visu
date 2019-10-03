//
//  visu.h
//  visualizer
//
//  Created by Frost atronach Snow bear on 30/09/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#ifndef visu_h
#define visu_h

#include "libs/mlx.h"
#include "libs/libft.h"
#include <stdio.h>

#define ROOMS -1
#define ANTS -2
#define END_DATA 0

#define INT_MAX 2147483647

typedef struct	s_minmax {
	
	int y_min;
	int y_max;
	int x_min;
	int x_max;
	
	
}				t_minmax;

typedef struct	s_cord {
	double		x;
	double		y;
	char		*name;
	struct		s_cord *next;
}				t_cord;

typedef struct s_antpos {
	char		*to_room;
	char		*into_room;
	char		*name;
	double		x;
	double		y;
	struct		s_antpos *next;
}				t_antpos;

typedef struct	s_connect {
	char		*from;
	char		*to;
	struct		s_connect *next;
}				t_connect;

typedef struct	s_visuality {
	double		zoom;
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bpp;
	int			size_of_line;
	int			endian;
	int			width;
	int			height;
}				t_visual;

typedef struct				s_steps {
	size_t					step;
	size_t					count_ants;
	struct		s_cord		*position_rooms;
	struct		s_connect	*room_connections;
	struct		s_antpos	*position_ants;
	struct		s_minmax	*limits;
	struct		s_visuality *graphic;
	struct		s_steps		*next;
}							t_steps;


void lineBr(t_cord xy0, t_cord xy1, t_visual *img);
t_cord			*initRoomsPosition();
t_steps			*initSteps();

t_cord *getPosRooms(t_list *main);
int keydown(int keycode, void *param);

#endif /* visu_h */
