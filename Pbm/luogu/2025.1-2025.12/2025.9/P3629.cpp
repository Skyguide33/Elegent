//2025/9/4 树的直径 2/27 MyVector
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 100005;

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
    for(int i = 0; i < n; ++i) _data[i] = init;
  }
  MyVector(const MyVector<T> &other): _data(new T[other.size()]), _size(other.size()), _capacity(other.size()) {
    for(size_t i = 0; i < other.size(); ++i) _data[i] = other[i];
  }
  MyVector(const initializer_list<T> &init): _data(new T[init.size()]), _size(0), _capacity(init.size()) {
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
    inline T& operator*() { return *ptr; }
    inline const T& operator*() const { return *ptr; }
    inline T* operator->() const { return ptr; }
    inline iterator& operator++() {
      ++ptr;
      return *this;
    }
    inline iterator operator++(int) {
      iterator temp = *this;
      ++ptr;
      return temp;
    }
    inline iterator& operator--() {
      --ptr;
      return *this;
    }
    inline iterator operator--(int) {
      iterator temp = *this;
      --ptr;
      return temp;
    }
    inline iterator operator+(int n) const { return iterator(ptr+n); }
    inline iterator operator-(int n) const { return iterator(ptr-n); }
    inline int operator-(const iterator &other) const { return ptr-other.ptr; }
    inline bool operator<(const iterator &other) const { return ptr < other.ptr; }
    inline bool operator>(const iterator &other) const { return ptr > other.ptr; }
    inline bool operator<=(const iterator &other) const { return ptr <= other.ptr; }
    inline bool operator>=(const iterator &other) const { return ptr >= other.ptr; }
    inline bool operator!=(const iterator &other) const { return ptr != other.ptr; }
    inline bool operator==(const iterator &other) const { return ptr == other.ptr; }
  };
  inline iterator begin() { return iterator(_data); }
  inline iterator end() { return iterator(_data+_size); }
  inline T& operator[](size_t index) { return _data[index]; }
  inline const T& operator[](size_t index) const { return _data[index]; }
  inline T& at(size_t index) {
    check_range(index);
    return _data[index];
  }
  inline const T& at(size_t index) const {
    check_range(index);
    return _data[index];
  }
  inline size_t size() const { return _size; }
  inline size_t capacity() const { return _capacity; }
  inline void reserve(size_t new_capacity) {
    if(new_capacity > _capacity) {
      _capacity = new_capacity;
      T *new_data = new T[_capacity];
      for(size_t i = 0; i < _size; ++i) new_data[i] = _data[i];
      delete[] _data;
      _data = new_data;
    }
  }
  inline void resize(size_t new_size, T init = T()) {
    if(new_size > _capacity) reserve(new_size);
    for(int i = _size; i < new_size; ++i) _data[i] = init;
    _size = new_size;
  }
  inline void clear() { _size = 0; }
  inline void push_back(const T elem) {
    if(_size == _capacity) reserve(_capacity == 0? 1: _capacity<<1);
    _data[_size++] = elem;
  }
  inline void pop_back() {
    if(_size == 0) throw out_of_range("can not pop_back empty vector"); 
    --_size;
  }
  inline void insert(const iterator &pos, const T x) {
    size_t index = pos-begin();
    if(_size == _capacity) reserve(_capacity == 0? 1: _capacity<<1);
    for(size_t i = _size; i > index; --i) _data[i] = _data[i-1];
    _data[index] = x;
    ++_size;
  }
  inline void erase(const iterator &pos) {
    for(int i = pos-begin(); i < _size-1; ++i) _data[i] = _data[i+1];
    --_size;
  }
  inline void erase(const iterator &start, const iterator &end) {
    int diff = end-start;
    if(diff < 0)  throw out_of_range("error1");
    for(size_t i = start-begin(); i < _size-diff; ++i) _data[i] = _data[i+diff];
    _size -= diff;
  }
  inline MyVector<T>& operator=(const MyVector<T> &other) {
    if(this != &other) {
      delete[] _data;
      _data = new T[other.capacity()];
      _size = other.size();
      _capacity = other.capacity();
    }
    return *this;
  }
  inline T& front() { 
    if(_size == 0) throw out_of_range("error2");
    return _data[0]; 
  }
  inline const T& front() const { 
    if(_size == 0) throw out_of_range("error2");
    return _data[0]; 
  }
  inline T& back() { 
    if(_size == 0) throw out_of_range("error3");
    return _data[_size-1];
   }
  inline const T& back() const { 
    if(_size == 0) throw out_of_range("error3");
    return _data[_size-1]; 
  }
  inline bool empty() const { return _size == 0; }
  template<typename ... Args>
  inline void emplace_back(const Args&... args) {
    if(_size == _capacity) reserve(_capacity == 0? 1: _capacity<<1);
    _data[_size++] = T(args...);
  }
};

int n, k;
struct edge { int to, w; };
struct edge2 { 
  int from, to; 
  bool operator < (const edge2 &other) const { 
    if(from == other.from) return to < other.to;
    return from < other.from;
  }
};
set<edge2> st;
MyVector<edge> e[N];
int dp[N], road[N], dist[N];
int maxlen = 0, cnt = 0;
bool vis[N];

bool dfs(int u, int fa, int d) {
  dist[u] = d;
  int flag = 0, add1 = 0;
  for(auto &x: e[u]) {
    if(x.to == fa) continue;
    flag = 1;
    add1 = dfs(x.to, u, d+1)|add1;
  }
  if(!flag) {
    if(dist[u] > maxlen) {
      maxlen = dist[u];
      cnt = 0;
      road[cnt++] = u;
      return 1;
    }
  }
  if(add1) {
    road[cnt++] = u;
    return 1;
  }
  return 0;
}

void dfs_dp(int u) {
  vis[u] = true;
  for(auto &x: e[u]) {
    if(vis[x.to]) continue;
    dfs_dp(x.to);
    int t = 1;
    if(st.count({u, x.to})) t = -1;
    maxlen = max(maxlen, dp[u]+dp[x.to]+t);
    dp[u] = max(dp[u], dp[x.to]+t);
  }
}

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  cin >> n >> k;
  for(int i = 0; i < n-1; ++i) {
    int u, v; cin >> u >> v;
    e[u].push_back({v, 1}); e[v].push_back({u, 1});
  }
  dfs(1, -1, 0);
  dfs(road[0], -1, 0);
  // cout << "Road: " << road[0];
  // for(int i = 1; i < cnt; ++i) cout << "->" << road[i];
  // cout << endl;
  int ans = (n-1)*2-maxlen+1;
  if(k == 2) {
    for(int i = 1; i < cnt; ++i) {
      st.insert({road[i-1], road[i]});
      st.insert({road[i], road[i-1]});
    }
    maxlen = 0;
    dfs_dp(1);
    ans -= maxlen-1;
  }
  cout << ans << endl;
  return 0;
  
  return 0;
}