#include <iostream>

int main() {
    //declare and initialize the i
    int i = 69;

    //declare and initialize the number
    int number = 72;

    //change the value of i
    i = i + number;

    //define an array with 3 elements initialized to zero
    int group[3] = { 0, 0, 0 };

    //create a pointer to i
    int* iPointer = &i;

    //read the data at the address from the pointer into the variable number
    number = *iPointer;

    //write the value 15 into i through the pointer
    *iPointer = 15;

    //change the address in iPointer to the address of the 1st element of the array
    iPointer = &group[0];

    //move to the 3rd element of the array using pointer
    iPointer += 2;

    //write the value 5 directly into the 1st element of the array
    group[0] = 5;

    //write the value 6 into the 3rd element of the array through iPointer
    *iPointer = 6;

    //output
    std::cout << "i: " << i << std::endl;
    std::cout << "number: " << number << std::endl;
    std::cout << "group[0]: " << group[0] << std::endl;
    std::cout << "group[2]: " << group[2] << std::endl;

    return 0;
}
