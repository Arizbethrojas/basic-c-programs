#!/bin/bash
# testing file for the program words.c 
# Arizbeth Rojas 2024 
#
#no arguments, should read from stdin until user enters control+d
./words 
# one argument called practice.txt which is a scene from Julia Robert's Pretty woman 
./words practice.txt 
# providing file name and the special filename '-' to read from stdin until control+d is entered
echo -e "In this modern update on Cinderella a working girl and a wealthy businessman fall hard for one another forming an unlikely pair" | ./words practice.txt - practice.txt
 # changing the order and still using the '-'
echo -e "In this modern update on Cinderella a working girl and a wealthy businessman fall hard for one another forming an unlikely pair" | ./words - practice.txt
# changing the order and still using the '-'
echo -e "In this modern update on Cinderella a working girl and a wealthy businessman fall hard for one another forming an unlikely pair" | ./words practice.txt - 
# tries to open a file that does not exist 
./words doestExist.txt 

