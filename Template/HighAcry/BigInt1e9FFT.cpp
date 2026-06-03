//2026/2/24
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class BigInt {
  using ull = unsigned long long;
  typedef complex<long double> cp;
private:
  
  vector<int> _num;
  int _is_neg;
  static const ull BASE = 1000000000;
  static const int BASE_DIGIT = 9;

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
  
  static void fft(vector<cp> &a, const vector<int> &rev, int n, int flag) {
    const static long double PI = acos(-1);
    for(int i = 0; i < n; ++i) {
      if(i < rev[i]) swap(a[i], a[rev[i]]);
    }
    for(int h = 1; h < n; h <<= 1) {
      cp wn = exp(cp(0, flag*PI/h));
      for(int j = 0; j < n; j += h*2) {
        cp w(1, 0);
        for(int k = j; k < j+h; ++k) {
          cp x = a[k];
          cp y = w*a[k+h];
          a[k] = x+y;
          a[k+h] = x-y;
          w *= wn;
        }
      }
    }
    if(flag == -1) {
      for(int i = 0; i < n; ++i) a[i] /= n;
    }
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
      while(temp.length() < BASE_DIGIT) temp = '0'+temp;
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
    const static int FFT_B = 10000, FFT_BD = 4;
    const vector<int> &b_num = other._num;
    int len1 = _num.size(), len2 = b_num.size();
    int alen = len1*BASE_DIGIT, blen = len2*BASE_DIGIT;
    alen -= BASE_DIGIT-to_string(_num.back()).length();
    blen -= BASE_DIGIT-to_string(b_num.back()).length();
    int n1 = (alen+FFT_BD-1)/FFT_BD, n2 = (blen+FFT_BD-1)/FFT_BD;
    int maxn = max(n1, n2);
    int k = 1, n = 2;
    while((1<<k) < 2*maxn-1) ++k, n <<= 1;
    vector<cp> a(n), b(n);
    int idx1 = 0, idx2 = 0;
    __int128_t tt = 0, pw = 1;
    for(int i = 0; i < len1; ++i) {
      tt += pw*_num[i];
      pw *= BASE;
      while(pw >= FFT_B) {
        if(tt) {
          a[idx1] = tt%FFT_B;
          tt /= FFT_B;
        }
        pw /= FFT_B;
        ++idx1;
      }
    }
    if(tt) {
      a[idx1] = tt;
      tt = 0; 
    }
    pw = 1;
    for(int i = 0; i < len2; ++i) {
      tt += pw*b_num[i];
      pw *= BASE;
      while(pw >= FFT_B) {
        if(tt) {
          b[idx2] = tt%FFT_B;
          tt /= FFT_B;
        }
        pw /= FFT_B;
        ++idx2;
      }
    }
    if(tt) {
      b[idx2] = tt;
      tt = 0;
    }
    vector<int> rev(n*2);
    for(int i = 0; i < n; ++i) rev[i] = (rev[i>>1]>>1)|((1&i)<<(k-1));
    fft(a, rev, n, 1);
    fft(b, rev, n, 1);
    for(int i = 0; i < n; ++i) a[i] *= b[i];
    fft(a, rev, n, -1);
    vector<int> rvt(len1+len2, 0);

    int rn = 0;
    pw = 1;
    for(int i = 0; i < n; ++i) {
      tt += pw*(ull)(a[i].real()+0.5);
      pw *= FFT_B;
      while(pw >= (ll)BASE) {
        if(tt) {
          rvt[rn] = tt%BASE;
          tt /= BASE;
        }
        pw /= BASE;
        ++rn;
      }
    }
    if(tt) rvt[rn++] = tt;
    BigInt res(move(rvt), _is_neg^other._is_neg);
    res.trim();
    return res;
  }

  BigInt operator/(const BigInt &other) const {
    assert(!other.is_zero() && "Division by zero");
    BigInt cur;
    vector<int> &cvt = cur._num, rvt; 
    int len = _num.size();
    cur._is_neg = other._is_neg;
    for(int i = len-1; i >= 0; --i) {
      cvt.insert(cvt.begin(), _num[i]);
      int l = 0, r = BASE-1;
      while(l < r) {
        int mid = (l+r+1)>>1;
        if((cur._is_neg && other*mid >= cur) || (!cur._is_neg && other*mid <= cur)) l = mid;
        else r = mid-1;
      }
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
      if(p&1) res = res*b;
      b = b*b;
      p >>= 1;
    }
    return res;
  }
}; 

int main() {
  cin.tie(0) -> sync_with_stdio(0);
  // BigInt a, b; cin >> a >> b;
  // BigInt c = a*b;
  // cout << c << endl;
  auto srt = chrono::steady_clock::now();
  BigInt ans = BigInt::fast_power(3, 10000000);
  auto stop = chrono::steady_clock::now();
  auto elapsed = std::chrono::duration<double, std::micro>(stop-srt).count();
  cout << "res: " << ans << endl;
  cout << "time: " << fixed << elapsed/1000000 << endl;
  return 0;
}

