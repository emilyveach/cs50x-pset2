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
    int keywordlength = strlen(keyword);
        
    // go through the phrase
    for (int i = 0, k = 0, n = strlen(phrase); i < n; i++, k++)
    {
        char phraseAt = phrase[i];
        char keywordAt = keyword[k % keywordlength];
        char encrypted;
        //printf("p = %c, k = %c: o = ", phraseAt, keywordAt);
        
        /*
            A B C D E ...
            0 1 2 3 4 ...
            
            a b c d e ...
            0 1 2 3 4 ...
            
            p = A, k = A: o = A
            p = B, k = B: o = C = (p-'A') + (k-'A') + 'A'
            p = B, k = c: o = (p-'A') + (k-'a') + 'A' = 1 + 2 + 'A' = 'D'
            p = C, k = z: o = (p-'A') + (k-'a') + 'A' = 2 + 25 + 'A' = 27 + 'A' = (27 % 26) + 'A' = 1 + 'A' = 'B'
            p = b, k = b: o = 
            phrase  = a b c
            keyword = abc
            p =  , k =  
            p = b, k = b
        */
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
            k--;
            printf("%c", phraseAt);
            continue;
        }
        
        if (isupper(keywordAt))
        {
            encrypted += (keywordAt - 'A');
        }
        else
        {
            encrypted += (keywordAt - 'a');
        }
        
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
