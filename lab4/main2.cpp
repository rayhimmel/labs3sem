#include "dynamicArray2.h"

int main()
{

    //test default constructor
    DynamicArray<int> arr1;
    assert(arr1.size() == 0);
    assert(arr1.getCapacity() == 0);

    //test constructor with capacity
    DynamicArray<int> arr2(10);
    assert(arr2.size() == 0);
    assert(arr2.getCapacity() == 10);

    //test copy constructor
    arr2.add(42);
    DynamicArray<int> arr3 = arr2;
    assert(arr3.size() == 1);
    assert(arr3[0] == 42);

    //test copy assignment operator
    DynamicArray<int> arr4;
    arr4 = arr3;
    assert(arr4.size() == 1);
    assert(arr4[0] == 42);

    //test move constructor
    DynamicArray<int> arr5 = std::move(arr4);
    assert(arr5.size() == 1);
    assert(arr5[0] == 42);
    assert(arr4.size() == 0);  // arr4 has been moved

    //test add method
    arr5.add(99);
    assert(arr5.size() == 2);
    assert(arr5[1] == 99);

    //test getCurrentSpan
    std::span<int> span = arr5.getCurrentSpan();
    assert(span.size() == 2);
    assert(span[0] == 42);
    assert(span[1] == 99);

    //add more elements
    arr5.add(1);
    arr5.add(2);
    arr5.add(3);

    //test subscript operator and size/capacity methods
    assert(arr5[2] == 2);
    assert(arr5.size() == 5);
    assert(arr5.getCapacity() == 10);

    return 0;
}
