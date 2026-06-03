//2026/2/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class BigInt {
  using ull = unsigned long long;

private:
  vector<int> _num;
  int _is_neg;
  static const ull BASE = 1000000000;

  void trim() {
    while(!_num.empty() && _num.back() == 0) _num.pop_back();
    if(_is_neg && is_zero()) _is_neg = 0;
  }

  bool is_zero() const { return _num.empty(); }

  static int compare_abs(const BigInt &a, const BigInt &b) { 
    if(a._num.size() != b._num.size()) return a._num.size() < b._num.size()? -1: 1;
    for(int i = (int)a._num.size()-1; i >= 0; --i) {
      if(a._num[i] != b._num[i]) return a._num[i] < b._num[i]? -1: 1;
    }
    return 0;
  }

  static BigInt add_abs(const BigInt &a, const BigInt &b) {
    size_t len = max(a._num.size(), b._num.size())+1;
    BigInt res;
    res._num.resize(len, 0);
    int carry = 0;
    for(size_t i = 0; i < len; ++i) {
      int sum = carry;
      if (i < a._num.size()) sum += a._num[i];
      if (i < b._num.size()) sum += b._num[i];
      res._num[i] = sum%BASE;
      carry = sum/BASE;
    }
    res.trim();
    return res;
  }

  static BigInt sub_abs(const BigInt &a, const BigInt &b) {
    BigInt res;
    res._num.resize(a._num.size(), 0);
    int borrow = 0;
    for(size_t i = 0; i < a._num.size(); ++i) {
      int diff = a._num[i]-borrow;
      if(i < b._num.size()) diff -= b._num[i];
      if(diff < 0) {
        diff += BASE;
        borrow = 1;
      } else borrow = 0;
      res._num[i] = diff;
    }
    res.trim();
    return res;
  }
  
  BigInt(const vector<int> &vct, int is_neg): _num(vct), _is_neg(is_neg) {} 

  BigInt(vector<int> &&vct, int is_neg): _is_neg(is_neg) { _num = move(vct); }

public:
  BigInt(): _is_neg(0) {}

  BigInt(ll num) {
    if(num >= 0) _is_neg = 0;
    else {
      num *= -1;
      _is_neg = 1;
    }
    if(num) _num.push_back(num);
  }

  BigInt(const string &s) {
    if(s.empty()) {
      _is_neg = 0;
      return;
    }
    int pw = 1, temp = 0, start = !isdigit(s[0]);
    for(int i = s.length()-1; i >= start; --i) {
      temp += pw*(s[i]-'0');
      pw *= 10;
      if(pw == BASE) {
        _num.push_back(temp);
        pw = 1;
        temp = 0;
      }
    }
    if(temp) _num.push_back(temp);
    if(s[0] == '-') _is_neg = 1;
    else  _is_neg = 0;
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
    if(this != &num) {
       _num = move(num._num);
      _is_neg = num._is_neg;
      num._is_neg = 0;
    }
    return *this;
  }
  
  explicit operator ll() const {
    if(is_zero()) return 0;
    ll res = _num[0];
    return _is_neg? -res: res;
  }

  explicit operator string() const {
    if(is_zero()) return "0";
    string res;
    if(_is_neg) res += '-';
    int len = _num.size();
    res += to_string(_num[len-1]); 
    for(int i = len-2; i >= 0; --i) {
      string temp = to_string(_num[i]);
      while(temp.length() < 9) temp = '0'+temp;
      res += temp;
    }
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
        ull cur = res._num[i+j]+carry;
        if(j < blen) cur += 1ull*_num[i]*other._num[j];
        res._num[i+j] = cur%BASE;
        carry = cur/BASE;
      } 
    }
    res._is_neg = _is_neg^other._is_neg;
    res.trim();
    return res;
  }

  BigInt operator/(const BigInt &other) const {
    assert(!other.is_zero() && "Division by zero");
    BigInt cur;
    vector<int> &cvt = cur._num, rvt; 
    int len = _num.size();
    cur._is_neg = other._is_neg;
    // vector<BigInt> temp;
    // for(int i = 0; i <= 10; ++i) temp.push_back(other*i);
    for(int i = len-1; i >= 0; --i) {
      cvt.insert(cvt.begin(), _num[i]);
      int l = 0, r = BASE-1;
      while(l < r) {
        int mid = (l+r+1)>>1;
        if((cur._is_neg && other*mid >= cur) || (!cur._is_neg && other*mid <= cur)) l = mid;
        else r = mid-1;
      }
      // int pos = (cur._is_neg? lower_bound(temp.begin(), temp.end(), cur)
      //   : upper_bound(temp.begin(), temp.end(), cur)-1)-temp.begin();
      cur = cur-other*l;
      rvt.push_back(l);
    }
    reverse(rvt.begin(), rvt.end());
    BigInt res(move(rvt), _is_neg^other._is_neg);
    res.trim();
    return res;
  }
  
  BigInt operator%(const BigInt &other) const { return *this-*this/other*other; }
  
  static BigInt mod_power(BigInt b, int p, const BigInt &MOD) {
    BigInt res = 1;
    while(p) {
      if(p&1) res = res*b%MOD;
      b = b*b%MOD;
      p >>= 1;
    }
    return res;
  }

  static BigInt fast_power(BigInt b, int p) {
    BigInt res = 1;
    while(p) {
      // cout << "p=" << p << endl;
      if(p&1) res = res*b;
      b = b*b;
      p >>= 1;
    }
    return res;
  }
}; 

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  BigInt a, b; cin >> a >> b;
  cout << a-b << endl;
  return 0;
}