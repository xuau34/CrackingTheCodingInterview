/*

Time : O(8!)
Space: O(8! * 8^2)
 
 */

#include <bits/stdc++.h>
using namespace std;

inline bool isValid(int N, int M, int x, int y){
  return x >= 0  && x < N && y >= 0 && y < M;
}

void fillMap( vector<vector<int>>& Map, int x, int y, int val){
  static const vector< vector<int> > directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
  for(const auto& direction: directions){
    int dx = direction[0], dy = direction[1];
    for(int i = x + dx, j = y + dy; isValid(8, 8, i, j); i += dx, j += dy ){
      Map[i][j] += val;
    }
  }
}

void printMap( vector<vector<int>>& Map){
  for(const auto& row: Map){
    for(int ele: row){
      if(ele < 0) cout << "Q ";
      else cout << ". ";
    }
    cout << endl;
  }
  cout << endl;
}

void eightQueens(int row = 0, vector<vector<int>> Map = vector<vector<int>>(8, vector<int>(8, 0)) ){
  if(row > 7){
    printMap( Map );
    return;
  }
  for(int col = 0; col < 8; ++col){
    if( Map[row][col] != 0 ) continue;
    fillMap( Map, row, col, +1 );
    Map[row][col] = -1;
    eightQueens( row + 1, Map );
    Map[row][col] = 0;
    fillMap( Map, row, col, -1 );
  }
}

int main(void){
  eightQueens();
}
