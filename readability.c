#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    // Prompt the user for input
    string text = get_string("Text: ");

    // Count letters, words, and sentences
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Calculate L and S as per the Coleman-Liau formula
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;

    // Apply the Coleman-Liau formula
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Round the result to the nearest whole number
    int grade = round(index);

    // Output according to specification
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
        printf("Grade %i\n", grade);
    }
}
// Count alphabetic letters (A–Z and a–z)
int count_letters(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}
// Count words by counting spaces + 1
int count_words(string text)
{
    int count = 1; // Start at 1 since there's one more word than number of spaces
    for (int i = 0; i < strlen(text); i++)
    {
        if (isspace(text[i]))
        {
            count++;
        }
    }
    return count;
}
// Count sentences based on '.', '!', and '?'
int count_sentences(string text)
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}
