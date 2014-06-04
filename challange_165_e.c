 /*
 (Easy): ASCII Game of Life

Hello people. Sorry for submitting this early, but I have exams this week and the next so I'll have to submit these challenges a little bit early - I'm sure that's not an issue though! Welcome to June, and it's time for a run of similarly themed challenges - all of them will be based on ASCII data. Not too dissimilar to this challenge[2] from a while ago.

This first challenge is based on a game (the mathematical variety - not quite as fun!) called Conway's Game of Life[3] . This is called a cellular automaton. This means it is based on a 'playing field' of sorts, made up of lots of little cells or spaces. For Conway's game of life, the grid is square - but other shapes like hexagonal ones could potentially exist too. Each cell can have a value - in this case, on or off - and for each 'iteration' or loop of the game, the value of each cell will change depending on the other cells around it. This might sound confusing at first, but looks easier when you break it down a bit.

    A cell's "neighbours" are the 8 cells around it.

    If a cell is 'off' but exactly 3 of its neighbours are on, that cell will also turn on - like reproduction.

    If a cell is 'on' but less than two of its neighbours are on, it will die out - like underpopulation.

    If a cell is 'on' but more than three of its neighbours are on, it will die out - like overcrowding.

Fairly simple, right? This might sound boring, but it can generate fairly complex patterns - this one, for example [4] , is called the Gosper Glider Gun and is designed in such a way that it generates little patterns that fly away from it. There are other examples of such patterns, like ones which grow indefinitely.

Your challenge is, given an initial 'state' of 'on' and 'off' cells, and a number, simulate that many steps of the Game of Life.
Formal Inputs and Outputs
Input Description

You will be given a number N, and then two more numbers X and Y. After that you will be given a textual ASCII grid of 'on' and 'off' states that is X cells wide and Y cells tall. On the grid, a period or full-stop . will represent 'off', and a hash sign # will represent 'on'.

The grid that you are using must 'wrap around'. That means, if something goes off the bottom of the playing field, then it will wrap around to the top, like this: http://upload.wikimedia.org/wikipedia/en/d/d1/Long_gun.gif [5] See how those cells act like the top and bottom, and the left and right of the field are joined up? In other words, the neighbours of a cell can look like this - where the lines coming out are the neighbours:

#-...-  ......  ../|\.
|\.../  ......  ......
......  |/...\  ......
......  #-...-  ......
......  |\.../  ..\|/.
|/...\  ......  ..-#-.

Output Description

Using that starting state, simulate N iterations of Conway's Game of Life. Print the final state in the same format as above - . is off and # is on.
Sample Inputs & Output
Sample Input

7 10 10
..........
..........
..#.......
...#......
.###......
..........
..........
..........
..........
..........

Sample Output

..........
..........
..........
..........
...#......
....##....
...##.....
..........
..........
..........

Challenge
Challenge Input

32 17 17
.................
.................
....###...###....
.................
..#....#.#....#..
..#....#.#....#..
..#....#.#....#..
....###...###....
.................
....###...###....
..#....#.#....#..
..#....#.#....#..
..#....#.#....#..
.................
....###...###....
.................
.................
*/

#include <stdio.h>
#include <string.h>

#define N 32
#define X 17 + 1 // + 1 is the space for the null byte
#define Y 17

void calculate_game_of_life();
void print_grid(char grid[][X]);
void copy_grid(char source[][X], char dest[][X]);
int check_neighbours(int pos_x, int pos_y, char gird[][X]);

char output_grid[Y][X];

char input_grid[][X] = {".................",
			".................",
			"....###...###....",
			".................",
			"..#....#.#....#..",
			"..#....#.#....#..",
			"..#....#.#....#..",
			"....###...###....",
			".................",
			"....###...###....",
			"..#....#.#....#..",
			"..#....#.#....#..",
			"..#....#.#....#..",
			".................",
			"....###...###....",
			".................",
			".................",};

int main() {

	int i;
	
	for (i = 0; i < N; i++) {
		
		calculate_game_of_life();
		copy_grid(output_grid, input_grid);
	}
	
	print_grid(output_grid);

	return 0;
}

void calculate_game_of_life() {

	int i;
	int j;

	for (i = 0; i < Y; i++) {
		
		for (j = 0; j < X - 1; j++) {
			
			char state = input_grid[i][j];
			int neighbours = check_neighbours(j, i, input_grid);

			//cell is off
			if (state == '.' && neighbours == 3) {
				
				output_grid[i][j] = '#';
			
			//cell is on
			} else if (state == '#' && neighbours < 2) {
			
				output_grid[i][j] = '.';
			
			} else if (state == '#' && neighbours > 3) {
				
				output_grid[i][j] = '.';
			
			//stays the same
			} else {

				output_grid[i][j] = input_grid[i][j];
			}
		}
	}
}

//returns the number of neighbours that are on in all 8 directions
int check_neighbours(int pos_x, int pos_y, char grid[][X]) {

	int count = 0;
	char val[8];
	
	//calculate grid index number for the 4 main directions 
	//allow wraping around if pos_x or pos_y is on the edge of the grid
	int n = (pos_y == 0) ? Y - 1 : pos_y - 1;
	int s = (pos_y == Y - 1) ? 0 : pos_y + 1;
	int e = (pos_x == X - 2) ? 0 : pos_x + 1;//(-2 to compistate for null byte)
	int w = (pos_x == 0) ? X - 2 : pos_x - 1;//(-2 to compistate for null byte)
	
	enum direction {NORTH, NORTH_EAST, EAST, SOUTH_EAST, SOUTH, SOUTH_WEST, WEST, NORTH_WEST};
	
	//value of cell's (pos_x, pos_y) 8 neighbours
	val[NORTH] = grid[n][pos_x];
	val[SOUTH] = grid[s][pos_x];
	val[EAST] = grid[pos_y][e];
	val[WEST] = grid[pos_y][w];
	val[NORTH_EAST] = grid[n][e];
	val[NORTH_WEST] = grid[n][w];
	val[SOUTH_EAST] = grid[s][e];
	val[SOUTH_WEST] = grid[s][w];
		
	int i;

	for (i = 0; i < 8; i++) {
		
		//cell is ON
		if (val[i] != '.') {
			
			count++;
		}
	}

	return count;
}

//copys the grid to another. used to have one grid to read from and another to write to.
//then swap them back to work on for more iterations
void copy_grid(char source[][X], char dest[][X]) {
	
	int i;
	
	for (i = 0; i < Y; i++ ) {
		
		strcpy(dest[i], source[i]);
	}
}

// prints the grid
void print_grid(char grid[][X]) {

	int i;
	
	for (i = 0; i < Y; i++ ) {
		
		printf("%s\n", grid[i]);
	}
}
