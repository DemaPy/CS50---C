#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int score_word(string word);

int main(void)
{
    int players_amount = get_int("Players amount: ");
    string players_words[players_amount];
    int players_scores[players_amount];

    for (int i = 0; i < players_amount; i++)
    {
        players_words[i] = get_string("Player %i: ", i + 1);
        players_scores[i] = score_word(players_words[i]);
    }

    int left = 0;
    int right = players_amount - 1;

    int winner_index = left;
    bool tie = false;

    while (left <= right)
    {
        if (players_scores[left] > players_scores[winner_index])
        {
            winner_index = left;
            tie = false;
        }
        else if (players_scores[left] == players_scores[winner_index] && left != winner_index)
        {
            tie = true;
        }

        if (players_scores[right] > players_scores[winner_index])
        {
            winner_index = right;
            tie = false;
        }
        else if (players_scores[right] == players_scores[winner_index] && right != winner_index)
        {
            tie = true;
        }

        left++;
        right--;
    }

    if (tie)
    {
        printf("Tie!\n");
    }
    else
    {
        printf("Player %i wins!\n", winner_index + 1);
    }
}

int score_word(string word)
{
    int char_to_score[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                             1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isalpha(word[i]))
        {
            int index = toupper(word[i]) - 'A';
            score += char_to_score[index];
        }
    }
    return score;
}