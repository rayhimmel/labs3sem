#include <iostream>

//declaration
int hello(int x);

int main() {
    //call and print result
    std::cout << "Result: " << hello(420) << std::endl;

    return 0;
}

//definition
int hello(int x) {
    return x * 69;
}
