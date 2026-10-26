#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    int score1 = compute_score(word1);                    // Compute score for Player 1
    int score2 = compute_score(word2);                    // Compute score for Player 2

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

int compute_score(string word)
{
    int score = 0;                                  // Initialize score to 0
    int len = strlen(word);                         // Get the length of the word
    for (int i = 0; i < len; i++)
    {
        if (isupper(word[i]))                       // Check if the character is an uppercase letter
        {
            score += POINTS[word[i] - 'A'];         // Calculate score for uppercase letters
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];         // Calculate score for lowercase letters
        }
    }
    return score;                                   // Return the total score
}
