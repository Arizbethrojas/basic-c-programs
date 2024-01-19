/*
 * words - a program that breaks its input into a series of words, one per line.
 * It may take input from stdin, or from files whose names are listed as arguments.
 * When one or more filenames are given on the command line, words reads from each file in sequence.
 * If the special filename - is given as one of the filenames, the stdin is read at that point in the sequence.
 * 
 * assumptions: A word is a maximal sequence of one or more letters, bounded by the beginning of file, end of file, or any non-letter character.
 *
 * exit: If the program terminates normally, it exits with a return code of 0.
 * Otherwise, it terminates with a non-zero return code
 *
 * Arizbeth Rojas 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void wordByWord(FILE *fp);

int main(const int argc, const char *argv[])
{
    int exitCode = 0;
    if (argc == 1)
    {
        wordByWord(stdin); // call helper function to read std in
    }
    else
    {
        int index = 1;
        while (argv[index] != NULL)
        {
            if (argv[index][0] == '-') // accesses first character of the current argument
            {
                wordByWord(stdin); // call helper function to read std in
            }
            else
            {
                FILE *fp = fopen(argv[index], "r"); // creates a file pointer to the current file in read mode
                if (fp == NULL)
                {
                    fprintf(stderr, "Error: Cannot open file %s in read mode\n", argv[index]);
                    exitCode = 1;
                }
                else
                {
                    // read file word by word
                    wordByWord(fp);
                    fclose(fp);
                }
            }
            index++;
        }
    }
    return exitCode;
}

void wordByWord(FILE *fp)
{ // function to print individual words on seperate lines from files
    int boolean = 0;
    char currChar;                        // character from file
    while ((currChar = fgetc(fp)) != EOF) // checks to see if there is a character and to make sure we are not at the end of file
    {
        if (isalpha(currChar))
        {
            printf("%c", currChar); // prints character by character
            boolean = 1;
        }
        else
        {
            if (boolean == 1)
            { // when it reaches a character that is not an alphabet, the program assumes that is the end of that specific word
                printf("\n");
                boolean = 0;
            }
        }
    }
}
