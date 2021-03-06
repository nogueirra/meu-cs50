#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int warnings(int argc, string argv[]);
string toupperString(string text);
string encrypt(string text, string cipher);

int main(int argc, string argv[])
{
    int exitError = warnings(argc, argv);
    if(exitError != 0)
    {
        return 1;
    }
    
    string KEY = argv[1];
    
    string plaintext = get_string("plaintext: ");
    
    printf("ciphertext: %s\n", encrypt(plaintext, KEY));
    
    return 0;
}

string encrypt(string text, string cipher)
{
    // Make a cipher out of the text
    
    for(int i = 0, j = strlen(text); i < j; i++)
    {
        char currentLetter = text[i];
        
        if (isupper(currentLetter))
        {
            text[i] = toupper(cipher[text[i] - 'A']);
        }
        else if (islower(currentLetter))
        {
            text[i] = tolower(cipher[text[i] - 'a']);
        }
    }
    
    return text;
}

int warnings(int argc, string argv[])
{
    if(argc < 2 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    
    int cipherLength = strlen(argv[1]);
    string cipher = argv[1];
    
    if (cipherLength < 26)
    {
        printf("Key must contain 26 characters. Missing %i characters.\n", 26 - cipherLength);
        return 2;
    }
    if(cipherLength > 26) 
    {
        printf("Key must contain only 26 characters. %i characters remaining.\n", cipherLength - 26);
        return 2;
    }
    
    for (int i = 0; i < cipherLength; i++)
    {
        // Check if every character is an alphabetic
        if (!isalpha(cipher[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
        
        for(int j = 0; j < cipherLength; j++)
        {
            if (i != j)
            {
                if(cipher[i] == cipher[j])
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }
        
    }
    
    return 0;
}