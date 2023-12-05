#include "dynamicArray.h"
#include <cassert>
#include <algorithm>

DynamicArray createDynamicArrayWithCapacity(size_t capacity)
{
    DynamicArray arr;
    arr.buffer = new int[capacity];
    arr.length = 0;
    arr.capacity = capacity;
    return arr;
}

DynamicArray createDynamicArray()
{
    return createDynamicArrayWithCapacity(4); //default
}

void addElementToArray(DynamicArray* arr, int value)
{
    if (arr->length == arr->capacity)
    {
        //double the capacity
        size_t newCapacity = arr->capacity * 2;
        int* newBuffer = new int[newCapacity];

        //copy existing elements to the new buffer
        std::copy(arr->buffer, arr->buffer + arr->length, newBuffer);

        //free the old buffer
        delete[] arr->buffer;

        //update array with the new buffer and capacity
        arr->buffer = newBuffer;
        arr->capacity = newCapacity;
    }

    //add the new element
    arr->buffer[arr->length++] = value;
}

int getElementAtIndex(const DynamicArray* arr, size_t index)
{
    assert(index < arr->length);
    return arr->buffer[index];
}

std::span<int> getCurrentSpan(DynamicArray* arr)
{
    //get the span after adding elements
    std::span<int> span(arr->buffer, arr->length);
    arr->length = 0;
    return span;
}

void destroyDynamicArray(DynamicArray* arr)
{
    delete[] arr->buffer;
    arr->buffer = nullptr;
    arr->length = 0;
    arr->capacity = 0;
}
