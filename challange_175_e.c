
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string[] = "hello";
char input[] = "lolhe";
char output[5];

void bogo_shuffle() {

	int i,j;
	int track[5];
	
	//clear track array of any valid index values
	for (i = 0; i < 5; i++) {

		track[i] = -1;
	}

	for (i = 0; i < 5; i++) {
		
		//random index
		int r = rand() % 5;
		
		//check to see if random index has already been tried
		for(j =0; j < 5; j++) {
		
			//index has been tried before
			if (r == track[j]) {
				
				r = rand() % 5; //randomly generate a new index
				j = 0;//start the checking process from the start again
			}
		}

		track[i] = r;//keep track of the string index's that have already be randomly tried
		output[i] = input[r];
	}
}

int main() {
	
	int count = 0;

	while (1) {
		
		bogo_shuffle();
		count++;

		if (strcmp(string, output) == 0) {
			
			printf("string \"%s\" shuffled %d times to reach sorted string \"%s\"\n", input, count, output);
			break;
		}
	}

	return 0;
}
