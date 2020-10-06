#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
  
using namespace std;


int main() {
  int n;
  while (cin >> n) {
    vector<int> list(n, 0);
    for (int i=0; i<n; i++) {
      cin >> list[i];
    }

    for (int i=0; i<n; i++) {
      cout << list[i];
    }
  }
  return 0;
}