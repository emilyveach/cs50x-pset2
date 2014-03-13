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
    string k = argv[1];
    
    //verify the command line argument is all alphabetical; if not, return 1 and exit
    if (argc != 2)
    {
        printf("Please enter a command-line argument.\n");
        return 1;
    }
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        if ((isalpha(k[i])) == 0)
        {
            printf("Please enter an all-alphabetical keyword.\n");
            return 1;
        }
    }
    
    string phrase = GetString();
    for (int i = 0, n = strlen(phrase); i <= n - 1; i++)
    {
        for (int j = 0, m = strlen(k); j < m - 1; j++)
        {
            printf("j is %d, i is %d, phrase[i] is %c; ", j, i, phrase[i]);
            if (j > (strlen(k)))
            {
                j = 0;
            }
            else if (isupper(phrase[i]))
            {
            phrase[i] = phrase[i] + (k[j] % 'A');
            printf("Upper: %c ", phrase[i]);
            }
            else if (islower(phrase[i]))
            {
            phrase[i] = phrase[i] + (k[j] % 'a');
            printf("Lower: %c ", phrase[i]);
            }
            else
            {
            phrase[i] = phrase[i];
            printf("Other: %c ", phrase[i]);
            }
            printf("post j is %d, phrase[i] is %c\n", j, phrase[i]);
        }
    }
    printf("%s\n", phrase);
}
