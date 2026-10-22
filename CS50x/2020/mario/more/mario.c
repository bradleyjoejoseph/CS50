#include<cs50.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h> 

int main(void)
{
    int height;
    char tag[] = "#";
    int space = 7;
    string tagsGonnaAdd = "#";
    int line;
    int max = 9;
    int min = 0;

    do
    {
        height = get_int("Height: ");
    }
    while (9 <= height || 1 > height);


    if (max > height && min < height)
    {
        int numOfLines = height;

        do
        {

            if (numOfLines == 8)
            {
                printf("       ");
            }
            else if (numOfLines == 7)
            {
                printf("      ");
            }
            else if (numOfLines == 6)
            {
                printf("     ");
            }
            else if (numOfLines == 5)
            {
                printf("    ");
            }
            else if (numOfLines == 4)
            {
                printf("   ");
            }
            else if (numOfLines == 3)
            {
                printf("  ");
            }
            else if (numOfLines == 2)
            {
                printf(" ");
            }
            else if (numOfLines == 1)
            {
                printf("");
            }


            printf("%s  ", tag);
            printf("%s", tag);

            strncat(tag, tagsGonnaAdd, 1);
            printf("\n");

            --numOfLines;
        }
        while (numOfLines > 0);

    }

}