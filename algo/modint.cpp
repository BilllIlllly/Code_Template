template <int mod>
struct mint {
  i64 v;
  mint(i64 val) {
    v = val % mod;
    if (v < 0)
      v += mod;
  }
  mint& operator++() {
    if (++v >= mod)
      v -= mod;
    return *this;
  }
  mint& operator--() {
    if (--v < 0)
      v += mod;
    return *this;
  }
  mint operator++(int) {
    mint tmp = *this;
    ++(*this);
    return tmp;
  }
  mint operator--(int) {
    mint tmp = *this;
    --(*this);
    return tmp;
  }
  mint& operator+=(mint b) {
    v += b.v;
    if (v >= mod)
      v -= mod;
    return *this;
  }
  mint& operator-=(mint b) {
    v -= b.v;
    if (v < 0)
      v += mod;
    return *this;
  }
  mint& operator*=(mint b) {
    v *= b.v;
    v %= mod;
    return *this;
  }
  mint& operator/=(mint b) {
    v *= b.pow().v;
    v %= mod;
    return *this;
  }
  mint& operator<<=(int b) {
    v *= mint(2).pow(b).v;
    v %= mod;
    return *this;
  }
  mint pow(i64 power = mod - 2) {
    mint ret = 1, base = *this;
    while (power) {
      if (power & 1ll)
        ret *= base;
      base *= base;
      power >>= 1ll;
    }
    return ret;
  }
  friend mint operator+(mint a, mint b) { return a += b; }
  friend mint operator-(mint a, mint b) { return a -= b; }
  friend mint operator*(mint a, mint b) { return a *= b; }
  friend mint operator/(mint a, mint b) { return a /= b; }
  friend mint operator<<(mint a, int b) { return a <<= b; }

  friend std::istream& operator>>(std::istream& in, mint& a) {
    i64 x;
    in >> x;
    a = x;
    return in;
  }
  friend std::ostream& operator<<(std::ostream& out, const mint& a) {
    return out << a.v;
  }
};

constexpr static int mod = 998244353;
using Z = mint<mod>;