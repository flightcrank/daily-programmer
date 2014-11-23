
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct word {
	
	char str[256];
	struct word *next;
};

int main () {

	struct word first;
	struct word *current = &first;
	first.next = NULL;

	//open file
	FILE *fp = fopen("wordlist.txt", "r");

	if (fp == NULL) {

		puts("File not found.");
		
		return 0;
	}
	
	char str[256];
	
	//loop through all lines in the file, and put them in a string
	while (fgets(str, 256, fp) != NULL) {
	
		//look for the new line char in the string
		char *c = strchr(str, '\n');

		//new line found
		if (c != NULL) {
			
			//change new line char into a null byte, terminating the string
			*c = '\0';
		}
		
		//look for the ' char in the string
		c = strchr(str, '\'');
		
		//string containing the ' char found. Skip over this word rather than deal with it
		if (c != NULL) {
			
			continue;
		}

		int len = strlen(str);

		if (len >= 1 && len <= 5) {
		
			//copy string form file into the current linked list element
			strcpy(current->str, str);

			//allocate memory for next linked list elemnt and link the current element to it.
			current->next = malloc(sizeof(struct word));

			//change the current element to the next one for processing
			current = current->next;
		}

	}

	//close file
	fclose(fp);

	return 1;
}

