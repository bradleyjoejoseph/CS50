#include<cs50.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<math.h>

int main(void)
{
    float wordCount = 0;
    float sentenceCount = 0;
    int i, a;
    string text = get_string("Text: ");
    float numOfLetters = strlen(text);

    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == ' ' && text[i + 1] != ' ')
        {
            wordCount++;
            numOfLetters--;

        }

    }
    for (a = 0; text[a] != '\0'; a++)
    {
        if (text[a] == '.' && text[a + 1] != '.')
        {
            sentenceCount++;
            numOfLetters--;
        }
        if (text[a] == ',' && text[a + 1] != ',')
        {
            numOfLetters--;
        }
        if (text[a] == '!' && text[a + 1] != '!')
        {
            sentenceCount++;
            numOfLetters--;
        }
        if (text[a] == '?' && text[a + 1] != '?')
        {
            sentenceCount++;
            numOfLetters--;
        }
        if (text[a] == '\'' && text[a + 1] != '\'')
        {
            numOfLetters--;
        }
        if (text[a] == '\"' && text[a + 1] != '\"')
        {
            numOfLetters--;
        }
    }
    wordCount++;
    float L = (numOfLetters / wordCount) * 100;
    float S = (sentenceCount / wordCount) * 100;
    int indexRound = round(0.0588 * L - 0.296 * S - 15.8);
    if (indexRound < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (indexRound > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", indexRound);


    }
}
