#include <iostream>
#include <set>
#include <vector>
#include <climits>

using namespace std;

int main() {
  int points;

  while (cin >> points) {
    int maxsum = INT_MIN;
    int minsum = INT_MAX;
    int maxdiff = INT_MIN;
    int mindiff = INT_MAX;
    
    for (int i=1; i<=points; i++) {
      int x, y, a, b, c, d;
      cin >> x >> y;

      if (x+y > maxsum) {
        maxsum = x+y;
        a = i;
      }

      if (x+y < minsum) {
        minsum = x+y;
        b = i;
      }

      if (x-y > maxdiff) {
        maxdiff = x-y;
        c = i;
      }

      if (x-y < mindiff) {
        mindiff = x-y;
        d = i;
      }

      if (maxsum-minsum > maxdiff-mindiff) {
        cout << a << " " << b << endl;
      } else {
        cout << c << " " << d << endl;
      }
    }
  } 
  return 0;
}