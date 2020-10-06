#include <iostream>
#include <math.h>

using namespace std;

int main() {
  double x, y;
  while (cin >> x >> y) {
    double div = x / y;
    
    int round_num = ceil(div);

    if (round_num == -0) round_num = 0;
    
    cout << round_num << endl;
  }
  return 0;
}