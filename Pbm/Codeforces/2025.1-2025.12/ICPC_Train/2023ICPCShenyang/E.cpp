//2025/10/31
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

template<typename T>
class Dlist {
private:
  class Node {
  public: 
    T _data;
    Node *_pre, *_next;
    Node(): _pre(nullptr), _next(nullptr) {}
    Node(const T &elem, Node *pre=nullptr, Node *next=nullptr): _data(elem), _pre(pre), _next(next) {}
  };

  Node *_head;
  size_t _size;

public:
  Dlist(): _head(new Node()), _size(0) { 
    _head->_next = _head->_pre = _head;
  }
  Dlist(size_t size, const T &elem=T()): _head(new Node()), _size(0) { 
    _head->_next = _head->_pre = _head;
    while(size--) push_back(elem);
  }
  Dlist(const initializer_list<T> &init): _head(new Node()), _size(0) {
    _head->_next = _head->_pre = _head;
    for(const T &x: init) push_back(x);
  }
  Dlist(const Dlist<T> &other): _head(new Node()), _size(0) {
    _head->_next = _head->_pre = _head;
    for(const T &elem: other) push_back(elem);
  }
  // 可通过其他容器来初始化链表
  template<typename Container>
  Dlist(const Container &other): _head(new Node()), _size(0) {
    _head->_next = _head->_pre = _head;
    for(const T &elem: other) push_back(elem);
  }
  ~Dlist() {
    clear();
    delete _head;
  }
  
  Dlist& operator = (const Dlist<T> &other) {
    if(this != &other) {
      clear();
      for(const T &elem: other) push_back(elem);
    }
    return *this;
  }
  template<typename Container>
  Dlist& operator = (const Container &other) {
    if(this != &other) {
      clear();
      for(const T &elem: other) push_back(elem);
    }
    return *this;
  }

  class iterator {
  private:
    Node *_ptr;
  public:
    using value_type = T;
    using __iterator_category = bidirectional_iterator_tag;
    using difference_type = ptrdiff_t;
    using pointor = T*;
    using reference = T&;
    iterator() {}
    iterator(Node *ptr): _ptr(ptr) {}
    T& operator*() { return _ptr->_data; }
    const T& operator*() const { return _ptr->_data; }
    T* operator->() const { return &(_ptr->_data); }
    iterator& operator++() {
      _ptr = _ptr->_next;
      return *this;
    }
    iterator operator++(int) {
      iterator temp = *this;
      _ptr = _ptr->_next;
      return temp;
    }
    iterator& operator--() {
      _ptr = _ptr->_pre;
      return *this;
    }
    iterator operator--(int) {
      iterator temp = *this;
      _ptr = _ptr->_pre;
      return temp;
    }
    iterator operator+(int32_t n) const {
      Node *rptr = _ptr;
      while(n-- > 0) rptr = rptr->_next; 
      while(n++ < 0) rptr = rptr->_pre; 
      return iterator(rptr);
    }
    iterator operator-(int32_t n) const {
      Node *rptr = _ptr;
      while(n-- > 0) rptr = rptr->_pre; 
      while(n++ < 0) rptr = rptr->_next; 
      return iterator(rptr);
    }

    bool operator!=(const iterator &other) const { return _ptr != other._ptr; }
    bool operator==(const iterator &other) const { return _ptr == other._ptr; }
  };
  iterator begin() const { return iterator(_head->_next); }
  iterator end() const { return iterator(_head); }
  bool empty() const { return _size == 0; }
  size_t size() const { return _size; }

  T& front() { 
    if(_size == 0) {
      throw out_of_range("access out of range");  // 抛出异常
    }
    return _head->_next->_data;
  }

  const T& front() const { 
    if(_size == 0) {
      throw out_of_range("access out of range");  // 抛出异常
    }
    return _head->_next->_data;
  }

  T& back() { 
    if(_size == 0) {
      throw out_of_range("access out of range");  // 抛出异常
    }
    return _head->_pre->_data;
  }

  const T& back() const { 
    if(_size == 0) {
      throw out_of_range("access out of range");  // 抛出异常
    }
    return _head->_pre->_data;
  }

  T& operator [](size_t pos) {
    if(pos < 0 || pos >= _size) {
      throw out_of_range("access out of range");  // 抛出异常
    }
    Node *now = _head->_next;
    for(size_t i = 0; i < pos; ++i) now = now->_next;
    return now->_data;
  }

  const T& operator [] (size_t pos) const {
    if(pos < 0 || pos >= _size) {
      throw out_of_range("access out of range");  // 抛出异常
    }
    Node *now = _head->_next;
    for(size_t i = 0; i < pos; ++i) now = now->_next;
    return now->_data;
  }
  
  // 查找某个元素的位置, 若找不到则返回-1
  int64_t find(const T &elem) const {
    Node *now = _head->_next;
    for(size_t idx = 0; idx < _size; ++idx) {
      if(now->_data == elem) return idx;
      now = now->_next;
    }
    return -1;
  }

