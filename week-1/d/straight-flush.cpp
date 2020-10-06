#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> rank;
    char suit[5];
    string input;
    
    while(getline(cin, input)) {
        rank.clear();
        int count = 0;
        bool same_suit = true;
        for(int i=0; i<input.size(); i+=3) {
            
            if (input[i] >= '2' && input[i] <= '9') {
                rank.push_back(input[i] - '0');
            }

            if (input[i] == 'A') {
                rank.push_back(1);
                rank.push_back(14);
            }

            if (input[i] == 'T') {
                rank.push_back(10);
            }

            if (input[i] == 'J') {
                rank.push_back(11);
            }

            if (input[i] == 'Q') {
                rank.push_back(12);
            }
            
            if (input[i] == 'K') {
                rank.push_back(13);
            }

            suit[count] = input[i+1];

            if(count > 0 && same_suit) {
                same_suit = suit[count] == suit[count-1];
            }
            
            count++;
        }

        if (same_suit) {
            int seq = 1;
            int max_seq = 1;
            sort(rank.begin(), rank.end());
            for (int i=1; i<rank.size(); i++) {
                if (rank[i] == rank[i-1] + 1) {
                    seq++;
                    if (max_seq < seq) {
                        max_seq = seq;
                    }
                } else {
                    seq = 1;
                }
            }
            if (max_seq == 5) {
                printf("YES\n");
            } else {
                printf("NO\n");
            }
        } else {
            printf("NO\n");
        }
    }

    
    return 0;
}