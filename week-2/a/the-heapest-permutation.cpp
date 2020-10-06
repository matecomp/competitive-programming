#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#define INT_MAX __INT_MAX__

using namespace std;
vector<vector<int> > matrix;
vector<int> best_seq;
unordered_map<int,int> vis;
int min_cost;


void reset() {
  matrix.clear();
  best_seq.clear();
  vis.clear();
  min_cost = INT_MAX;
}

void read_input(vector<vector<int> > &matrix, int n) {
  matrix.clear();
  vis.clear();
  int read_value;
  for (int i=0; i<n; i++) {
    vector<int> line;
    for (int j=0; j<n; j++) {
      cin >> read_value;
      line.push_back(read_value);
    }
    matrix.push_back(line);
  }
}

int cost(vector<int> seq) {
  int total_cost = 0;
  for (int i=0; i<seq.size()-1; i++) {
    total_cost += matrix[seq[i]-1][seq[i+1]-1];
  }
  return total_cost;
}

void print(vector<int> array) {
  for (int i=0; i<array.size(); i++) {
    if (i == 0) {
      printf("%d", array[i]);
    } else {
      printf(" %d", array[i]);
    }
  }
  printf("\n");
}

void backtracking(int n, vector<int> seq) {
  if (seq.size() == n) {
    int total_cost = cost(seq);
    if (total_cost < min_cost) {
      min_cost = total_cost;
      best_seq = seq;
    }
    return;
  }

  for (int i=1; i<=n; i++) {
    if (vis[i]) continue;
    seq.push_back(i);
    vis[i] = 1;
    backtracking(n, seq);
    seq.pop_back();
    vis[i] = 0;
  }

  return;
}


int main() {
  int n;
  while (cin >> n) {
    reset();
    read_input(matrix, n);

    backtracking(n, vector<int>());
    print(best_seq);
  }
  return 0;
}