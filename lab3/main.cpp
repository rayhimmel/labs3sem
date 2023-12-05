#include <iostream>
#include "f.cpp"

//declaration
static int hello(int x);

int main() {
    //function call and print result
    std::cout << "Result: " << hello(42) << std::endl;

    return 0;
}
