#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

int count_letters(char *text);
int count_words(char *text);
int count_sentences(char *text);

int main(void)
{
    // Prompt for text
    char text[1000];
    printf("Text: ");
    fgets(text, sizeof(text), stdin);

    // Count letters, words, and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate L and S
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    // Calculate the Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Determine grade level
    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", grade);
    }

    return 0;
}

int count_letters(char *text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_words(char *text)
{
    int count = 1; // Start with 1 because the last word won't have a space after it
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}

int count_sentences(char *text)
{
    int count = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
