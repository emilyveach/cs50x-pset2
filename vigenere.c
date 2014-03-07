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

}
