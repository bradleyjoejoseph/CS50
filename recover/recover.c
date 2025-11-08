#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <cs50.h>
typedef uint8_t BYTE;
//comment for 100%
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("ERROR 001 - Usage: ./recover filename.filetype\n");
        return 1;
    }
    FILE *rj = fopen(argv[1], "r");
    if (rj == NULL)
    {
        printf("ERROR 002 - Couldn't open %s\n", argv[1]);
        return 2;
    }
    
    int jpegNum = 0;
    BYTE block[512];
    FILE *jpeg = NULL;
    int jpegFound = 0;
    
    while (fread(block, sizeof(block), 1, rj))
    {
        if (block[0] == 0xff && block[1] == 0xd8 && block[2] == 0xff && (block[3] & 0xf0) == 0xe0)
        {
            if (jpegFound == 1)
            {
                fclose(jpeg);
            }
            else
            {
                jpegFound = 1;
            }
            
            char filename[8];
            sprintf(filename, "%03d.jpg", jpegNum);
            jpeg = fopen(filename, "a");
            jpegNum++;
        }
        if (jpegFound == 1)
        {
            fwrite(&block, sizeof(block), 1, jpeg);
        }
    }
    fclose(rj);
    fclose(jpeg);
    return 0;
}
