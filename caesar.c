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

string phrase = "";
int cipher;
string encrypted_phrase = "";   
 
string caesar_cipher()
{
    
    //Shift the characters using the command-line input
    for (int i = 0, n = strlen(phrase); i <= n - 1; i++)
    {
        char phraseAt = phrase[i];
        char encrypted;
        encrypted_phrase = phrase;
        
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
            encrypted_phrase[i] = phraseAt;
            continue;
        }
        
        encrypted += cipher;
        encrypted = encrypted % 26;
        
        if (isupper(phraseAt))
        {
            encrypted += 'A';
        }
        else if (islower(phraseAt))
        {
            encrypted += 'a';
        }
        encrypted_phrase[i] = encrypted;
    }
    
    return encrypted_phrase;  
}

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
        cipher = atoi(argv[1]);
        //Set the cypher to be 0-25
        cipher = cipher % 26;
        
        //Ask the user for a string to be encrypted
        phrase = GetString();
        
        //print the return of the caesar_cipher() function
        printf("%s\n", caesar_cipher());
    }
}
