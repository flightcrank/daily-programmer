
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
int list_count = -1;

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

void clean_up() {

	current = first.next;
	struct word *temp;

	//free the linked list's memory
	while (current->next != NULL) {
		
		//save the adderss for the next element in the linked list
		temp = current->next;	
		
		//free the memory of the current element
		free(current);

		//set the current element to the saved address of the next elemnt so it can be free'd
		current = temp;
	}
}

int main () {

	char selection[3];

	do {
		printf("HANGMAN !\n");
		printf("Please Select Difficulty:\n" 
			"1: Easy (words >= 8 chars)\n"
			"2: Medium (words 6 - 7 chars)\n" 
			"3: Hard (words < 5 chars)\n"
			"q: to quit\n");
	
		//get user input
		fgets(selection, sizeof(selection), stdin);

		if (selection[0] == '1' || selection[0] == '2' || selection[0] == '3') {

			printf("Option %c: selected\n", selection[0]);

		} else if (selection[0] == 'q') {
			
			puts("bye bye!");
			return 0;

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
			list_count++;
		
		//medium difficutly
		} else if (selection[0] == '2' && len >= 6 && len <= 8) {
			
			add_to_list(str);
			list_count++;
		
		//hard difficulty
		} else if (selection[0] == '3' && len <=5){
		
			add_to_list(str);
			list_count++;
		}
	}

	//close file
	fclose(fp);
	
	//select random word from list
	int index = rand() % list_count;
	
	int count = 0;
	current = &first;
	
	while(count <= list_count) {
		
		if (count == index) {
			
			strcpy(str, current->str);
			break;
		}
			
		current = current->next;
		count++;
	}
	
	printf("list count %d\n", list_count);
	
	char guess[] = "0000000000";

	
	int i = 0;
	int j = 0;
	int win = 0;

	//loops for 10 guess's
	for (i = 0; i < strlen(guess); i++) {
	
		win = 0;
		printf("Word :");
		
		//loop over the length of the word to find
		for (j = 0; j < strlen(str); j++) {
			
			if (strchr(guess, str[j]) != NULL) {
				
				printf("%c ", str[j]);
				win++;

			} else {
				
				printf("_ ");
			}
		}
		
		if (win == strlen(str)) {
			
			printf("\nGame Won !!!\n");

			//free the heap
			clean_up();

			return 0;
		}

		fgets(selection, 10, stdin);

		for (j = 0; j < strlen(guess); j++) {

			if (guess[j] == '0') {
				
				guess[j] = selection[0];
				break;
			}
		}

		printf("guess's = %s\n", guess);
		
	}
	
	//free the heap, game not won
	clean_up();

	return 0;
}

