
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct word {
	
	char str[256];
	struct word *next;
};

//setup linked list
struct word first;
struct word *current = &first;

void add_to_list(char *str) {
			
	//copy string form file into the current linked list element
	strcpy(current->str, str);
	
	//allocate memory for next linked list elemnt and link the current element to it.
	current->next = malloc(sizeof(struct word));
	
	//change the current element to the next one for processing
	current = current->next;

	//initilise the current elements *next pointer to NULL so we know when the linked list ends.
	current->next = NULL;
}

int main () {

	char selection[2];

	do {

		printf("Please Select Difficulty;\n" 
			"1: Easy (words >= 8 chars)\n"
			"2: Medium (words 6 - 7 chars)\n" 
			"3: Hard (words < 5 chars)\n");
	
		//get user input
		fgets(selection, sizeof(selection), stdin);

		if (selection[0] == '1' || selection[0] == '2' || selection[0] == '3') {

			printf("Option %c: selected\n", selection[0]);

		} else {
	
			selection[0] = '0';
		}

	} while(selection[0] == '0');

	

	//temp string to store a single line read from the word file
	char str[256];
	
	//open file
	FILE *fp = fopen("wordlist.txt", "r");

	if (fp == NULL) {

		puts("File not found.");
		
		return 0;
	}
	
	//loop through all lines in the file, and put them into the temp string
	while (fgets(str, sizeof(str), fp) != NULL) {
	
		//look for the new line char in the line that was just read
		char *c = strchr(str, '\n');

		//new line found
		if (c != NULL) {
			
			//change new line char into a null byte, terminating the string
			*c = '\0';
		}
		
		//look for the ' char in the string
		c = strchr(str, '\'');
		
		//string containing the ' char found. Skip over this word rather tan copy it to the linked list
		if (c != NULL) {
			
			continue;
		}

		int len = strlen(str);
		
		//easy difficutly
		if (selection[0] == '1' && len >= 9) {
			
			add_to_list(str);
		
		//medium difficutly
		} else if (selection[0] == '2' && len >= 6 && len <= 8) {
			
			add_to_list(str);
		
		//hard difficulty
		} else if (selection[0] == '3' && len <=5){
		
			add_to_list(str);
		}
	}

	//close file
	fclose(fp);
	
	current = &first;

	while (current->next != NULL) {
		
		printf("%s\n", current->str);
		current = current->next;
	}

	//free the linked list's memory
	//free(...);

	return 1;
}

