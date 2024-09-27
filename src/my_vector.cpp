#include "../include/my_vector.hpp"

// Default constructor
template <typename T>
MyVector<T>::MyVector() : _data(nullptr), _size(0), _capacity(0) {}

// Destructor
template <typename T>
MyVector<T>::~MyVector() {
  delete[] _data;
}

// Returns the number of elements in the vector.
template <typename T>
size_t MyVector<T>::size() const {
  return _size;
}

// Adds an element to the end of the vector.
template <typename T>
void MyVector<T>::push_back(const T& value) {
  // Double when it is full.
  if (_size == _capacity) {
    if (_capacity == 0) resize(1);
    else resize(_capacity * 2);
  }

  _data[_size++] = value;
}

// Removes the last element of the vector.
template <typename T>
void MyVector<T>::pop_back() {
  _size--;

  // Half when it is at 1/4 capacity.
  if (_size == _capacity / 4) {
    resize(_capacity / 2);
  }
}

// Access element by index.
template <typename T>
T& MyVector<T>::operator[](size_t index) {
  return _data[index];
}

// Resizes the vector.
// Assumes _size <= new_capacity.
template <typename T>
void MyVector<T>::resize(size_t new_capacity) {
  T* new_data = new T[new_capacity];
  for (size_t i = 0; i < _size; i++) {
    new_data[i] = _data[i];
  }

  delete[] _data;
  _data = new_data;
  _capacity = new_capacity;
}
