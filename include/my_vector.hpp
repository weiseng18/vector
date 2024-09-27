#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

#include <cstddef>

template <typename T>
class MyVector {
public:
  MyVector();
  ~MyVector();

  size_t size() const;

  void push_back(const T& value);
  void pop_back();

  T& operator[](size_t index);

private:
  T* _data;
  size_t _size;
  size_t _capacity;

  void resize(size_t new_capacity);
};

#endif
