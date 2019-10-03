//
//  initStructs.c
//  visualizer
//
//  Created by Frost atronach Snow bear on 30/09/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "visu.h"

t_steps			*initSteps() {
	
	t_steps *new;
	
	new = (t_steps *)malloc(sizeof(t_steps));
	new->next = 0;
	new->position_ants = 0;
	new->position_rooms = 0;
	new->step = 0;
	new->graphic = malloc(sizeof(t_visual));
	
	return new;
}

t_cord *initRoomsPosition() {
	t_cord *pos;
	
	pos = (t_cord *)malloc(sizeof(t_cord));
	pos->name = 0;
	pos->x = 0;
	pos->y = 0;
	pos->next = 0;
	
	return pos;
}
