#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Coleman-Liau index
// Calculates the reading grade of a person by this formula right below
// index = 0.0588 * L - 0.296 * S - 15.8

// Where:
// L = the average number of letters per 100 words in the text
// S = the average number of sentences per 100 words in the text

float basicFormula(float L, float S);

int countLetters(string text);
int countWords(string text);
int countSentences(string text);

int main(void) 
{
    string text = get_string("Text: ");
    // string text = "One fish. Two fish. Red fish. Blue fish.";
    
    int letters = countLetters(text);
    int sentences = countSentences(text);
    int words = countWords(text);
    
    float lettersPerHundredWords = letters * 100.0 / words;
    float sentencesPerHundredWords = sentences * 100.0 / words;
    
    float grade = basicFormula(lettersPerHundredWords, sentencesPerHundredWords);
    
    if (grade >= 16)
    {
        printf("Grade 16+");
    }
    else if (grade < 1)
    {
        printf("Before Grade 1");
    }
    else
    {
        printf("Grade %d", (int) round(grade));
    }
    
    printf("\n");
    
    return 0;
}


// The basic formula of this program
float basicFormula(float L, float S)
{
    return 0.0588 * L - 0.296 * S - 15.8;
}


int countLetters(string text)
{
    int letters = 0;
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] >= 'A' && text[i] <= 'z' && !(text[i] >= '[' && text[i] <= '`'))
        {
            letters++;
        }
    }
    
    return letters;
}

int countWords(string text)
{
    int words = 1;
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }
    
    return words;
}

int countSentences(string text)
{
    int sentences = 0;
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}