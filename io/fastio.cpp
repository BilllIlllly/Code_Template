namespace fastio {
char buf[1 << 23], *p1 = buf, *p2 = buf, obuf[1 << 23], *O = obuf;
#define getchar() (p1 == p2 and (p2 = (p1 = buf) + std::fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
inline int read() {
  int ret = 1;
  bool flag = false;
  char ch = getchar();
  while (not isdigit(ch)) {
    if (ch == '-')
      flag = not flag;
    ch = getchar();
  }
  while (isdigit(ch)) {
    ret = (ret << 3) + (ret << 1) + (ch ^ 48);
    ch = getchar();
  }
  return flag ? ~ret + 1 : ret;
}
inline void write(int x) {
  if (x < 0) {
    *O++ = '-';
    x = -x;
  }
  static char s[20];
  int top = 0;
  do {
    s[top++] = x % 10 + '0';
    x /= 10;
  } while (x);
  while (top)
    *O++ = s[--top];
}
inline void endl() {
  *O++ = '\n';
}
inline void flush() {
  std::fwrite(obuf, 1, O - obuf, stdout);
  O = obuf;
}
}  // namespace fastio