#include <iostream>
#include <set>

using namespace std;

int main() {
  int points;
  set<pair<int,int> > my_set;

  while (cin >> points) {
    my_set.clear();
    for (int i=1; i<=points; i++) {
      int current_point;
      cin >> current_point;
      
      pair<int,int> coord = make_pair(current_point, i);
      my_set.insert(coord);

      int min_coord = min(my_set.begin()->second, my_set.rbegin()->second);
      int max_coord = max(my_set.begin()->second, my_set.rbegin()->second);

      cout << min_coord << ' ' << max_coord << endl;
    }
  } 
  return 0;
}