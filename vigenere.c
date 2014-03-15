/**
*
* Emily Veach
* vigenere.c
* Encrypts a string using a Vigenere cypher 
* check50 2014/x/pset2/caesar vignere.c
* accept a single command-line argument: a keyword, k, composed entirely of alphabetical characters
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    string keyword = argv[1];
    
    //verify the command line argument is all alphabetical; if not, return 1 and exit
    if (argc != 2)
    {
        printf("Please enter a command-line argument.\n");
        return 1;
    }
    for (int i = 0, n = strlen(keyword); i < n; i++)
    {
        if ((isalpha(keyword[i])) == 0)
        {
            printf("Please enter an all-alphabetical keyword.\n");
            return 1;
        }
    }
    
    string phrase = GetString();
    
    for (int i = 0, n = strlen(phrase); i <= n - 1; i++)
    {
        char phraseAt = phrase[i];
        
        {
            int keywordlength = strlen(keyword);
            char keywordAt = keyword[i % keywordlength];
            //printf("%c\n", keywordAt);
            
            //printf("j is %d, i is %d, phrase[i] is %c; \n", j, i, phraseAt);
            
            if ((isupper(phraseAt) && isupper(keywordAt)) || (islower(phraseAt) && isupper(keywordAt)))
            {
                phraseAt = phraseAt + (keywordAt % 'A');
                printf("%c", phraseAt);            
                //printf("Upper: %c ", phraseAt);
            }
            else if ((islower(phraseAt) && islower(keywordAt)) || (isupper(phraseAt) && islower(keywordAt)))
            {
                phraseAt = phraseAt + (keywordAt % 'a');
                printf("%c", phraseAt);
                //printf("Lower: %c ", phraseAt);
            }
            
            else
            {
                printf("%c", phraseAt);
                //printf("Other: %c ", phraseAt);
            }
        }
    }
    printf("\n");
}
