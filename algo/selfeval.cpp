#include <bits/stdc++.h>

const std::string file = "file";
std::string cpp(const std::string& s) {
  return s + ".cpp";
}
std::string exe(const std::string& s) {
  return s + ".exe";
}
std::string in(const std::string& s) {
  return s + ".in";
}
std::string out(const std::string& s) {
  return s + ".out";
}
std::string ans(const std::string& s) {
  return s + ".ans";
}
int system(const std::string& s) {
  return system(s.c_str());
}

int main() {
  if (system("g++ " + cpp(file) + " -o " + exe(file) + " -O2 -Wall -Wextra -Wshadow -Wconversion")) {
    std::cout << "CE" << '\n';
    return 0;
  }

  int ll, rr;
  std::cin >> ll >> rr;

  for (int i = ll; i <= rr; ++i) {
    std::string _in = in(file + std::to_string(i));
    std::string _ans = ans(file + std::to_string(i));
    system("copy /Y " + _in + " " + in(file));
    auto st = std::chrono::steady_clock::now();
    system(exe(file));
    long double t = std::chrono::duration<long double>(std::chrono::steady_clock::now() - st).count();
    std::cout << "Test #" << i << ": ";
    if (system("fc.exe /w " + _ans + " " + out(file) + " > nul"))
      std::cout << "WA" << std::endl;
    else
      std::cout << "AC" << std::endl;
    std::cout << "Time: " << t << "s" << std::endl;
  }
}