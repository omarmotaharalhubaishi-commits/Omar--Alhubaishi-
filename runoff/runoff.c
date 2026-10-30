#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // Go through all the candidates one by one.
    for (int i = 0; i < candidate_count; i++)
    {
        // compare the name of the candidate with the name provided by the voter.
        if (strcmp(candidates[i].name, name) == 0)
        {
            // storage of the voter's preference for the candidate in the preferences array.
            preferences[voter][rank] = i;
            // return true to indicate that the vote was successfully recorded.
            return true;
        }
    }
    // If no match is found, return false to indicate that the vote was invalid.
    return false;
}

// Tabulate votes for non-eliminated candidates.
void tabulate(void)
{
    // Loop through each voter and their preferences to count votes for non-eliminated candidates.
    for (int i = 0; i < voter_count; i++)
    {
        // Loop through each voter's ranked preferences
        for (int j = 0; j < candidate_count; j++)
        {
            // Get the index of the candidate corresponding to the voter's jth preference.
            int candidate_index = preferences[i][j];
            if (!candidates[candidate_index].eliminated)
            {
                // Increment the vote count for the candidate and break out of the loop to move to
                // the next voter.
                candidates[candidate_index].votes++;
                break;
            }
        }
    }
    // Return from the function after tabulating votes for all voters.
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Calculate the threshold for winning (more than half of the total votes).
    int threshold = voter_count / 2;
    // Loop through all candidates to check if any candidate has more votes than the threshold.
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > threshold)
        {
            // If a candidate has more votes than the threshold, print their name and return true to
            // indicate a winner has been found.
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    // If no candidate has more votes than the threshold, return false to indicate that there is no
    // winner yet.
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Initialize min to a value greater than the maximum possible votes (voter_count + 1).
    int min = voter_count + 1;
    // Loop through all candidates to find the minimum number of votes among non-eliminated
    // candidates.
    for (int i = 0; i < candidate_count; i++)
    {
        // If the candidate is not eliminated and has fewer votes than the current min, update min.
        if (!candidates[i].eliminated && candidates[i].votes < min)
        {
            min = candidates[i].votes;
        }
    }
    // Return the minimum number of votes found among non-eliminated candidates.
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // Loop through all candidates to check if all non-eliminated candidates have the same number of 
    // votes as min.
    for (int i = 0; i < candidate_count; i++)
    {
        // If a non-eliminated candidate has a different number of votes than min, return false to 
        // indicate that there is no tie.
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            return false;
        }
    }
    // If all non-eliminated candidates have the same number of votes as min, return true to 
    // indicate that there is a tie.
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // Loop through all candidates to eliminate those who have the minimum number of votes and are
    // not already eliminated.
    for (int i = 0; i < candidate_count; i++)
    {
        // If a candidate is not eliminated and has the minimum number of votes, mark them as 
        // eliminated.
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            // Set the eliminated status of the candidate to true.
            candidates[i].eliminated = true;
        }
    }
    // Return from the function after eliminating the candidates with the minimum number of votes.
    return;
}