  size_t count(const T &elem) const {
    size_t cnt = 0;
    Node *now = _head->_next;
    for(size_t idx = 0; idx < _size; ++idx) {
      if(now->_data == elem) ++cnt;
      now = now->_next;
    }
    return cnt;
  }

  bool push_front(const T &elem) {
    Node *tmp = _head->_next;
    _head->_next = new Node(elem, _head, tmp);
    tmp->_pre = _head->_next;
    ++_size;
    return true;
  }

  bool push_back(const T &elem) {
    _head->_pre = _head->_pre->_next = new Node(elem, _head->_pre, _head);
    ++_size;
    return true;
  }
  
  bool pop_front()  {
    if(_size == 0) return false;
    --_size;
    Node *tmp = _head->_next;
    _head->_next = tmp->_next;
    _head->_next->_pre = _head;
    delete tmp;
    return true;
  }

  bool pop_back() {
    if(_size == 0) return false;
    --_size;
    Node *tmp = _head->_pre;
    tmp->_pre->_next = tmp->_next;
    _head->_pre = tmp->_pre;
    delete tmp;
    return true;
  }
  
  // 参数: 插入的位置、插入的元素
  bool insert(size_t pos, const T &elem) {
    if(pos < 0 || pos > _size) return false;
    Node *now = _head->_next;
    while(pos--) now = now->_next;
    Node *tmp = new Node(elem, now->_pre, now);
    now->_pre->_next = tmp;
    now->_pre = tmp;
    ++_size;
    return true;
  }

  // 参数: 要删除的元素的下标
  bool erase(size_t pos) {
    if(pos >= _size) return false;
    Node *now = _head->_next;
    while(pos--) now = now->_next;
    --_size;
    now->_pre->_next = now->_next;
    now->_next->_pre = now->_pre;
    delete now;
    return true;
  }

  // 删除值为elem的元素, 可指定最大删除个数number
  size_t erase_elem(const T &elem, size_t number=SIZE_MAX) {
    if(number < 1 || _size == 0) return 0;
    number = min(number, _size);
    size_t cnt = 0;
    Node *now = _head->_next;
    for(size_t idx = 0; idx < _size; ++idx) {
      if(now->_data == elem) {
        --_size; --idx;
        now->_pre->_next = now->_next;
        now->_next->_pre = now->_pre;
        Node *tmp = now;
        now = now->_next;
        delete tmp;
        if(++cnt == number) break;
      } else now = now->_next;
    }
    return cnt;
  }

  bool clear() {
    _size = 0;
    Node *now = _head->_next;
    while(now != _head) {
      now = now->_next;
      delete now->_pre;
    }
    _head->_next = _head->_pre = _head;
    return true;
  }

  bool reverse() {
    if(_size > 1) {
      Node *now = _head->_pre, *rear = _head, *pre;
      while(now != _head) {
        pre = now->_pre;
        now->_pre = rear;
        rear = rear->_next = now;
        now = pre;
      }
      rear->_next = _head;
      _head->_pre = rear;
    }
    return true;
  }
};

template<typename T>
class Queue {
  Dlist<T> _st;
public:
  Queue(): _st() {}
  Queue(size_t size, const T &elem=T()): _st(size, elem) {}
  Queue(const initializer_list<T> &init): _st(init) {}
  size_t size() const { return _st.size(); }
  bool empty() const { return _st.empty(); }
  bool push(const T &elem) { return _st.push_back(elem); }
  bool pop() { return _st.pop_front(); }
  T& back() { return _st.back(); }
  const T& back() const { return _st.back(); }
  T& front() { return _st.front(); }
  const T& front() const { return _st.front(); }
};

int dp[101][101][2];

struct Node {
  int x, y, side;
};

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  int x, y, p, q; cin >> x >> y >> p >> q;
  memset(dp, 0x3f, sizeof(dp));
  Queue<Node> qq;
  qq.push({0, 0, 0});
  dp[0][0][0] = 0;
  while(!qq.empty()) {
    auto [xx, yy, side] = qq.front(); qq.pop();
    if((x-xx+q >= y-yy || x-xx == 0) && dp[xx][yy][side]+1 < dp[x-xx][y-yy][side^1]) {
      dp[x-xx][y-yy][side^1] = dp[xx][yy][side]+1;
      qq.push({x-xx, y-yy, side^1});
    }
    for(int num = 1; num <= min(p, x+y-xx-yy); ++num) {
      for(int cx = max(0, yy-y+num); cx <= min(num, x-xx); ++cx) {
        if((x-xx-cx+q >= y-yy-num+cx || x-xx-cx == 0) && dp[xx][yy][side]+1 < dp[x-xx-cx][y-yy-num+cx][side^1]) {
          dp[x-xx-cx][y-yy-num+cx][side^1] = dp[xx][yy][side]+1;
          qq.push({x-xx-cx, y-yy-num+cx, side^1});
        }
      }
    }
  }
  int ans = 1e9;
  for(int i = 0; i <= y; ++i) ans = min(ans, dp[0][i][1]);
  for(int i = 0; i <= y; ++i) ans = min(ans, dp[x][i][0]);
  if(ans == 1e9) cout << -1 << endl;
  else cout << ans << endl; 
  return 0;
}