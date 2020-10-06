#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

void print_map(unordered_map<char,int> mymap) {
  for ( auto local_it = mymap.begin(); local_it!= mymap.end(); ++local_it ) {
    cout << " " << local_it->first << ":" << local_it->second;
  }
  cout << endl;
}

void print_arr(vector<unordered_map<char,int> > arr) {
  for (int i=0; i<arr.size(); i++) {
    print_map(arr[i]);
  }
}

char most_frequent(unordered_map<char,int> mymap) {
  char letter = '-';
  int max = 0;
  for ( auto local_it = mymap.begin(); local_it != mymap.end(); ++local_it ) {
    if (local_it->second >= max) {
      max = local_it->second;
      letter = local_it->first;
    }
  }

  return letter;
}

unordered_map<char,int> join(unordered_map<char,int> map1, unordered_map<char,int> map2) {
  for ( auto local_it = map2.begin(); local_it!= map2.end(); ++local_it ) {
    map1[local_it->first] += local_it->second;
  }

  return map1;
}

void build(vector<unordered_map<char,int> >& tree, string word) {
  int n = word.size();
  // insert leaf nodes in tree 
  for (int i=0; i<n; i++) {  
    tree[n+i][word[i]]++;
  }
    
  // build the tree by calculating parents 
  for (int i = n - 1; i > 0; --i) {
    tree[i] = join(tree[i<<1], tree[i<<1 | 1]);
  }
}

char query(vector<unordered_map<char,int> >& tree, int l, int r, int n) {  
  unordered_map<char,int> res; 
      
  // loop to find the sum in the range 
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) { 
    if (l&1)
      res = join(res, tree[l++]);
    
    if (r&1)  
      res = join(res, tree[--r]);
  }
    
  return most_frequent(res);
}


int main() {
  vector<unordered_map<char,int> > tree;
  string word;
  int cases, l, r;

  while (cin >> word) {
    cin >> cases;
    tree = vector<unordered_map<char,int> >(word.size()*2, unordered_map<char,int>());
    build(tree, word);
    for (int c=1; c<=cases; c++) {
      cin >> l >> r;
      cout << query(tree, l-1, r, word.size()) << endl;
    }
  } 
  return 0;
}