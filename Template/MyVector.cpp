//2025/9/26
#include <bits/stdc++.h>
#include <sstream>
using namespace std;
#define ll long long
#define endl '\n'

template<typename T>
class MyVector {
private:
  T *_data;
  size_t _size;
  size_t _capacity;
  void check_range(size_t index) const {
    if(index >= _size) {
      stringstream ss;
      ss << "out of range, index: " << index << ", size = " << _size;
      throw out_of_range(ss.str());
    }
  }
public:
  MyVector(): _data(nullptr), _size(0), _capacity(0) {}
  MyVector(int n, T init = T()): _data(new T[n]), _size(n), _capacity(n) {
    cout << "MyVector(n)" << endl;
    for(int i = 0; i < n; ++i) _data[i] = init;
  }
  MyVector(const MyVector<T> &other): _data(new T[other.size()]), _size(other.size()), _capacity(other.size()) {
    cout << "MyVector(other)" << endl;
    for(size_t i = 0; i < other.size(); ++i) _data[i] = other[i];
  }
  MyVector(const initializer_list<T> &init): _data(new T[init.size()]), _size(0), _capacity(init.size()) {
    cout << "MyVector(init)" << endl;
    for (T x: init) _data[_size++] = x;
  }
  ~MyVector() {
    delete[] _data;
  }
  class iterator {
  private:
    T *ptr;
  public:
    using value_type = T;
    using __iterator_category = random_access_iterator_tag;
    using difference_type = ptrdiff_t;
    using pointor = T*;
    using reference = T&;
    iterator() {}
    iterator(T *ptr): ptr(ptr) {}
    T& operator*() { return *ptr; }
    const T& operator*() const { return *ptr; }
    T* operator->() const { return ptr; }
    iterator& operator++() {
      ++ptr;
      return *this;
    }
    iterator operator++(int) {
      iterator temp = *this;
      ++ptr;
      return temp;
    }
    iterator& operator--() {
      --ptr;
      return *this;
    }
    iterator operator--(int) {
      iterator temp = *this;
      --ptr;
      return temp;
    }
    iterator operator+(int n) const { return iterator(ptr+n); }
    iterator operator-(int n) const { return iterator(ptr-n); }
    int operator-(const iterator &other) const { return ptr-other.ptr; }
    bool operator<(const iterator &other) const { return ptr < other.ptr; }
    bool operator>(const iterator &other) const { return ptr > other.ptr; }
    bool operator<=(const iterator &other) const { return ptr <= other.ptr; }
    bool operator>=(const iterator &other) const { return ptr >= other.ptr; }
    bool operator!=(const iterator &other) const { return ptr != other.ptr; }
    bool operator==(const iterator &other) const { return ptr == other.ptr; }
  };
  iterator begin() { return iterator(_data); }
  iterator end() { return iterator(_data+_size); }
  T& operator[](size_t index) { return _data[index]; }
  const T& operator[](size_t index) const { return _data[index]; }
  T& at(size_t index) {
    check_range(index);
    return _data[index];
  }
  const T& at(size_t index) const {
    check_range(index);
    return _data[index];
  }
  size_t size() const { return _size; }
  size_t capacity() const { return _capacity; }
  void reserve(size_t new_capacity) {
    if(new_capacity > _capacity) {
      _capacity = new_capacity;
      T *new_data = new T[_capacity];
      for(size_t i = 0; i < _size; ++i) new_data[i] = _data[i];
      delete[] _data;
      _data = new_data;
    }
  }
  void resize(size_t new_size, T init = T()) {
    if(new_size > _capacity) reserve(new_size);
    for(int i = _size; i < new_size; ++i) _data[i] = init;
    _size = new_size;
  }
  void clear() { _size = 0; }
  void push_back(const T elem) {
    if(_size == _capacity) reserve(_capacity == 0? 1: _capacity<<1);
    _data[_size++] = elem;
  }
  void pop_back() {
    if(_size == 0) throw out_of_range("can not pop_back empty vector"); 
    --_size;
  }
  void insert(const iterator &pos, const T x) {
    size_t index = pos-begin();
    if(_size == _capacity) reserve(_capacity == 0? 1: _capacity<<1);
    for(size_t i = _size; i > index; --i) _data[i] = _data[i-1];
    _data[index] = x;
    ++_size;
  }
  void erase(const iterator &pos) {
    for(int i = pos-begin(); i < _size-1; ++i) _data[i] = _data[i+1];
    --_size;
  }
  void erase(const iterator &start, const iterator &end) {
    int diff = end-start;
    if(diff < 0)  throw out_of_range("error1");
    for(size_t i = start-begin(); i < _size-diff; ++i) _data[i] = _data[i+diff];
    _size -= diff;
  }
  MyVector<T>& operator=(const MyVector<T> &other) {
    if(this != &other) {
      delete[] _data;
      _data = new T[other.capacity()];
      _size = other.size();
      _capacity = other.capacity();
    }
    return *this;
  }
  T& front() { 
    if(_size == 0) throw out_of_range("error2");
    return _data[0]; 
  }
  const T& front() const { 
    if(_size == 0) throw out_of_range("error2");
    return _data[0]; 
  }
  T& back() { 
    if(_size == 0) throw out_of_range("error3");
    return _data[_size-1];
   }
  const T& back() const { 
    if(_size == 0) throw out_of_range("error3");
    return _data[_size-1]; 
  }
  bool empty() const { return _size == 0; }
  template<typename ... Args>
  void emplace_back(const Args&... args) {
    if(_size == _capacity) reserve(_capacity == 0? 1: _capacity<<1);
    _data[_size++] = T(args...);
  }
};

void function1(const MyVector<int> &b) {
  cout << b.size() << endl;
  cout << b[1] << endl;
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  MyVector<int> a;
  for(int i = 1; i <= 4; ++i) a.push_back(i);
  for(int i = 0; i < 4; ++i) cout << a[i] << ' ';
  cout << endl;
  reverse(a.begin(), a.end());
  for(int i = 0; i < 4; ++i) cout << a[i] << ' ';
  cout << endl;
  return 0;
}