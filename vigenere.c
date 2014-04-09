/**
*
* Emily Veach
* vigenere.c
* Encrypts a string using a Vigenere cypher 
* check50 2014/x/pset2/vignere vignere.c
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
    int keywordlength = strlen(keyword);
        
    // go through the phrase
    for (int i = 0, k = 0, n = strlen(phrase); i < n; i++, k++)
    {
        char phraseAt = phrase[i];
        char keywordAt = keyword[k % keywordlength];
        
        if (isupper(phraseAt))
        {
            phrase[i] = (phraseAt - 'A') + (keywordAt - 'A') % 26 + 'A';
        }
        else if (islower(phraseAt))
        {
            phrase[i] = (phraseAt - 'a') + (keywordAt - 'a') % 26 + 'a';
        }
        else
        {
            printf("%c", phrase[i]);
            k--;
            continue;
        }
        printf("%c", phrase[i]);
    }
    printf("\n");
}


