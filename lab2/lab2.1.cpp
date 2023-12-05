#include <stdlib.h>
#include <iostream>
#include <cstring>

//define a structure TwoInts with two int members a and b
struct TwoInts
{
    int a;
    int b;
};

//define a structure StructWithArray with int array arr and an integer pointer someNumber
struct StructWithArray
{
    int arr[4];
    int* someNumber;
};

int main()
{
    //create an instance of TwoInts and initialize it with default values (both elements set to 0)
    TwoInts i2 = { };

    //assign values to the members of i2
    i2.a = 5;
    i2.b = 7;

    //print the values of a and b
    std::cout << i2.a << std::endl; //output: 5
    std::cout << i2.b << std::endl; //output: 7

    //create an instance of StructWithArray and initialize it with default values (all elements set to 0)
    StructWithArray s = { };

    //assign a value to the 1st element of the array arr in s
    s.arr[0] = 10;

    //create another instance of StructWithArray and initialize it with default values
    StructWithArray s1 = { };
    s1.arr[0] = 15;

    //create a pointer to StructWithArray and point it to the memory location of s
    StructWithArray* sPointer = &s;

    //change the value of the 1st element of the array arr through the pointer
    sPointer->arr[0] = 20;

    //print the values of the 1st element of the array arr in s
    std::cout << s.arr[0] << std::endl; //output: 20

    //change the value of the 1st element of the array arr in s
    s.arr[0] = 25;

    //print the values of the 1st element of the array arr in s
    std::cout << s.arr[0] << std::endl; //output: 25

    //change the value of the 1st element of the array arr through the pointer
    sPointer->arr[0] = 30;

    //print the values of the 1st element of the array arr in s
    std::cout << s.arr[0] << std::endl; //output: 30

    //change the pointer to point to the memory location of 's1'
    sPointer = &s1;

    //change the value of the 1st element of the array arr through the pointer
    sPointer->arr[0] = 35;

    //print the values of the 1st elements of the arrays arr in s and s1
    std::cout << s.arr[0] << std::endl; //output: 30
    std::cout << s1.arr[0] << std::endl; //output: 35

    //create an array of StructWithArray with two elements and initialize them with default values
    StructWithArray structArray[2] = { };

    //assign a value to the 4th element of the array arr in the 1st element of structArray
    structArray[0].arr[3] = 77;

    //assign the address of the 4th element of the array arr in the 1st element of structArray to someNumber in the 2nd element
    structArray[1].someNumber = &structArray[0].arr[3];

    //point sPointer to the memory location of s
    sPointer = &s;

    //create a pointer to an integer and point it to the 4th element of the array arr through sPointer
    int* pointer = &sPointer->arr[3];

    //change the value of the 4th element of the array arr in s
    s.arr[3] = 72;

    //print the value pointed to by pointer
    std::cout << *pointer; //output: 72

    //create an instance of StructWithArray called memory and set all its bytes to 0
    StructWithArray memory;
    memset(&memory, 0, sizeof(StructWithArray));

    //end
    return 0;
}