#include <bits/stdc++.h>
using namespace std;

inline bool isValid(int rows, int cols, int x, int y){
  return x >= 0 && x < rows && y >= 0 && y < cols;
}

vector< pair<int,int> > constructPath( const vector< vector<pair<int,int>>>& prevs, int x, int y){
  vector< pair<int,int> > path;
  int rows = prevs.size(), cols = prevs[0].size();
  if(!isValid(rows, cols, x, y) || prevs[x][y].first < 0) return path;
  while( x + y > 0 ){
    path.push_back( make_pair(x,y) );
    const auto& prev = prevs[x][y];
    x = prev.first, y = prev.second;
  }
  path.push_back( make_pair(x,y) );
  return vector< pair<int,int> >(path.rbegin(), path.rend());
}

/*
Time: O(row * col)
Space: O(row * col)
The path is shortest for there's only two directions for it
*/
vector< pair<int,int> > findPath( const vector< vector<bool> >& Map){
  size_t rows = Map.size(), cols = Map[0].size();
  vector< vector< pair<int, int> > > prev( rows, vector< pair<int,int> >( cols, make_pair(-1, -1) ));
  vector< vector<int> > directions{{1, 0}, {0, 1}};
  prev[0][0] = make_pair(0, 0);
  for(int i = 0; i < rows; ++i){
    for(int j = 0; j < cols; ++j){
      if(prev[i][j].first < 0 || Map[i][j] ) continue;
      for(const auto& dir: directions){
        int X = i + dir[0], Y = j + dir[1];
        if(!isValid(rows, cols, X, Y) || Map[X][Y]) continue;
        prev[X][Y] = make_pair(i, j);
      }
    }
  }
  return constructPath( prev, rows - 1, cols - 1);
}

/*
Time: O(row * col)
Space: O(row * col)
*/
vector< pair<int, int> > findShortestPath( const vector< vector<bool>>& Map){
  size_t rows = Map.size(), cols = Map[0].size();
  vector< vector< pair<int, int> > > prev( rows, vector< pair<int,int> >( cols, make_pair(-1, -1) ));
  vector< vector<int> > directions{{1, 0}, {0, 1}};
  prev[0][0] = make_pair(0, 0);
  queue<pair<int,int>> que;
  que.push(make_pair(0, 0));
  while(!que.empty()){
    int x = que.front().first, y = que.front().second;
    que.pop();
    for(const auto& dir: directions){
      int X = x + dir[0], Y = y + dir[1];
      if(!isValid(rows, cols, X, Y) || Map[X][Y] || prev[X][Y].first >= 0) continue;
      prev[X][Y] = make_pair(x, y);
      que.push( make_pair(X, Y) );
    }
  }
  return constructPath( prev, rows - 1, cols - 1);
}

void output( vector<pair<int,int>> path){
  for(const auto& pos: path){
    cout << "(" << pos.first << ", " << pos.second << ") ";
  }
  cout << endl;
}

int main(void){
  int N, M;
  cin >> N >> M;
  vector< vector<bool> > Map(N, vector<bool>(M, false) );
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < M; ++j){
      bool x;
      cin >> x;
      Map[i][j] = x;
    }
  }
  cout << "Path - " << endl;
  output( findPath(Map) );
  cout << "Shortest Path - " << endl;
  output( findShortestPath(Map) );
}
