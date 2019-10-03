//
//  roomsHandler.c
//  visualizer
//
//  Created by Frost atronach Snow bear on 01/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "visu.h"


int isRoom(char *line) {
	
	if (ft_strstr(line, "##start") && ft_strstr("##start", line)) {
		return 2;
	}
	if (ft_strstr(line, "##end") && ft_strstr("##end", line)) {
		return 3;
	}
	return 0;
}


t_list *get(t_list *main) {
	t_list *ret = main;
	
	while (42) {
		if (ft_wordcount(ret->content, ' ') == 3) {
			return ret;
		}
		ret = ret->next;
	}
	return main;
}

t_cord *getPosRooms(t_list *main) {
	t_cord *new = malloc(sizeof(t_cord));
	new->next = 0;
	t_cord *cur_new = new;
	t_list *cur = main;
	
	while (cur->next) {
		char *line = (char *)cur->content;
		size_t res = ft_wordcount(line, ' ');
		
		if (isRoom(line) == 2 || isRoom(line) == 3) {
			if (isRoom(line) == 2) {
				cur_new->name = ft_strdup("start");
			} else {
				cur_new->name = ft_strdup("end");
			}
			cur = get(cur);
			line = cur->content;
			char **split = ft_strsplit(line, ' ');
			cur_new->x = ft_atoi(split[1]) * 10;
			cur_new->y = ft_atoi(split[2]) * 10;
			cur_new->next = malloc(sizeof(t_cord));
			cur_new = cur_new->next;
			cur_new->next = 0;
		} else if (ft_wordcount(line, ' ') < 3) {
			
		} else if (line[0] == 'L') {
			break ;
		}  else if (res == 3 && isRoom(line) == 0) {
			char **split = ft_strsplit(line, ' ');
			cur_new->name = ft_strdup(split[0]);
			cur_new->x = ft_atoi(split[1]) * 10;
			cur_new->y = ft_atoi(split[2]) * 10;
			cur_new->next = malloc(sizeof(t_cord));
			cur_new = cur_new->next;
			cur_new->next = 0;
		}
		cur = cur->next;
	}
	printf("getPosRooms\n");
	return new;
}
