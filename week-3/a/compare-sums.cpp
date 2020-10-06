#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
  int n;
  while (cin >> n) {
    double a = 0.0, b = 0.0;
    
    for (int i=0; i<n; i++) {
      double temp;
      cin >> temp;
      a += temp;
    }

    for (int i=0; i<n; i++) {
      double temp;
      cin >> temp;
      b += temp;
    }

    char delimiter;
    
    if (abs(a - b) <= 0.0009) delimiter = '=';
    else if (a > b) delimiter = '>';
    else if (a < b) delimiter = '<';

    cout << "SUM(A)" << delimiter << "SUM(B)" << endl;
  }
  return 0;
}