#include <cs50.h>
#include <stdio.h>

int main(void)
{
    for (int i = 1; i < 101; i++)
        {
            if (i % 5 == 0 && i % 3 == 0)
            {
                printf("CracklePop\n");
            }
            
            else if (i % 3 == 0)
            {
                printf("Crackle\n");
            }
            
            else if (i % 5 == 0)
            {
                printf("Pop\n");
            }
            
            else
            {
                printf("%d\n", i);
            }
        }
}
