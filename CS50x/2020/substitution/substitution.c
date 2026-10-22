#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string keyy = argv[1];



        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        string caps = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int keyNum = strlen(keyy);
        bool character = false;
        if (keyNum == 26)
        {

            for (int i = 0; i < 26; i++)
            {
                unsigned char const a = keyy[i];
                if (!isalpha(a))
                {
                    printf("Error 003: Key must only contain alphabetical characters\n");
                    return 1;
                }

                for (int b = 1; b < 26; b++)
                {
                    if (a == keyy[i + b])
                    {
                        printf("Error 004: Key must only contain one of each character");
                        return 1;
                    }
                }
            }

            string plain = get_string("plaintext: ");
            int textNum = strlen(plain);
            int textFix = textNum * 1;
            int f = 0;
            printf("");
            char key[26];
            char capKey[26];
            for(f = 0; f < 26; f++)
            {
                for (int g = 0; g < 26; g++)
                {
                    if(keyy[f] == caps[g])
                    {
                        strncat(key, &alphabet[g], 1);
                        strncat(capKey, &caps[g], 1);
                    }
                    else if (keyy[f] == alphabet[g])
                    {
                        strncat(key, &alphabet[g], 1);
                        strncat(capKey, &caps[g], 1);
                    }
                }
            }
            char ciphertext[textNum];
            for (int c = 0; c < textNum; c++)
            {
                for (int d = 0; d < 26; d++)
                {
                    if (plain[c] == alphabet[d])
                    {
                        strncat(ciphertext, &key[d], 1);
                        textNum = textFix * 1;
                        character = true;
                    }
                    else if (plain[c] == caps[d])
                    {
                        strncat(ciphertext, &capKey[d], 1);
                        textNum = textFix * 1;
                        character = true;
                    }
                }
                if (character == false)
                {
                    strncat(ciphertext, &plain[c], 1);
                }
                character = false;
            }
            printf("ciphertext: %s\n", ciphertext);
        }
        else
        {
            printf("Error 002: Key must have 26 characters\n");
            return 1;
        }
    }
    else
    {
        printf("Error 001: Key must be have only one argument excluding substitution\n");
        return 1;
    }
}