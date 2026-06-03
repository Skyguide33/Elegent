//2026/2/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class BigInt {
private:
  vector<int> _num;
  int _is_neg;

  void trim() {
    while(!_num.empty() && _num.back() == 0) _num.pop_back();
    if(_is_neg && is_zero()) _is_neg = 0;
  }
  bool is_zero() const { return _num.empty(); }
  static int compare_abs(const BigInt& a, const BigInt& b) { 
    if(a._num.size() != b._num.size()) return a._num.size() < b._num.size()? -1: 1;
    for(int i = (int)a._num.size()-1; i >= 0; --i) {
      if(a._num[i] != b._num[i]) return a._num[i] < b._num[i]? -1: 1;
    }
    return 0;
  }
  static BigInt add_abs(const BigInt& a, const BigInt& b) {
    size_t len = max(a._num.size(), b._num.size())+1;
    BigInt res;
    res._num.resize(len, 0);
    int carry = 0;
    for(size_t i = 0; i < len; ++i) {
      int sum = carry;
      if (i < a._num.size()) sum += a._num[i];
      if (i < b._num.size()) sum += b._num[i];
      res._num[i] = sum%10;
      carry = sum/10;
    }
    res.trim();
    return res;
  }
  static BigInt sub_abs(const BigInt& a, const BigInt& b) {
    BigInt res;
    res._num.resize(a._num.size(), 0);
    int borrow = 0;
    for(size_t i = 0; i < a._num.size(); ++i) {
      int diff = a._num[i]-borrow;
      if(i < b._num.size()) diff -= b._num[i];
      if(diff < 0) {
        diff += 10;
        borrow = 1;
      } else borrow = 0;
      res._num[i] = diff;
    }
    res.trim();
    return res;
  }
public:
  BigInt(): _is_neg(0) {}
  BigInt(ll num) {
    // cout << "ll_to" << endl;
    if(num >= 0) _is_neg = 0;
    else {
      num *= -1;
      _is_neg = 1;
    }
    while(num) {
      _num.push_back(num%10);
      num /= 10;
    }
  }
  BigInt(const string &s) {
    for(size_t i = s.length()-1; i > 0; --i) _num.push_back(s[i]-'0');
    if(s[0] == '-') _is_neg = 1;
    else {
      _num.push_back(s[0]-'0');
      _is_neg = 0;
    }
    trim();
  }
  explicit BigInt(const char *s): BigInt(string(s)) {}

  BigInt(const BigInt &other): _num(other._num), _is_neg(other._is_neg) {}

  BigInt(BigInt &&other) noexcept
    : _num(std::move(other._num)), _is_neg(other._is_neg) {
    other._is_neg = 0;
  }
  BigInt& operator=(const BigInt &num) {
    if(this != &num) {
      _num = num._num;
      _is_neg = num._is_neg;
    }
    return *this;
  }
  BigInt& operator=(BigInt &&num) noexcept {
    // cout << "b" << endl;
    if(this != &num) {
       _num = move(num._num);
      _is_neg = num._is_neg;
      num._is_neg = 0;
    }
    return *this;
  }
  
  explicit operator ll() const {
    ll res = 0;
    for(int i = (int)_num.size()-1; i >= 0; --i) res = res*10+_num[i];
    return _is_neg? -res: res;
  }
  explicit operator string() const {
    // cout << "to_str" << endl;
    if(is_zero()) return "0";
    string res;
    if(_is_neg) res += '-';
    for(int i = (int)_num.size()-1; i >= 0; --i) res += char('0'+_num[i]);
    // cout << "tag" << endl;
    return res;
  }
  friend ostream& operator<<(ostream &out, const BigInt &num) {
    out << string(num);
    return out;
  }
  friend istream& operator>>(istream &in, BigInt &num) {
    string s; in >> s;
    num = BigInt(s);
    return in;
  }
  BigInt operator+() const { return *this; }
  BigInt operator-() const {
    BigInt res(*this);
    if (!res.is_zero()) res._is_neg ^= 1;
    return res;
  }
  bool operator==(const BigInt& other) const {
    return _is_neg == other._is_neg && _num == other._num;
  }
  bool operator!=(const BigInt& other) const { return !(*this == other); }
  bool operator<(const BigInt& other) const {
    if(_is_neg != other._is_neg) return _is_neg > other._is_neg;
    return (_is_neg? -1: 1)*compare_abs(*this, other) < 0; 
  }
  bool operator>=(const BigInt& other) const { return !(*this < other); }
  bool operator>(const BigInt& other) const {
    if(_is_neg != other._is_neg) return _is_neg < other._is_neg;
    return (_is_neg? -1: 1)*compare_abs(*this, other) > 0; 
  }
  bool operator<=(const BigInt& other) const { return !(*this > other); }
  BigInt operator+(const BigInt& other) const {
    if(_is_neg == other._is_neg) {
      BigInt res = add_abs(*this, other);
      res._is_neg = _is_neg;
      return res;
    }
    int cmp = compare_abs(*this, other);   
    if (cmp == 0) return BigInt();
    BigInt res;
    if (cmp > 0) {
      res = sub_abs(*this, other);
      res._is_neg = _is_neg;
    } else {
      res = sub_abs(other, *this);
      res._is_neg = other._is_neg;
    }
    return res;
  }
  BigInt operator-(const BigInt& other) const { return *this+(-other); }
  BigInt operator*(const BigInt& other) const { 
    BigInt res;
    int alen = _num.size(), blen = other._num.size();
    res._num.resize(alen+blen, 0);
    for(int i = 0; i < alen; ++i) {
      int carry = 0;
      for(int j = 0; j < blen || carry; ++j) {
        ll cur = res._num[i+j]+carry;
        if(j < blen) cur += _num[i]*other._num[j];
        res._num[i+j] = cur%10;
        carry = cur/10;
      } 
    }
    res._is_neg = _is_neg^other._is_neg;
    res.trim();
    return res;
  }
  BigInt operator/(const BigInt &other) const {
    assert(!other.is_zero() && "Division by zero");
    BigInt cur, res;
    const vector<int> &a = this->_num;
    vector<int> &c = res._num, &cvt = cur._num; 
    int len = a.size();
    cur._is_neg = other._is_neg;
    for(int i = len-1; i >= 0; --i) {
      cvt.insert(cvt.begin(), _num[i]);
      int l = 0, r = 9;
      while(l < r) {
        int mid = (l+r+1)>>1;
        if((!cur._is_neg && other*mid <= cur) || (cur._is_neg && other*mid >= cur)) l = mid;
        else r = mid-1;
      }
      c.push_back(l);
      cur = cur-other*l;
      while(!cvt.empty() && cvt.back() == 0) cvt.pop_back();
    }
    reverse(c.begin(), c.end());
    res.trim();
    res._is_neg = _is_neg^other._is_neg;
    return res;
  }
  BigInt operator%(const BigInt &other) const { return *this-*this/other*other; }
}; 

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  BigInt a, b; cin >> a >> b;
  BigInt c = a/b, r = a-b*c;
  cout << a/b << endl << a%b << endl;
  return 0;
}