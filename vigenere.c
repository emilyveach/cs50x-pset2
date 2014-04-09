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

string caesar_cipher(int cipher, string phrase);
string vigenere_cipher(string phrase, string keyword);

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
    
    printf("%s\n", vigenere_cipher(phrase, keyword));
}



string vigenere_cipher(string phrase, string keyword)
{
    int keywordlength = strlen(keyword);
    
    for (int i = 0, k = 0, n = strlen(phrase); i < n; i++, k++)
    {
        char phraseAt = phrase[i];
        char keywordAt = keyword[k % keywordlength];
        int cipher = keywordAt;
        
        if (isalpha(phraseAt))
        {
            return caesar_cipher(cipher, phrase);
            k++;
        }
        else 
        {
            phraseAt = phrase[i];
            k--;
            continue;
        }
    }
    
    return phrase;
}

string caesar_cipher(int cipher, string phrase)
{
    char phraseAt;
    
    //Shift the characters using the command-line input
    for (int i = 0, n = strlen(phrase); i < n; i++)
    {
        phraseAt = phrase[i];
        
        if (!isalpha(phraseAt))
        {
            phrase[i] = phraseAt;
            continue;
        }
            
        if (isupper(phraseAt))
        {
            phrase[i] = (phraseAt - 'A' + cipher) % 26 + 'A';
        }
        else
        {
            phrase[i] = (phraseAt - 'a' + cipher) % 26 + 'a';
        }
    }
    
    return phrase;
}
