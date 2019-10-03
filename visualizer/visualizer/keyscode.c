//
//  keyscode.c
//  visualizer
//
//  Created by Frost atronach Snow bear on 03/10/2019.
//  Copyright © 2019 Frost atronach Snow bear. All rights reserved.
//

#include "visu.h"

int keydown(int keycode, void *param) {
	if (keycode == 53) {
		exit(EXIT_SUCCESS);
	}
	return 1;
}
