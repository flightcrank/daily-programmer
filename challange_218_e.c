
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//reverse a string inplace
void reverse_str(char *str) {

	int i;

	int len = strlen(str);
	int i2 = len -1;//index of char we want to swap

	for (i = 0; i < len / 2; i++) {
		
		char temp = str[i];
		str[i] = str[i2 - i];
		str[i2 - i] = temp;
	}
}

unsigned long long add_num(unsigned long long int a, unsigned long long int b) {

	return a + b;
}

int is_palindrome(unsigned long long num) {
	
	char orig[51];
	char rev[51];

	sprintf(orig, "%llu", num);
	strcpy(rev, orig);
	reverse_str(rev);

	return strcmp(orig, rev);

}

int main () {
	
	char input[51] = "286";
	int seed = atoi(input);
	int steps = 1;

	while(steps < 1000) {

		unsigned long long int num_1 = strtoull(input, NULL, 10);
		reverse_str(input);
		unsigned long long int num_2 = strtoull(input, NULL, 10);
		
		unsigned long long int result = add_num(num_1, num_2);
		
		//printf(" %d: %llu + %llu = %llu\n", steps, num_1, num_2, result);

		sprintf(input, "%llu", result);
		
		if (is_palindrome(result) == 0) {
			
			printf("%d gets palondromic after = %d steps: %llu\n", seed, steps, result);
			break;
		}

		steps++;
	}
		
	return 0;
}
