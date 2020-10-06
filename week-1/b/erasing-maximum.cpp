#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;

int main() {
    int n;
    
    while(scanf("%d", &n) != EOF) {
        std::vector<int> list;
        int max = 0;
        int max_freq = 0;
        int remove_idx = 0;
        for (int i=0; i<n; i++) {
            int temp;
            scanf("%d", &temp);
            list.push_back(temp);
            if (temp > max) {
                max = temp;
                max_freq = 1;
                remove_idx = i;
            } else if (temp == max) {
                max_freq++;
                if (max_freq == 3) remove_idx = i;
            }
        }

        list.erase(list.begin()+remove_idx);

        for (int i=0; i<list.size(); i++) {
            if (i == list.size() - 1) {
                printf("%d\n", list[i]);
            } else {
                printf("%d ", list[i]);
            }
        }
    }

    
    return 0;
}