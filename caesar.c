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
//Verify the command-line argument exists
    string phrase = "";
    int k;
    
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
            printf("Please enter a phrase to be encoded: \n");
            phrase = GetString();
        }
        
    //Shift the characters using the command-line input
    for (int i = 0, n = strlen(phrase); i <= n - 1; i++)
        {            
            if (isalpha(phrase[i]))
            {
                char b = phrase[i]; 
                if ((isupper(b) && ((b + k) > 90)) || (islower(b) && ((b + k) > 122))
                {
                    b = b - (26 - k);
                    printf("%c!", b);
                }
                
                else 
                {
                    b = b + k;
                    printf("%c?", b);
                }
            }
            else 
            {
                printf("%c,", phrase[i]);
            }
            
        }
      printf("\n");  
//      printf("%d\n", k);


//Change the new integers into characters
//Output encrypted string, non-alphabetical characters are unchanged

}
