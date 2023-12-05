@echo off
g++ -c dynamicArray.cpp -o dynamicArray.o
g++ -c main.cpp -o main.o
g++ dynamicArray.o main.o -o my_program
