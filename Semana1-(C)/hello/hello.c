#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What's your name?\n");
    
    // %s is a placeholder
    printf("Hello, %s!\n", name);
}