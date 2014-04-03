/**
*
* Emily Veach
* caesar.c
* Encrypts a string using a Caesar cypher increment provided by the user
* check50 2014/x/pset2/caesar caesar.c
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    string phrase = "";
    int k;

    //Verify the command-line argument exists
    if (argc != 2)
    {
        printf("Try again with a positive number\n");
        return 1;
    }
    else
    {
        //Convert the cypher to an integer from a string 
        k = atoi(argv[1]);
        //Set the cypher to be 1-26
        k = k % 26;
        
        //Ask the user for a string to be encrypted
        //printf("Please enter a phrase to be encoded: \n");
        phrase = GetString();
    }
        
    //Shift the characters using the command-line input
    for (int i = 0, n = strlen(phrase); i <= n - 1; i++)
    {
        char phraseAt = phrase[i];
        char encrypted;
        
        if (isupper(phraseAt))
        {
            encrypted = phraseAt - 'A';
        }
        else if (islower(phraseAt))
        {
            encrypted = phraseAt - 'a';
        }
        else
        {
            printf("%c", phraseAt);
            continue;
        }
        
        encrypted += k;
        encrypted = encrypted % 26;
        
        if (isupper(phraseAt))
        {
            encrypted += 'A';
        }
        else if (islower(phraseAt))
        {
            encrypted += 'a';
        }
        printf("%c", encrypted);
    }
    printf("\n");  
}
