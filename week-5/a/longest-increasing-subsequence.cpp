#include <iostream>
#include <vector>
#include <string>

using namespace std;





int main() {
  int n;

  while (cin >> n) {
    vector<int> arr;
    vector<int> lis(n, 1);
    
    for (int i=0; i<n; i++) {
      int temp;
      cin >> temp;
      arr.push_back(temp);
    }

    int max_value = 0;
    for (int i=0; i<n; i++) {
      for (int j=i-1; j>=0; j--) {
        if (arr[i] > arr[j]) lis[i] = max(lis[i], lis[j] + 1);
      }
      max_value = max(max_value, lis[i]);
    }

    cout << max_value << endl;
  }
  return 0;
}