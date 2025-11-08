#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (isdigit(argv[1]) == 1)
    {
        int num = atoi(argv[1]);
        if (num == 0)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            printf("Num: %i\n", num);
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}