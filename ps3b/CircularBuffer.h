// Copyright 2020 Matt Zagame
#ifndef CIRCULARBUFFER_H   //NOLINT
#define CIRCULARBUFFER_H   //NOLINT

#include <stdint.h>
#include <iostream>
#include <exception>

class CircularBuffer {
 public:
    explicit CircularBuffer(int capacity);   // create an empty ring buffer
                                             // with given max capacity
    CircularBuffer(const CircularBuffer& copyCB);
    CircularBuffer(CircularBuffer&& moveCB) noexcept;
    ~CircularBuffer();

    int size() const;      // return number of items currently in the buffer
    int capacity() const;     // return capacity of buffer
    bool isEmpty() const;     // is the buffer empty (size equals zero)?
    bool isFull() const;      // is the buffer full (size equals capacity)?
    void enqueue(int16_t x);  // add item x to the end
    int16_t dequeue();        // delete and return item from the front
    int16_t peek();        // return (but do not delete) item from the front
    void empty();             // set the buffer to an empty state

    CircularBuffer& operator=(const CircularBuffer& rightSide);
    CircularBuffer& operator=(CircularBuffer&& rvalue) noexcept;

 private:
    int _size;
    int _capacity;
    int _first;
    int _last;
    int16_t* _buffer;
};
#endif  //NOLINT
