#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

int ccopy(const char* str) {
    const char proto_cmd[] = "echo '%s' | pbcopy";

    char cmd[strlen(str) + strlen(proto_cmd) -1];
    sprintf(cmd, proto_cmd, str);

    return system(cmd);
}

int main(int argc, char **argv) {

    srand(time(NULL));

    char const *version;
    char input[] = "";
    char input2[] = "";
    //char words[] = "";
    //char excludedWords[] = {'%', '\\'};
    int genlength;
    //char genlengthInput[2] = {};
    //int vowels;

    /*bool includeNums = false;
    bool includeMiscCharacters = false;
    bool includeRandomCaps = false;
    bool isFirstLetterIsCap = false;
    bool numsAreAtEnd = false;
    bool includeSpcificWords = false;
    */

    version = "version 0.0.1";
    printf("\033[0;95mString Generator %s\n", version);

    printf("enter string length\n");
    scanf("%d", &genlength);
    char generated[] = {};
//    printf("%s", genlengthInput);
//   strtol(genlengthInput, &end, genlength);
    
//   printf("gen length input is %s.\ngen length is %d", genlengthInput, genlength); 
    printf("\ntype 'gen' to generate the string once you have finished setting all other settings\n\n");
    while(getchar() != '\n') {
        getchar();
        fgets(input, 3, stdin);
        input[strcspn(input, "\n")] = '\0';
    }

    char fixedInput[genlength];
    sprintf(fixedInput, "%s", input);

    if(strcmp(input, "gen") == 0 || strcmp(input, "GEN") == 0) {
        printf("this wokrd");
        for(int i = genlength; i > 0; i--) {
                generated[i] = rand() % 256;
                printf("%c", generated[i]);
        }
        printf("%s", generated);
    }
    else
    {
        printf("you need to input either gen or GEN");
    }
    

    printf("\nwould you like to copy output to your clipboard?\n");
    while(getchar() != '\n') {
        fgets(input, 3, stdin);
    }

    if(strcmp(input2, "YES") == 0 || strcmp(input2, "yes") == 0) {
        ccopy(generated);
    }

    return EXIT_SUCCESS;

}
