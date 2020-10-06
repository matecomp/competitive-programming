#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
  
using namespace std;

bool isInside(int x, int y, int r, int c) {
  if (x < 0 || x >= r) return false;
  if (y < 0 || y >= c) return false;
  return true;
}

void pulse_in(vector<vector<int> > &matrix, int x, int y) {
  int dx[8] = {0, 0, -1, 1, 1, -1, 1, -1};
  int dy[8] = {-1, 1, 0, 0, 1, -1, -1, 1};

  for (int i=0; i<8; i++) {
    int newx = x + dx[i];
    int newy = y + dy[i];
    if (isInside(newx, newy, matrix.size(), matrix[x].size())) {
      matrix[x][y]++;
    }
  }
}

void pulse_out(vector<vector<int> > &matrix, int x, int y) {
  int dx[8] = {0, 0, -1, 1, 1, -1, 1, -1};
  int dy[8] = {-1, 1, 0, 0, 1, -1, -1, 1};

  for (int i=0; i<8; i++) {
    int newx = x + dx[i];
    int newy = y + dy[i];
    if (isInside(newx, newy, matrix.size(), matrix[x].size()) && matrix[newx][newy] > 0) {
      matrix[newx][newy]--;
      if (matrix[newx][newy] == 0) matrix[newx][newy] = -1;
    }
  }
}


void init(vector<vector<int> > &matrix, int r, int c) {
  for (int i=0; i<matrix.size(); i++) {
    for (int j=0; j<matrix[i].size(); j++) {
      pulse_in(matrix, i, j);
    }
  }
}

void remove_king(vector<vector<int> > &matrix, int x, int y) {
  int dx[8] = {0, 0, -1, 1, 1, -1, 1, -1};
  int dy[8] = {-1, 1, 0, 0, 1, -1, -1, 1};

  matrix[x][y] = -1;
  for (int i=0; i<8; i++) {
    int newx = x + dx[i];
    int newy = y + dy[i];
    int count = 0;
    if (isInside(newx, newy, matrix.size(), matrix[x].size()) && matrix[newx][newy] > 0) {
      matrix[newx][newy] = 0;
      pulse_out(matrix, newx, newy);
    }
  }
}

bool remove_best_king(vector<vector<int> > &matrix) {

  int x_max = -1, y_max = -1;
  int max = 0;

  for (int i=0; i<matrix.size(); i++) {
    for (int j=0; j<matrix[i].size(); j++) {
      if (max < matrix[i][j]) {
        x_max = i;
        y_max = j;
        max = matrix[i][j];
      }
    }
  }

  if (x_max == -1 && y_max == -1) return false;
  remove_king(matrix, x_max, y_max);
  return true;
}

int count_remove_king(vector<vector<int> > &matrix) {
  int count = 0;
  for (int i=0; i<matrix.size(); i++) {
    for (int j=0; j<matrix[i].size(); j++) {
      if (matrix[i][j] == -1) count++;
    }
  }
  return count;
}


int main() {
  int r, c;
  while (cin >> r >> c) {
    vector<vector<int> >matrix(r, vector<int>(c,0));
    init(matrix, r, c);

    while (remove_best_king(matrix)) {}

    int count = count_remove_king(matrix);

    if (count) cout << r*c  - count << endl;
    else cout << 0 << endl;
  }
  return 0;
}