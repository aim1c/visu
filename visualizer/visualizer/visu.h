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

typedef struct				s_steps {
	size_t					step;
	size_t					count_ants;
	struct		s_cord		*position_rooms;
	struct		s_connect	*room_connections;
	struct		s_antpos	*position_ants;
	struct		s_steps		*next;
}							t_steps;

t_cord			*initRoomsPosition();
t_steps			*initSteps();

t_cord *getPosRooms(t_list *main);

#endif /* visu_h */
