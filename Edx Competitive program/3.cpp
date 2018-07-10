#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <stack>
#include <cmath>

bool comp (std::pair<int, int> a, std::pair<int, int> b) {
    return a.first < b.first;
}

void w3p2() {
  std::ifstream inp("input.txt");
  std::ofstream out("output.txt");
  int n;
  inp >> n;
  int A[n];
  for (int i = 0; i < n; ++i) {
      inp >> A[i];
      // A.push_back(std::pair<int, int>(v, i));
  }
  int s_p = 0;
  for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        A[i] > A[j] ? ++s_p : 0;  
      }
    
  }
  out << s_p;
}


void w3p4 () {
  std::ifstream inp("input.txt");
  std::ofstream out("output.txt");
  int n;
  inp >> n;
  int A[n];
  for (int i = n - 1; i >= 0; --i) {
      A[i] = n - i - 1; 
      // A.push_back(std::pair<int, int>(v, i));
  }
  std::cout << std::ceil(n / 2);
  std::reverse(A, &A[int((n / 2) + 1)]);
  std::reverse(&A[int((n / 2) + 1)], &A[n]);
  std::reverse(A, &A[n]);
  for (auto i : A) {

      out << i << " ";
  }  
}

void w3p6() {
  std::ifstream inf("input.txt");
  std::ofstream ouf("output.txt");
  int n, k;
  inf >> n >> k;
  std::vector<std::vector<int>> M(k, std::vector<int>(n / k + 1, 9999));
  for (int i = 0; i < n; ++i) {
    inf >> M[i % k][i / k]; 
  }
  for (auto& vec : M) {
      std::sort(vec.begin(), vec.end());
  }
  for (int i = 0; i + 1 < n; i++) {
      int oo = M[i % k][i / k];
      int tt = M[(i + 1) % k][i / k];
      if (M[i % k][i / k] > M[(i + 1) % k][(i + 1) / k]) {
        ouf << "NO";
        return;
      }
  }
  ouf << "YES";
}




void w3p7 () {
  int n, a;
  std::cin >> n;
  std::vector<int> T (101);
  for (int i = 0; i < n; ++i) {
    std::cin >> a;
    T[a] += 1;
  }
  a = 0;
  for (int i = 0; i < 101; ++i) {
    a = std::max(a, T[i]);
  }
  std::cout << a; 
}


int main(int argc, char const *argv[])
{
    /* code */
    try {
      w3p7();
    } catch (const char* msg) {
        std::cout << msg;
    }
    
    return 0;
}
