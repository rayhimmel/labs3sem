@echo off
g++ -c dynamicArray2.cpp -o dynamicArray2.o
g++ -c main2.cpp -o main2.o
g++ dynamicArray2.o main2.o -o my_program2
