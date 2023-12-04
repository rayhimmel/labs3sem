#include <stdlib.h>
#include <iostream>

//function that returns a pointer to a variable with on stack
int* stackMemory1()
{
    int a = 1;   //variable a is allocated on the stack
    return &a;   //returning the address of a
}

//function that returns a pointer to another variable on stack
int* stackMemory2()
{
    int b = 2;   //variable b is allocated on stack
    return &b;   //returning the address of b
}

int main()
{
    int* b = stackMemory1();  //b now points to the memory location of a in stackMemory1()
    int a1 = *b;              //dereferencing b to get the value of a (1)

    int* c = stackMemory2();  //c now points to the memory location of b in stackMemory2()
    int a2 = *c;              //dereferencing c to get the value of b (2)

    int a3 = *b;              //dereferencing b again, but a (1) is no longer valid in the stack

    // Output values
    std::cout << a1 << std::endl;                //prints 1
    std::cout << a2 << std::endl;                //prints 2
    std::cout << a3 << std::endl;                //prints 2
    std::cout << ((std::byte*)b - (std::byte*)c) << std::endl;  //prints 0, as both pointers point to the same address

    return 0;
}
