#!/bin/bash
# testing file for the program words.c 
# Arizbeth Rojas 2024 
#
#multiple arguments 
#./histo hey hey hye hye
#first lab example 
echo -e "3 -4 5 1 7 0 8 0 15 12 3 5 3 3 3 3 3" | ./histo 
# second lab example 
echo -e "3 -4 5 1 7 0 8 0 15 12 3 5 18 19 20 30 7 12 50 34 32 19 44" | ./histo 
#third lab example 
echo -e "150" | ./histo
# more examples for 1 - 169
echo -e {1..169} | ./histo  
# an example with only negative numbers 
echo -e "-2 -4 -2 -2 -2 -2 -3"| ./histo


