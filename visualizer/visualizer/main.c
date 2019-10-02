//
//  main.c
//  visualizer
//
//  Created by Frost atronach Snow bear on 28/09/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "visu.h"

size_t		getCountSize(t_list *mainList) {
	size_t ants;
	t_list *cur = mainList;
	
	while (42) {
		ants = ft_atoi(cur->content);
		if (ants > 0) {
			return ants;
		}
		cur = cur->next;
	}
}

void freeSplit(char **need) {
	int i = -1;
	
	while (need[++i] != 0) {
		free(need[i]);
	}
	free(need);
}

t_connect *getConnections(t_list *en) {
	t_list	*main = en;
	t_connect *head = malloc(sizeof(t_connect));
	head->next = 0;
	t_connect *cur = head;
	
	while (main->next) {
		char *line = main->content;
		if (ft_wordcount(line, '-') == 2 && line[0] != 'L') {
			char **split = ft_strsplit(line, '-');
			cur->from = ft_strdup(split[0]);
			cur->to = ft_strdup(split[1]);
			cur->next = malloc(sizeof(t_connect));
			cur = cur->next;
			cur->next = 0;
		}
		main = main->next;
	}
	return head;
}

t_antpos *getAntsDislocation(char *data) {
	
	char **space;
	char **line;
	size_t		space_words;
	size_t		line_words;
	size_t		i = -1;
	t_antpos *head = malloc(sizeof(t_antpos));
	head->next = 0;
	t_antpos *new = head;
	
	space_words = ft_wordcount(data, ' ');
	if (space_words > 0 || ft_wordcount(data, '-') == 2) {
		if (ft_wordcount(data, '-') == 2) {
			space = malloc(sizeof(char *) + 1);
			space[0] = ft_strdup(data);
			space[1] = 0;
			space_words = 2;
		} else {
			space = ft_strsplit(data, ' ');
		}
	}
	while (++i < space_words - 1) {
		line = ft_strsplit(space[i], '-');
		new->name = ft_strdup(line[0]);
		new->to_room = ft_strdup(line[1]);
		new->next = malloc(sizeof(t_antpos));
		new = new->next;
		new->next = 0;
	}
	i = -1;
	return head;
}

t_steps *handleData(t_list *main) {
	t_steps *new = initSteps();
	t_steps *c = new;
	t_list	*cur = main;
	size_t step = 1;
	
	c->count_ants = getCountSize(main);
	c->position_rooms = getPosRooms(main);
	c->room_connections = getConnections(main);
	
	while (cur->next) {
		char *line = cur->content;
		
		if (line[0] == 'L') {
			c->step = step;
			c->position_ants = getAntsDislocation(line);
			c->next = initSteps();
			c = c->next;
			c->count_ants = new->count_ants;
			c->position_rooms = new->position_rooms;
			c->room_connections = new->room_connections;
			step += 1;
		}
		cur = cur->next;
	}
	return new;
}

t_steps *readData() {
	
	char *line;
	int res = 0;
	t_list *head = malloc(sizeof(t_list));
	head->next = 0;
	t_list *cur = head;
	
	while ((res = ft_gnl(0, &line)) > 0) {
		cur->content = (void *)ft_strdup(line);
		cur->next = malloc(sizeof(t_list));
		cur = cur->next;
	}
	t_steps *steps = handleData(head);
	return steps;
}

void printIt(t_steps *steps) {
	printf("%zu\n", steps->count_ants);
	t_cord *cur = steps->position_rooms;
	t_connect *cur_c = steps->room_connections;
	printf("%sLOG: - Start printing rooms\n%s", "\x1B[32m", "\x1B[0m");
	while (cur->next) {
		printf("%s %.0f %.0f\n", cur->name, cur->x, cur->y);
		cur = cur->next;
	}
	printf("%sLOG: - End printing rooms\n%s", "\x1B[32m", "\x1B[0m");
	printf("%sLOG: - Start printing connections \n%s", "\x1B[35m", "\x1B[0m");
	while (cur_c->next) {
		printf("from: %s to: %s\n", cur_c->from, cur_c->to);
		cur_c = cur_c->next;
	}
	printf("%sLOG: - End printing connections \n%s", "\x1B[35m", "\x1B[0m");
//	printf("%sLOG: - Start print steps! \n%s", "\x1B[31m", "\x1B[0m");
//	while (steps->next) {
//		printf("%sStep: %zu%s\n", "\x1B[32m", steps->step ,"\x1B[0m");
//		t_antpos *now = steps->position_ants;
//		while (now->next) {
//				printf("\t ant: %s to: %s\n", now->name, now->to_room);
//				now = now->next;
//		}
//		steps = steps->next;
//	}
//	printf("%sLOG: - End print steps! \n%s", "\x1B[31m", "\x1B[0m");
}

t_minmax *getLimits(t_steps *s) {
	t_minmax *new = malloc(sizeof(t_minmax));
	t_steps *cur = s;
	
	t_cord *rooms = s->position_rooms;

	new->x_max = -2147483648;
	new->y_max = -2147483648;
	new->x_min = INT_MAX;
	new->y_min = INT_MAX;
	
	while (rooms->next) {
		if (new->x_min > rooms->x) {
			new->x_min = rooms->x;
		}
		if (new->x_max < rooms->x) {
			new->x_max = rooms->x;
		}
		if (new->y_max < rooms->y) {
			new->y_max = rooms->y;
		}
		if (new->y_min > rooms->y) {
			new->y_min = rooms->y;
		}
		rooms = rooms->next;
	}
	
	return new;
}

int main(void) {
	
	t_steps *steps = readData();
	
	t_minmax *limits = getLimits(steps);
	
	printf("xMIN : %d yMIN : %d xMAX : %d yMAX : %d\n", limits->x_min, limits->y_min, limits->x_max, limits->y_max);
	
//	printIt(steps);
	
	
}
