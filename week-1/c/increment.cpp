#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string input;
    
    while(cin >> input) {
        int digits = input.size();
        bool flag = true;
        for (int i=0; i<input.size(); i++) {
            if (input[i] != '9') {
                flag = false;
                break;
            }
        }

        if (flag) digits++;
        cout << digits << endl;
    }

    
    return 0;
}