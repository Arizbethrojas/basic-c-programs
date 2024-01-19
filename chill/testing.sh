#!/bin/bash
# testing file for the program chill.c 
# Arizbeth Rojas 2024 
#
# zero arguments                                                                    
./chill
# one int argument in range                                                                   
./chill 32
# one double argument in range 
./chill 44.0 
# one invalid alphabet input 
./chill z 
# one valid argument in range that is very long 
./chill -17.77483901016373785849020017377474020107484940010174757490301010028474894
# temp out of range, too big                                                                 
./chill 55
# temp out of range, too small                                                                 
./chill -200
# one argument at inclusive part of temp range (-99) 
./chill -99
# one argument at inclusive part of temp range (50) 
./chill 50 
# one argument with an alphabet as input 
./chill 15mouse 
# two arguments: wind at inclusive part of range (0.5) 
./chill 32 0.5
# two arguments: wind at inclusive part of range (231) 
./chill 32 231
# two arguments each at respective range
./chill 50 0.5
# two valid arguments                                                                     
./chill 32.5 10
# two arguments: wind out of range, too small                                                               
./chill 10 0
# two arguments: wind out of range, too big                                                               
./chill 10 400
# two arguments: temp out of range                                                                 
./chill 60 200
# two arguments: invalid temp argument                                                                 
./chill 638.5.5.4 200
# two arguments: invalid wind argument                                                                 
./chill 30 638.5.5.4
# too many arguments
./chill 20 18 28 288 28888 