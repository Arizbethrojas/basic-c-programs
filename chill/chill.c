/*
 * chill - program to calculate "wind chill" based on the current temperature and wind speed.
 *
 * usage: The user may run your program with no arguments, one argument, or two arguments.
 * For the first argument: temperature must be less than 50 and greater than -99.
 * For the second argument: wind velocity must be greater than or equal to 0.5 and less than or equal to 231mph.
 *
 * exit: If the program terminates normally, it exits with a return code of 0.
 * Otherwise, it terminates with a non-zero return code.
 *
 * Arizbeth Rojas 2024
 */
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[])
{
    int alphaBool = 0;
    if (argc >= 1)
    {
        if (argc == 1) // case in which there is no temperature value
        {
            printf("  Temp   Wind  Chill\n");
            printf(" -----  -----  -----\n");
            for (double t = -10.0; t < 50; t += 10) // loops through each temperature value between -10 and 40 three times each
            {
                for (double v = 5.0; v < 20; v += 5) // loops through velocity values, incrementing by 10
                {
                    double c = 35.74 + (0.6215 * t) - (35.75 * pow(v, 0.16)) + (0.4275 * t * pow(v, 0.16)); // wind chill formula
                    printf("%2.1f     %2.1f     %2.1f\n", t, v, c);                                         // extra spaces in print statement to align columns
                }
            }
        }
        if (argc == 2) // case in which there is only temperature value and no velocity value
        {
            char *alphaTemp = argv[1];
            int i = 0;
            while (alphaTemp[i] != '\0')
            { // loop to ensure no letters are considered valid inputs
                if (isalpha(alphaTemp[i])>0)
                {
                    alphaBool = 1;
                }
                i++;
            }
            if (alphaBool == 1)
            {
                printf("You cannot include alphabet letters in your input\n");
                return 1;
            }

            double t = atof(argv[1]); // creates double temperature value from user input
            if (t < -99)              // checks to see if valid temp
            {
                printf("Temperature must be greater than -99 degrees Fahrenheit\n");
                return 1;
            }
            if (t > 50) // checks to see if valid temp
            {
                printf("Temperature must be less than 50 degrees Fahrenheit\n");
                return 1;
            }
            else
            {
                printf("  Temp   Wind  Chill\n");
                printf(" -----  -----  -----\n");
                for (double v = 5.0; v < 20; v += 5) // loops through 3 velocity values because the user did not provide these values
                {
                    double c = 35.74 + (0.6215 * t) - (35.75 * pow(v, 0.16)) + (0.4275 * t * pow(v, 0.16)); // wind chill formula
                    printf("%2.1f     %2.1f     %2.1f\n", t, v, c);                                         // extra spaces in print statement to align columns
                }
            }
        }
        if (argc == 3) // case in which there is a temperature value and velocity value
        {
            alphaBool=0;
            char *alphaTemp = argv[1];
            char *alphaWind = argv[2];
            int i = 0;
            while (alphaTemp[i] != '\0')
            {
                if (isalpha(alphaTemp[i])>0)
                {
                    alphaBool = 1;
                }
                i++;
            }
            int j = 0;
            while (alphaWind[j] != '\0')
            {
                if (isalpha(alphaWind[j])>0)
                {
                    alphaBool = 1;
                }
                j++;
            }
            if (alphaBool == 1)
            {
                printf("You cannot include alphabet letters in your input\n");
                return 1;
            }
            double t = atof(argv[1]); // creates double temperature value from user input
            double v = atof(argv[2]); // creates double wind velocity value from user input
            if (t < -99)              // checks to see if valid temp
            {
                printf("Temperature must be greater than -99 degrees Fahrenheit\n");
                return 1;
            }
            if (t > 50) // checks to see if valid temp
            {
                printf("Temperature must be less than 50 degrees Fahrenheit\n");
                return 1;
            }
            if (v < .5) // checks to see if valid velocity
            {
                printf("Wind velocity must be greater than .5 MPH\n");
                return 1;
            }
            if (v > 231) // checks to see if valid velocity
            {
                printf("Wind velocity must be less than 235 MPH\n");
                return 1;
            }
            if (v <= 231 && v >= .5 && t <= 50 && t >= -99)
            {
                printf("  Temp   Wind  Chill\n");
                printf(" -----  -----  -----\n");
                double c = 35.74 + (0.6215 * t) - (35.75 * pow(v, 0.16)) + (0.4275 * t * pow(v, 0.16)); // wind chill formula
                printf("%2.1f     %2.1f     %2.1f\n", t, v, c);                                         // extra spaces in print statement to align columns
            }
        }
        if (argc >= 4)
        {
            fprintf(stderr, "Usage: this is a program to compute wind chill.\n");
            printf("You may enter a temperature value between -99 and 50 degrees Fareinheit.\n");
            printf("Given a temperature value, you may also choose to input a wind velocity value.\n");
            printf("You can also run the program with no temperature or wind velocity values.\n");
        }
    }
    return 0;
}
