#include <iostream>
#include <vector>
#include <map>
#include <math.h>

using namespace std;


map<pair<int,int>, long long int> dp;
map<pair<int,int>, long long int>::iterator it;

long long int digits_sum(int sum, int len) {
  if (sum < 0) return 0;
  if (len <= 0) return 0;
  if (len == 1) {
    if (sum >= 1 && sum <= 9) return 1;
    else return 0;
  }

  it = dp.find(make_pair(sum,len));
  if (it != dp.end()) return dp[make_pair(sum,len)];


  long long int ans = 0;

  for (int i=0; i<=9; i++) {
    ans += digits_sum(sum-i, len-1);
  }

  dp[make_pair(sum,len)] = ans;
  return dp[make_pair(sum,len)];
}

int main() {
  int sum, len;
  
  
  while (cin >> sum >> len) {
    dp.clear();
    long long int ans;
    if (sum == 0 && len == 1) ans = 1;
    else ans = digits_sum(sum, len);
    cout << ans << endl;
  }

  return 0;
}