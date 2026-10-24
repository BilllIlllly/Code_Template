struct SuffixArray {
  int n;
  std::string s;
  int m;
  std::vector<int> sa;
  std::vector<int> rk1;
  std::vector<int> rk2;
  std::vector<int> c;

  SuffixArray(const std::string& str) {
    s = " " + str;
    n = s.length() - 1;
    m = 130;

    sa.resize(n + 1);
    rk1.resize(2 * n + 1, 0);
    rk2.resize(2 * n + 1, 0);
    c.resize(std::max(n + 1, m + 1), 0);
  }

  void build() {
    for (int i = 1; i <= n; ++i)
      ++c[rk1[i] = s[i]];
    for (int i = 1; i <= m; ++i)
      c[i] += c[i - 1];
    for (int i = n; i >= 1; --i)
      sa[c[rk1[i]]--] = i;

    for (int k = 1; k <= n; k <<= 1) {
      int p = 0;
      for (int i = n - k + 1; i <= n; ++i)
        rk2[++p] = i;
      for (int i = 1; i <= n; ++i)
        if (sa[i] > k)
          rk2[++p] = sa[i] - k;

      for (int i = 1; i <= m; ++i)
        c[i] = 0;
      for (int i = 1; i <= n; ++i)
        ++c[rk1[rk2[i]]];
      for (int i = 1; i <= m; ++i)
        c[i] += c[i - 1];
      for (int i = n; i >= 1; --i)
        sa[c[rk1[rk2[i]]]--] = rk2[i];

      rk2[sa[1]] = 1, p = 1;
      for (int i = 2; i <= n; ++i)
        rk2[sa[i]] = (rk1[sa[i]] == rk1[sa[i - 1]] and rk1[sa[i] + k] == rk1[sa[i - 1] + k]) ? p : ++p;
      rk1.swap(rk2);

      if (p >= n)
        break;
      m = p;
    }
  }
};