//
//  breh.c
//  d
//
//  Created by Alexander Volkov on 27/09/2019.
//  Copyright © 2019 Alexander Volkov. All rights reserved.
//

#include "visu.h"

double abs_d(double a) {
	return (a > 0 ? (a) : (a * -1));
}


void putPixel(double x, double y, t_visual *img) {
	
	int i = (x * img->bpp / 8) + (y * img->size_of_line);
	char *addr = img->addr;
	
	addr[i] = 255;
	addr[++i] = 0;
	addr[++i] = 0;
	addr[++i] = 0;
}

void lineL(t_cord move, t_cord to, t_visual *img) {
	double dx = to.x - move.x;
	double dy = to.y - move.y;
	int yi = 1;
	
	if (dy < 0) {
		yi = -1;
		dy *= -1;
	}
	int D = 2 * dy - dx;
	
	double x = move.x;
	double y = move.y;
	
	while (x != to.x) {
		mlx_pixel_put(img->mlx, img->win, x, y, 234435);
		if (D > 0) {
			y += yi;
			D = D - 2 * dx;
		}
		D = D + 2 * dy;
		x++;
	}
}

void lineH(t_cord move, t_cord to, t_visual *img) {
	double dx = to.x - move.x;
	double dy = to.y - move.y;
	int xi = 1;
	
	if (dx < 0) {
		xi = -1;
		dx *= -1;
	}
	int D = 2 * dx - dy;
	
	double y = move.y;
	double x = move.x;
	
	while (y != to.y) {
		mlx_pixel_put(img->mlx, img->win, x, y, 234435);
		if (D > 0) {
			x += xi;
			D = D - 2 * dy;
		}
		D = D + 2 * dx;
		y++;
	}
}

void lineBr(t_cord xy0, t_cord xy1, t_visual *img) {
	if (abs_d(xy1.y - xy0.y) < abs_d(xy1.x - xy0.x)) {
		if (xy0.x > xy1.x) {
			lineL(xy1, xy0, img);
		} else {
			lineL(xy0, xy1, img);
		}
	} else {
		if (xy0.y > xy1.y) {
			lineH(xy1, xy0, img);
		} else {
			lineH(xy0, xy1, img);
		}
	}
}
