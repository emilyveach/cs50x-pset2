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

char letter_shifter(char ch, int shift);
string vigenere_cipher(string phrase, string keyword);


int main(int argc, string argv[])
{
    string keyword = argv[1];
    
    //program uses main() to verify keyword as all alpha
    if (argc != 2)
    {
        printf("Please enter a command-line argument.\n");
        return 1;
    }
    for (int i = 0, n = strlen(keyword); i < n; i++)
    {
        if (!isalpha(keyword[i]))
        {
            printf("Please enter an all-alphabetical keyword.\n");
            return 1;
        }
    }
    //program uses main() to prompt and save phrase from user
    string phrase = GetString();
    
    //main prints the result of vigenere_cipher()
    printf("%s\n", vigenere_cipher(phrase, keyword));
}


string vigenere_cipher(string phrase, string keyword)
{
    int keywordlength = strlen(keyword);
    char keychar;
    
    //vigenere_cipher() progresses through the phrase and keyword at each iteration
    for (int i = 0, k = 0, n = strlen(phrase); i < n; i++, k++)
    {
        keychar = keyword[k % keywordlength];
        
        //program uses vigenere_cipher() to normalize 
        // the k-th letter of the keyword for use by letter_shifter()
        if (isupper(keychar))
        {
            keychar -= 'A';
        }
        else 
        {
            keychar -= 'a';
        }
        
        //program uses vigenere_cipher() to send the i-th letter of the phrase with 
        //the corresponding cipher letter to letter_shifter()
        phrase[i] = letter_shifter(phrase[i], keychar);
        if (!isalpha(phrase[i]))
        {
            k--;
        }
        
    }
    
    return phrase;
}

char letter_shifter(char ch, int shift)
{   
    if (isupper(ch))
    {
        ch = (ch - 'A' + shift) % 26 + 'A';
    }
    else if (islower(ch))
    {
        ch = (ch - 'a' + shift) % 26 + 'a';
    }
    
    return ch;
}
