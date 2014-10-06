
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GRID_HEIGHT 24

int main (int argc, char *argv[]) {
	
	int col;
	int col_width;
	int col_space;

	char input[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut at pharetra sapien, id sodales ipsum. Vivamus eleifend molestie tortor, vel pretium tortor venenatis nec. Nam in metus vitae nulla aliquam fringilla at vel metus. Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis dignissim mauris a velit facilisis ullamcorper. Ut vitae consectetur purus, eu auctor quam. Donec aliquet, urna non egestas faucibus, mauris velit vestibulum quam, eget porttitor eros dui non eros. Aliquam fringilla, mi et suscipit lacinia, libero ligula consequat quam, id facilisis neque augue eget metus. Mauris dignissim quis ex eget euismod. Nunc vitae lectus turpis. Vivamus tincidunt, est sollicitudin varius blandit, sapien quam molestie mi, eget volutpat dui mauris nec dui. Praesent tincidunt lectus ut leo tincidunt, quis consectetur sapien ultricies. Nunc erat risus, mollis in ultrices ac, posuere sit amet velit. Pellentesque semper tempus sapien id tempor. Suspendisse vitae condimentum mauris, quis imperdiet nisl.";

	if (argc == 4) {

		col = atoi(argv[1]);
		col_width = atoi(argv[2]);
		col_space = atoi(argv[3]);

	} else {
		
		col = 1;
		col_width = 1;
		col_space = 1;
	}
	
	int width = (col * col_width) + (col * col_space);

	char grid[GRID_HEIGHT][width];

	int i,j,k;

	//clear all grid cells to default value
	for (i = 0; i < GRID_HEIGHT; i++) {
		
		for (j = 0; j < width; j++) {
			
			grid[i][j] = ' ';
		}
	}
	
	j = 0;
	k = 0;
	int len = strlen(input);
	int col_count = 1;
	int col_start = 0;

	for (i = 0; i < len; i++) {
		
		if (j == GRID_HEIGHT) {
			
			j = 0;
			col_start = (col_count * col_width) + (col_count * col_space);
			k = col_start;
			col_count++;
		}

		if (k == col_start + col_width) {
			
			j++;
			k = col_start;
		}

		grid[j][k] = input[i]; 
		k++;
	}

	//print output grid
	for (i = 0; i < GRID_HEIGHT; i++) {
		
		for (j = 0; j < width; j++) {
			
			printf("%c", grid[i][j]);
		}

		printf("\n");
	}

	return 1;
}

