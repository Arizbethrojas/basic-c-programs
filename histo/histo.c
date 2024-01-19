/*
 * histo - a program that reads a series of positive integers from stdin, and prints out a histogram.
 * There are 16 bins in final histogram.
 *
 * usage: The histogram only considers positive integer values
 *
 * assumptions:
 * 1. There will be spaces between values that the user wishes the progam to consider different values.
 * (ex: 1234 is one number but 1 2 3 4 is four numbers )
 *
 * exit: This program always exits 0
 *
 * Arizbeth Rojas 2024
 */

#include <stdio.h> //allows us to read user input
#include <math.h>  // for squaring

void histoStars(int userInput[], int bins, int size); // helper function that will print the graphic

int main(const int argc, const char *argv[])
{
    int currInt; // user input
    int currMax = 16;
    int size = 1; // initial bin size
    int bins = currMax;
    int userInput[bins];
    int scale = 4;                                                         // 2 to the power of 4 is 16
    printf("%d bins of size %d for range [0, %d)\n", bins, size, currMax); // initial bin dimensions
    while (scanf("%d", &currInt) != EOF)                                   // checks to see if there is a value
    {
        if (currInt > -1) // checks if input is positive
        {
            if (currInt >= currMax) // checks to see if resizing bins is neccessary
            {
                while (currInt > pow(2, scale))
                {
                    scale++;
                    currMax = pow(2, scale); // increases the largest number we can represent to fit the large user input
                    size = currMax / bins;   // each respective bin size are enlarges
                    printf("%d bins of size %d for range [0, %d)\n", bins, size, currMax);
                }
                int newRange = 0;
                for (int i = 0; i < bins; i++) // loops through the array to resize it to account for the new larges value
                {
                    if (i < bins / 2)
                    {
                        userInput[i] = userInput[newRange] + userInput[newRange + 1]; // updates bin size
                        newRange += 2;
                    }
                    else
                    {
                        userInput[i] = 0; // initializes new bin values to be zero
                    }
                }
                int index = currInt / size;
                userInput[index]++; // includes the new value in the histogram
            }
            else
            {
                int index = 0;
                for (int i = 0; i < currInt + 1; i += size)
                {
                    if (currInt >= i && currInt < (i + size))
                    {
                        userInput[index]++;
                    }
                    else
                    {
                        index++;
                    }
                }
            }
        }
    }
    histoStars(userInput, bins, size);
    return 0; // always exits successfully
}

void histoStars(int userInput[], int bins, int size)
{
    printf("\n");
    for (int i = 0; i < bins; i++)
    {
        printf("[  %d  -  %d] ", i * size, ((i + 1) * size) - 1);
        for (int j = 0; j < userInput[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}