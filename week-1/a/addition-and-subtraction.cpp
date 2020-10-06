#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c;
    while(cin >> a >> b >> c) {
        int r1 = a - b;

        int idx1, idx2;

        if (c == 0) {
            idx1 = 0;
        } else if (r1 > 0 && c % r1 == 0) {
            idx1 = c / r1 * 2;
        } else {
            idx1 = -1;
        }

        if (c == a) {
            idx2 = 1;
        } else if (r1 > 0 && (c-a) % r1 == 0) {
            idx2 = (c-a) / r1 * 2 + 1;
        } else {
            idx2 = -1;
        }

        int ans = -1;
        if (idx1 > -1 && idx2 > -1) {
            ans = min(idx1, idx2);
        } else if (idx2 > -1) {
            ans = idx2;
        } else if (idx1 > -1) {
            ans = idx1;
        }

        cout << ans << endl;


    }
    return 0;
}