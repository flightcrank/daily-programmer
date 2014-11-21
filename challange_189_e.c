
#include <stdio.h>
#include <string.h>

int main () {

	//open file
	FILE *fp = fopen("wordlist.txt", "r");

	if (fp == NULL) {

		puts("File not found.");
		
		return 0;
	}
	
	char str[256];

	while (fgets(str, 256, fp) != NULL) {
	
		char *nl = strchr(str, '\n');

		//new line found
		if (nl != NULL) {
			
			//change new line char into a null byte, terminating the string
			*nl = '\0';
		}

		printf("%s\n", str);
	}

	//close file
	fclose(fp);

	return 1;
}

