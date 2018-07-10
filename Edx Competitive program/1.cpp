#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <stack>

template <class T>
std::vector<T> read_line(int n, std::ifstream* inp) {
  std::vector<T> v(n);
  for (int i = 0; i < n; i++) {
    *inp >> v[i];   
  }
  return v;
}

bool comp_up(int a, int b) {return a >= b; }

void w2p7(std::ifstream *inp, std::ofstream *out){
  int n;
  *inp >> n;
  std::vector<int> v = read_line<int>(n, inp);
  std::vector<int> st;

    //std::vector<int>::iterator ind;
    //ind = std::lower_bound(st.begin(), st.end(), v, comp_up);


  for (auto fcup : v) {
      if (!st.size()) {
          st.push_back(1);
      } else if (!fcup) {
          int val = st[st.size() - 1] + 1;
          std::vector<int>::iterator ind;
          ind = std::lower_bound(st.begin(), st.end(), val, comp_up);
          st[st.size() - 1] = *ind;
          *ind = val;
          //(ind, st[st.size() - 1]);  
      } else {
          st.push_back(1);
      }
  }
  
  *out << st.size() << '\n';
  //std::vector<int> group(st[0], 0);
  //for (auto stac : st) {
  //  ++group[stac];
  //}
  //int i = 1;
  int count = 1;
  for (int i = 1; i <= st.size(); ++i) {
    if (st[i] != st[i-1] || i == st.size()) {
      *out << st[i-1] << count << '\n';
      count = 1;  
    } else {
       ++count; 
    }
  }
}

struct blade {
  blade* next;
  blade* prev;
  int v; 
};

struct bdl {
  blade* top = NULL;
  blade* last = NULL;
  //std::vector<blade> backet;
  //blade* b = &backet.back();
  //blade* a = NULL;

  void push(int val) {
      //backet.push_back(blade());
      blade *sbl = new blade();
      sbl->prev = last;
      sbl->v = val;
      if (top == NULL) {
          // sbl->prev = NULL;
          top = sbl;
          last = top;
      } else {
        last->next = sbl;
        
        last = last->next;
      }
  }
  void pop() {
      last = last->prev;
      delete last->next;
      last->next = NULL;
      // del last;
  }

};

void w2p8() {
  std::ifstream inp("input.txt");
  std::ofstream out("output.txt");
  bdl table;
  int n;
  inp >> n;
  blade* mid = NULL;
  bool even = false;
  for (int i = 0; i < n; ++i) {
    std::string act; 
    inp >> act;
    if (act == "add") {
      int b;
      inp >> b;
      table.push(b);
      even = !even;
      if (mid == NULL && table.top != table.last) {
        even = true;
        mid = table.top;
      } else if (mid != NULL && even) {
        mid = mid->next;
      } 
    } else if (act == "take") {
      even = !even;
      table.pop();
      if (!even) {
        mid = mid->prev;
      }
    } else {
       table.last->next = table.top;
       table.top->prev = table.last;
       table.top = mid->next;
       std::swap(table.last, mid);
       
    }
    if (mid != NULL) {
    std::cout << mid->v;
    }
  } 


  blade* m = table.top;
  out << m->v << ' ';
  while (m != table.last) {
      m = m->next;
      out << m->v << ' ';
  }
}


int main(int argc, char const *argv[])
{
    // std::ifstream inp("input.txt");
    // std::ofstream out("output.txt");
    // //w2p7(&inp, &out);
    // std::map<int, int> cnt;
    // ++cnt[1];
    // ++cnt[1];
    // ++cnt[100];
    // auto first = cnt.begin();
    //         ++cnt[first->first + 1];
    //         if (first->second == 1) {
    //             cnt.erase(first);
    //         } else {
    //             --first->second;
    //         }

    // std::cout << cnt[0]; 
    w2p8();

    

    return 0;

}
