#include <stdio.h>
#include <cs50.h>

void pyramid(int height, char background)
{
    // Right side
    for (int y = 0; y < height; y++)
    {
        for (int i = 1; i < height - y; i++)
        {
            printf("%c", background);
        }
        
        for (int x = 0; x < height; x++)
        {
            if (x <= y)
            {
                printf("#");
            }
        }
        printf("%c", background);
        printf("%c", background);
        
        // Left side
        for (int x = 0; x < height; x++)
        {
            if (x <= y)
            {
                printf("#");
            }            
        }
            
        printf("\n");
    }
}

int main(void)
{
    char background = ' ';
    
    // Get user input
    int height;
    do 
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);

    // Actually do 
    pyramid(height, background);
}