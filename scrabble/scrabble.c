#include <stdio.h>
#include <string.h>
#include <ctype.h>

int compute_score(char *word);

int main(void)
{
    // Array to store the point values of each letter
    int points[] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1,
        3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8,
        4, 10
    };

    char word1[100], word2[100];

    // Prompt player 1 for their word
    printf("Player 1: ");
    scanf("%s", word1);

    // Prompt player 2 for their word
    printf("Player 2: ");
    scanf("%s", word2);

    // Compute scores for both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score2 > score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int compute_score(char *word)
{
    // Array to store the point values of each letter
    int points[] = {
        1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1,
        3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8,
        4, 10
    };

    int score = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            // Convert letter to uppercase
            char upper = toupper(word[i]);
            // Add the point value of the letter to the score
            score += points[upper - 'A'];
        }
    }

    return score;
}
