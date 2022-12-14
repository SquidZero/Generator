#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

bool range(int num, int min, int max) {

	return (min <= num && num <= max);
}

//https://stackoverflow.com/questions/1202687/how-do-i-get-a-specific-range-of-numbers-from-rand
int random_range(int min, int max) {
	return rand() % (max + 1 - min) + min;
}

int main(int argc, char **argv) {

	srand(time(NULL));

	char const *version;
	char input[20] = "";
	//char input2[20] = "";
	//char words[] = "";
	//char excludedWords[] = {'%', '\\'};
	int genlength;
	//int vowels;

	bool includeNums = true;

	bool includeMiscCharacters = true;
	bool firstLetterIsCap = false;
	bool numsAreAtEnd = false;
	//bool includeSpcificWords = false;

	const char miscCharacters[] = { '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '`', '~', '[', ']', '\\', '{', '}', '|', ',', '<' ,'.', '>', '\"', '\'', ';', ':', '?', '/', '\0' };


	version = "version 0.0.1";
	printf("String Generator %s\n", version);
	printf("the 40th character is %c\n", (char)40);

	printf("type setting(s) you would like to use\n");
	fgets(input, 5, stdin);
	getchar();
	if(strcmp(input, "inf") == 0) {
		includeNums = false;
	} 

	else if (strcmp(input, "flct") == 0) {
		firstLetterIsCap = true;
	}

	else if (strcmp(input, "imcf") == 0) {
		includeMiscCharacters = false;
	}
	
	else if (strcmp(input, "nae") == 0) {
		numsAreAtEnd = true;
	}

	else {
		printf("youd di not type inf\n");
		printf("you typed %s\n", input);
	}

	printf("%s\n", input);
	printf("enter string length\n");
	scanf(" %d", &genlength);
	printf("genlength is %d\n", genlength);
	getchar();
	printf("\ntype 'gen' to generate the string once you have finished setting all other settings\n\n");
	const char* userinput = fgets(input, 4, stdin);
	if(strcmp(input, "gen") == 0 || strcmp(input, "GEN") == 0) {
		char generated[genlength];
		for(int i = 0; i < genlength; i++) {

			int random = random_range(32, 126);
			if(random != 92)
				generated[i] = random;
			else {
				generated[i] = random_range(32, 91);
			}
		}

		if(includeNums == false) {
			for(int i = 0; i <= strlen(generated); i++) {
				if(range(generated[i], 48, 57) == true) {
					generated[i] = random_range(58, 126);

				}
			}
		}			

		if(firstLetterIsCap == true) {
			generated[0] = random_range(65,90);
		}

		if(includeMiscCharacters == false) {
			for(int i = 0; i <= genlength; i++) {
				for(int n = 0; n <= strlen(miscCharacters); n++) {
					if(generated[i] == miscCharacters[n])
						generated[i] = random_range(97, 122);
				}
			}
		}

		if(firstLetterIsCap == true) {
				generated[0] = random_range(65,90);
			}

		if(numsAreAtEnd == true) {
			for(int i = 0; i < genlength; i++) {
				if(range(generated[i], 48, 57) == true) {
					for(int f = genlength; f >= 0; f--) {
						if(range(generated[f], 48, 57) == false) {
							generated[f] = generated[i];
						}
					}
				}
			}
		}
						
		printf("\n%s\n", generated);
		printf("generated length is %zu", strlen(generated));
	}
	else
	{
		printf("you need to input either gen or GEN\n");
		printf("userinput was %s\n", userinput);
		printf("input was %s\n", input);
		printf("userinput length was %zu\n", strlen(userinput));
	}

	printf("program exiting\n");

	return EXIT_SUCCESS;
}

