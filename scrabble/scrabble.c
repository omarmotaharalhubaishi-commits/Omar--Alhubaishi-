#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// points assigned to each letter of the alphabet.
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string value);

int main(void)

{
    // prompt the user for two value.
    string value1 = get_string("player 1: ");
    string value2 = get_string("player 2: ");

    // compute the score of each value.
    int score1 = compute_score(value1);

    int score2 = compute_score(value2);

    // print the winner.
    if (score1 > score2)
    {
        printf("player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("player 2 wins!\n");
    }
    else 
    {
        printf("tie!\n"); 
    }
}

int compute_score(string value)

{
    // keep track of score.
    int score = 0;

    // compute score for each character.
    for (int i = 0, len = strlen(value); i < len; i++)
    {
        if (isupper(value[i]))
        {
            score += POINTS[value[i] - 'A'];
        }
        else if (islower(value[i]))
        {
            score += POINTS[value[i] - 'a'];
        }
    }
    return score;
}