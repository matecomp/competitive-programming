#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<pair<int,int>, int> pd;

int binary_knapsack(int w, int i, vector<pair<int,int> >& items) {
  if (pd.find(make_pair(w,i)) != pd.end()) {
    return pd[make_pair(w,i)];
  }
  
  if (w == 0 || i < 0) return 0;
  if (w < 0) return -1;

  int without_item = binary_knapsack(w, i-1, items);
  int with_item = 0;
  int ans;
  
  if (items[i].first <= w) {
    with_item = items[i].second + binary_knapsack(w-items[i].first, i-1, items);
  }

  if (with_item > without_item) ans = with_item;
  else ans = without_item;
  
  pd[make_pair(w,i)] = ans;
  return ans;
}

vector<int> make_path(int w, int idx, vector<pair<int,int> >& items){
  vector<int> ans;

  for (int i=idx; i>=0; i--) {
    if (w-items[i].first >= 0 && binary_knapsack(w-items[i].first, i-1, items) + items[i].second == binary_knapsack(w, i, items)) {
      ans.push_back(i+1);
      w -= items[i].first;
    }
  }

  return ans;
}



int main() {
  int n, m;

  while (cin >> n >> m) {
    vector<pair<int,int> > items;
    pd.clear();
    
    for (int i=0; i<n; i++) {
      int w, v;
      cin >> w >> v;
      items.push_back(make_pair(w,v));
    }

    
    int value = binary_knapsack(m,n-1,items);
    vector<int> path = make_path(m,n-1,items);

    cout << path.size() << endl;
    for (int i=path.size()-1; i>=0; i--) {
      cout << path[i] << " ";
    }

    cout << endl;
    // cout << value << endl;
  }
  return 0;
}