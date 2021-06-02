#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <math.h>
#include <string.h>

long prompt(void);
int getDigits(long int number);
int getNumFromPos(long lNo, int pos);
int every(long number, bool multipleOfTwo);
string identifyCard(long creditCardNumber);


int main(void)
{
    long int credit = prompt();

    int secondToLast = every(credit, false);
    int notMultipliedNums = every(credit, true);
    int result = secondToLast + notMultipliedNums;
    
    string creditCard = identifyCard(credit);
    
    if (result % 10 != 0)
    {
        creditCard = "INVALID";
    }
    
    printf("%s\n", creditCard);
}

string identifyCard(long creditCardNumber)
{
    
    int digits = getDigits(creditCardNumber);
    string brand = "INVALID";
    
    char lastTwoDigits[10];
    char secondToLastDigit[2];
    char lastDigit[2];
    
    // Turn numbers into string
    sprintf(lastDigit, "%i", getNumFromPos(creditCardNumber, digits - 1));
    sprintf(secondToLastDigit, "%i", getNumFromPos(creditCardNumber, digits - 2));
    
    // Put numbers together
    strcat(lastTwoDigits, lastDigit);
    strcat(lastTwoDigits, secondToLastDigit);
    
    switch (digits)
    {
        
        case 13:
            if (strcmp(lastDigit, "4") == 0)
            {
                brand = "VISA";
            }
            break;
        
        case 14:
            if (strcmp(lastDigit, "4") == 0)
            {
                brand = "VISA";
            }
            break;
        
        case 15:
            if (strcmp(lastTwoDigits, "35") == 0 || strcmp(lastTwoDigits, "37") == 0)
            {
                brand = "AMEX";
            }
            else 
            {
                if (strcmp(lastDigit, "4") == 0)
                {
                    brand = "VISA";
                }
            }
            break;
        
        case 16:
            if (strcmp(lastTwoDigits, "51") == 0 || strcmp(lastTwoDigits, "52") == 0 || strcmp(lastTwoDigits, "53") == 0 
                || strcmp(lastTwoDigits, "54") == 0 || strcmp(lastTwoDigits, "55") == 0)
            {
                brand = "MASTERCARD";
            }
            else 
            {
                if (strcmp(lastDigit, "4") == 0)
                {
                    brand = "VISA";
                }
            }
            break;
    }
    
    return brand;
}

long prompt(void)
{
    long creditCard = get_long("Number: ");
    
    return creditCard;
}

int getDigits(long int number)
{
    int digits = 0;

    while (number > 0) 
    {
        number /= 10;
        digits++;
    }

    return digits;
}

int getNumFromPos(long lNo, int pos)
{
    int digits = getDigits(lNo);
    int numbers[digits], i = 0;
    
    while (lNo > 0) 
    {
        numbers[i] = lNo % 10;
        lNo /= 10;
        i++;
    }

    return numbers[pos];
}

int every(long number, bool multipleOfTwo) 
{
    
    int multiple = multipleOfTwo == true ? 0 : 1; 
    int numOfDigits = getDigits(number);
    
    int sum = 0;
    
    int i = 0;
    while (i < numOfDigits)
    {
        int curDigit = getNumFromPos(number, i);
        
        if (i % 2 == multiple)
        {
            // If the digit multiplied by 2 is lower than 10, it's added every digit of that multiplication
            // Else, it's added every digit
            
            if (multiple == 1)
            {
                if (curDigit * 2 < 10)
                {
                    sum += curDigit * 2; 
                }
                else
                {
                    sum += getNumFromPos(curDigit * 2, 0) + getNumFromPos(curDigit * 2, 1);
                }
            }
            else 
            {
                sum += curDigit;
            }
        }
        i++;
    }
    return sum;
}