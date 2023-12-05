#pragma once

#include <span>

struct DynamicArray
{
    int* buffer;
    size_t length;
    size_t capacity;
};

DynamicArray createDynamicArrayWithCapacity(size_t capacity);
DynamicArray createDynamicArray();
void addElementToArray(DynamicArray* arr, int value);
int getElementAtIndex(const DynamicArray* arr, size_t index);
std::span<int> getCurrentSpan(DynamicArray* arr);
void destroyDynamicArray(DynamicArray* arr);

