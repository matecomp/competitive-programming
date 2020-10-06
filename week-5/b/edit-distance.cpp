#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_matrix(vector<vector<int> > matrix, string word1, string word2) {
  for (int i=0; i<word1.size(); i++) {
    if (i==0) cout << "- -";
    cout << " " << word1[i];
  }
  cout << endl;

  for (int i=0; i<matrix.size(); i++) {
    if (i==0) cout << "-" << " ";
    else cout << word2[i-1] << " ";
    for (int j=0; j<matrix[i].size(); j++) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}



int edit_distance(string word1, string word2, int insert_cost, int delete_cost, int substitution_cost) {
  vector<vector<int> > ED(word2.size() + 1, vector<int>(word1.size() + 1, 0) );

  for (int i=0; i<=word1.size(); i++) ED[0][i] = i*delete_cost;
  for (int i=0; i<=word2.size(); i++) ED[i][0] = i*insert_cost;
  
  for (int i=1; i<ED.size(); i++) {
    for (int j=1; j<ED[i].size(); j++) {
      
      ED[i][j] = min(
        ED[i-1][j] + insert_cost,
        ED[i][j-1] + delete_cost
      );

      int diff = (word1[j-1] == word2[i-1]) ? 0 : substitution_cost;
      ED[i][j] = min(
        ED[i][j],
        ED[i-1][j-1] + diff
      );

    }
  }

  // print_matrix(ED, word1, word2);

  return ED[word2.size()][word1.size()];
}



int main() {
  int n, m, i, d, s;
  
  
  while (cin >> n >> m) {
  
    string word1, word2;
    
    cin >> word1;
    cin >> word2;

    cin >> i >> d >> s;

    // cout << i << " " << d << " " << s << endl;

    int ans = edit_distance(word1, word2, i, d, s);

    cout << ans << endl;
  }

  return 0;
}