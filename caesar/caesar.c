#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int key = atoi(argv[1]);
    if (key == 0)
    {
        printf("Key must be a numeric digit\n");
        return 1;
    }

    char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
    char ALPHABET[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char plaintext[501];



    printf("plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);

    char ciphertext[strlen(plaintext) + 1];

    for (int i = 0; i < strlen(plaintext) - 1; i++)
    {
        bool found = false;
        for (int j = 0; j < 26; j++)
        {
            int KEY = key + j;
            while (KEY >= 26)
            {
                KEY -= 26;
            }

            if (plaintext[i] == alphabet[j])
            {
                found = true;
                strncpy(&ciphertext[i], &alphabet[KEY], 1);
            }
            if (plaintext[i] == ALPHABET[j])
            {
                found = true;
                strncpy(&ciphertext[i], &ALPHABET[KEY], 1);
            }
        }
        if (found == false)
        {
            strncpy(&ciphertext[i], &plaintext[i], 1);
        }
    }
    printf("ciphertext: %s\n", ciphertext);

}
