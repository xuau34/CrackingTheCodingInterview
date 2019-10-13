
/*
DFS
Time : O(N * M);
Space: O(N * M);
*/

inline bool isValid(int N, int M, int x, int y){
  return x >= 0 && x < N && y >= 0 && y < M;
}

void paintFill( vector<vector<int>>& screen, pair<int,int> point, int newColor, int oriColor ){
  const static vector< vector<int> > directions{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  int X = point.first, Y = point.second;
  int N = screen.size(), M = screen[0].size();
  if( !isValid(N, M, X, Y) || screen[X][Y] != oriColor ) return;
  screen[X][Y] = newColor;
  for( const auto& direction: directions){
    int x = X + direction[0], y = Y + direction[1];
    if( !isValid(N, M, x, y) || screen[x][x] == newColor ) continue;
    paintFill(screen, make_pair(x,y), newColor, oriColor );
  }
}

void paintFill( vector<vector<int>>& screen, pair<int,int> point, int newColor ){
  int X = point.first, Y = point.second;
  int N = screen.size(), M = screen[0].size();
  if( !isValid(N, M, X, Y) || screen[X][Y] == newColor ) return;
  paintFill( screen point, newColor, screen[X][Y] );
}
