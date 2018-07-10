#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <cmath>
#include <queue>
#include <unordered_map>

#define forn(i, n) for(int i = 0; i < n; ++i)

void w4p4() {
  std::ifstream inp("input.txt");
  std::ofstream out("output.txt");
  int n, v;
  inp >> n;
  std::priority_queue<int, std::vector<int>> qu;
  for (int i = 0; i < n; ++i) {
    inp >> v;
    qu.push(v);
  }
  int delta = 0, k;
  inp >> k;
  while (qu.top() - delta > 0) {
    ++delta;
    int x = qu.top() - k + 1;
    qu.pop();
    qu.push(x);
  }
  out << delta;
}

void p1() {
  int n, v, st = 0;
  std::vector<int> vec;
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    std::cin >> v;
    if (v == 1) {
      st += 1;
      vec.push_back(1);
    } else {
      vec.back() += 1;
    }
  }
  std::cout << st << "\n";
  for (auto i : vec) {
    std::cout << i << " ";
  }
}

void p2() {
  std::string s, t;
  // std::cin >> s >> t;
  //std::cin.ignore(26, '\n');
  std::getline(std::cin, s);
  //std::cin.clear();
  std::getline(std::cin, t);
  //std::cin.clear();
  
  // std::cin >> t;
  int k = 0, i = 1;
  while (i <= t.size() && i <= s.size() && s[s.size() - i] == t[t.size() - i]) {
    k += 2;
    ++i;  
  }
  std::cout << s.size() + t.size() - k;
}

void p3() {
  int n, d = 0, k =0;
  std::unordered_map<int, int> dpow;
  while (k <= 1e9) {
    k = std::pow(2,++d);
    dpow.insert({k, 0});
  }
  k = 0; 
  std::cin >> n;
  std::vector<int> vec(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> vec[i];
    //std::cout << std::pow(2, i);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (i != j && dpow.count(vec[i] + vec[j])) {
        k++;
        break;
      }
    }
  }
  std::cout << n - k;
}

void p4() {
  int n, k = 0;
  std::string a;
  std::getline(std::cin, a);
  n = a.size();
  for (int i = 0; i < n; ++i) {
    int s = 0;
    for (int j = i; j < n; ++j) {
      if (!a[j]) {
        ++k;
        i = j;
        break;
      }
      s += int(a[j]);
      if (s % 3 == 0) {
        i = j;
        ++k;
        break;
      }
    }
  }
  std::cout << k;
}

void p5() {
  int n, m, ls = 0, rs = 0, k = 0;
  std::cin >> n >> m;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  auto ind = std::find(a.begin(), a.end(), m);
  for (auto l = ind; l >= a.begin(); --l) {
    ls = 0;
    rs = 0;
    for (int r = l - a.begin(); r < n; ++r) {
      if (a[r] <= m) {
        ++ls;
      } else {
        ++rs;
      }
      if (rs >= ind - a.begin() && (ls == rs || ls == rs + 1)) {
        ++k;
      }
    }
  }
  std::cout << k;
}



int main(int argc, char const *argv[])
{
    //p3();
    forn(i, 10) {
     std::cout << i;
    }
    return 0;
}
