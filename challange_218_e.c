
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *input = "24";

void reverse_str() {

	int i;

	for (i = 0; i < (int) strlen(input); i++) {
	
		printf("%d\n", i);
	}
}

int main () {
	

	int num_1 = atoi(input);
	reverse_str();
	
	return 0;
}
