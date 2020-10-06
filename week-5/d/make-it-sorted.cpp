#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

int main() {
  int n, temp;
  
  while (cin >> n) {
    vector<int> values(n, 0);
    int max_value = 0;
    for (int i=0; i<n; i++) {
      cin >> values[i];
      max_value = max(values[i], max_value);
    }
    vector<vector<int> > dp(n+1, vector<int>(max_value+1, 0));

    for (int i=0; i<n; i++) {
      int bestpast = 1e9;
      for (int j=0; j<=max_value; j++) {
        bestpast = min(bestpast, dp[i][j]);
        int current = abs(values[i] - j);
        dp[i+1][j] = bestpast + current;
      }
    }

    cout << *min_element(dp[n].begin(), dp[n].end()) << endl;
  }

  return 0;
}