#include <stdio.h>
#include <cs50.h>

void piramid(int height)
{
    for (int y = 1; y <= height; y++)
    {
        for (int i = 0; i < height - y; i++)
        {
            printf(" ");
        }
        
        for (int x = 1; x <= height; x++)
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
    int height;

    do
    {
        height = get_int("Height: ");
        
    }
    while (height < 1 || height > 8);

    piramid(height);
}