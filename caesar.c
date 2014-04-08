/**
*
* Emily Veach
* caesar.c
* Encrypts a string using a Caesar cipher increment provided by the user
* check50 2014/x/pset2/caesar caesar.c
*/

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

string caesar_cipher(int cipher, string phrase);

int main(int argc, string argv[])
{
    //Verify the command-line argument exists
    if (argc != 2)
    {
        printf("Try again with a positive number\n");
        return 1;
    }
    else
    {
        //Convert the cipher to an integer from a string 
        int cipher = atoi(argv[1]);
        string phrase = GetString();
    
        //Set the cypher to be 0-25
        cipher = cipher % 26;
        
        //print the return of the caesar_cipher() function
        printf("%s\n", caesar_cipher(cipher, phrase));
    }
}

string caesar_cipher(int cipher, string phrase)
{
    string encrypted_phrase = phrase;
    char phraseAt;
    
    //Shift the characters using the command-line input
    for (int i = 0, n = strlen(phrase); i < n; i++)
    {
        phraseAt = phrase[i];
        
        if (!isalpha(phraseAt))
        {
            encrypted_phrase[i] = phraseAt;
            continue;
        }
            
        if (isupper(phraseAt))
        {
            encrypted_phrase[i] = (phraseAt - 'A' + cipher) % 26 + 'A';
        }
        else
        {
            encrypted_phrase[i] = (phraseAt - 'a' + cipher) % 26 + 'a';
        }
    }
    
    return encrypted_phrase;  
}
