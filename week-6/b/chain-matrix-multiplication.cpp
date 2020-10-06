#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void print (vector<vector<int> >& table) {
  for (int i=0; i<table.size(); i++) {
    for (int j=0; j<table.size(); j++) {
      if (j > 0) cout << " ";
      cout << table[i][j];
    }
    cout << endl;
  }
}

int main() {
  int n;

  while (cin >> n) {
    vector<int> items(n+1, 0);
    vector<vector<long long int> > table(n+1, vector<long long int>(n+1, 0));
    
    for (int i=0; i<items.size(); i++) {
      int temp;
      cin >> temp;
      items[i] = temp;
    }


    int count = 1;
    for (int step=2; step<items.size(); step++) {
      for (int row=0; row<items.size()-step; row++) { 
        int col = row + step;

        table[row][col] = LLONG_MAX;
        
        for (int k=row+1; k < col; k++) {
          long long int value = items[row]*items[col]*items[k];
          
          table[row][col] = min(
            table[row][col],
            table[k][col] + table[row][k] + value
          );
        }

      }
    }

    
    // print(table);

    cout << table[0][n] <<endl;
  }
  return 0;
}