#pragma once

#include <iostream>
#include <cassert>
#include <span>

template <typename T>
class DynamicArray
{
private:
    T* buffer;
    size_t length;
    size_t capacity;

public:
    //default constructor
    DynamicArray();

    //constructor with capacity
    explicit DynamicArray(size_t initialCapacity);

    //destructor
    ~DynamicArray();

    //copy constructor
    DynamicArray(const DynamicArray& other);

    //copy assignment operator
    DynamicArray& operator=(const DynamicArray& other);

    //move constructor
    DynamicArray(DynamicArray&& other) noexcept;

    //access element at index
    T& operator[](size_t index);

    //add element to the array
    void add(const T& value);

    //get current span
    std::span<T> getCurrentSpan();

    //get size
    size_t size() const;

    //get capacity
    size_t getCapacity() const;
};

//default constructor implementation
template <typename T>
DynamicArray<T>::DynamicArray()
    : buffer(nullptr), length(0), capacity(0) {}

//constructor with capacity implementation
template <typename T>
DynamicArray<T>::DynamicArray(size_t initialCapacity)
    : buffer(new T[initialCapacity]), length(0), capacity(initialCapacity) {}

//destructor implementation
template <typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] buffer;
}

//copy constructor implementation
template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other)
    : buffer(new T[other.capacity]), length(other.length), capacity(other.capacity)
{
    std::copy(other.buffer, other.buffer + other.length, buffer);
}

//copy assignment operator implementation
template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{
    if (this != &other)
    {
        delete[] buffer;
        buffer = new T[other.capacity];
        length = other.length;
        capacity = other.capacity;
        std::copy(other.buffer, other.buffer + other.length, buffer);
    }
    return *this;
}

//move constructor implementation
template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray&& other) noexcept
    : buffer(other.buffer), length(other.length), capacity(other.capacity)
{
    other.buffer = nullptr;
    other.length = 0;
    other.capacity = 0;
}

//access element at index implementation
template <typename T>
T& DynamicArray<T>::operator[](size_t index)
{
    assert(index < length);
    return buffer[index];
}

//add element to the array implementation
template <typename T>
void DynamicArray<T>::add(const T& value)
{
    if (length == capacity)
    {
        size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
        T* newBuffer = new T[newCapacity];
        std::copy(buffer, buffer + length, newBuffer);
        delete[] buffer;
        buffer = newBuffer;
        capacity = newCapacity;
    }

    buffer[length++] = value;
}

//get current span implementation
template <typename T>
std::span<T> DynamicArray<T>::getCurrentSpan()
{
    std::span<T> span(buffer, length);
    length = 0;
    return span;
}

//get size implementation
template <typename T>
size_t DynamicArray<T>::size() const
{
    return length;
}

//get capacity implementation
template <typename T>
size_t DynamicArray<T>::getCapacity() const
{
    return capacity;
}
