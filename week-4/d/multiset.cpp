#include <iostream>
#include <vector>

using namespace std;

void print_arr(vector<int> arr) {
  for (int i=0; i<arr.size(); i++) {
    cout << arr[i] << ' ';
  }
  cout << endl;
}

int query(vector<int>& segtree, int idx, int n) {  
  int ans = 0;  
  for (idx += n; idx > 0; idx >>= 1) {
    ans += segtree[idx];
  }
    
  return ans;
}

void update(vector<int>& segtree, int l, int r, int n) {  
  int ans = 0; 

  for (l += n, r += n; l < r; l >>= 1, r >>= 1) { 
    if (l&1)
      segtree[l++] += 1;
    
    if (r&1)  
      segtree[--r] += 1;
  }
}


int main() {
  
  int intervals, range_size = 100000;
  cin >> intervals;
  
  vector<int> segtree(range_size*2, 0);

  for (int i=0; i<intervals; i++) {
    int left, right;
    cin >> left >> right;
    update(segtree, left-1, right, range_size);
  }

  for (int i=0; i<range_size; i++) {
    int quant = query(segtree, i, range_size);
    if (quant)
      cout << i+1 << " " << query(segtree, i, range_size) << endl;
  }

  cout << endl;
  return 0;
}