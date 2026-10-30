#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
 
int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
    
    // prompt the user for some text.
    string text = get_string("text: ");
    // count the number of letters, words, and sentences in the text.
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // cumpute the coleman-liau index.
    // calculating the average number of characters per 100 words.
    float l = ((float) letters / (float) words) * 100;

    // calculating the average number of sentences per 100 words.
    float s = ((float) sentences / (float) words) * 100;
    // applying the coleman-liau index formule.
    float index = 0.0588 * l - 0.296 * s - 15.8;
    // using the 'round' function to round the result.
    int grade = round(index);
    // print the grade level.
    if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)

{
    // return the number of letters in text.
    int letters = 0;
    // get the length of the string.
    int length = strlen(text);
    for (int i = 0; i < length; i++)
    {
        // count letters (A-Z, a-z)

        if (isalpha(text[i]))
        {
            letters++;
        }
    }

    return letters;
}
    
int count_words(string text)
{
    // return the number of words in text.
    int words = 1;
    for (int i = 0; text[i] != '\0'; i++)
    {
        // count words by checking for spaces.
        if (text[i] == ' ')
            words++;
    }
    return words;
}

int count_sentences(string text)
{
    // return the number of sentences in text.
    int sentences = 0;
    for (int i = 0; text[i] != '\0'; i++)
    {
        // count sentences by checking for ending punctuation marks.
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}