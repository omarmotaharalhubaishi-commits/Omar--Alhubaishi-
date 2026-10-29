#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // loop through candidates to find a match for the name.
    for (int i = 0; i < candidate_count; i++)
    {
        // if the name matches, increment the vote count and return true.
        if (strcmp(candidates[i].name, name) == 0)
        {
            // increment the vote count for the candidate
            candidates[i].votes++;
            // return true to indicate a successful vote
            return true;
        }
    }
    // if no match is found, return false to indicate an invalid vote.
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // Initialize a variable to keep track of the maximum number of votes
    int max_votes = 0;
    // Find the maximum number of votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > max_votes)
        {
            max_votes = candidates[i].votes;
        }
    }
    // Print the winner(s)
    for (int i = 0; i < candidate_count; i++)
    {
        // If the candidate's votes equal the maximum votes, print their name
        if (candidates[i].votes == max_votes)
        {
            // Print the name of the candidate with the maximum votes
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}