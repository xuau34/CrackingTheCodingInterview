/*
 dfs = O(N)
Time : O(N)
Space : O(N)
 */

#include <bits/stdc++.h>
using namespace std;

void dfs(const vector<vector<int>>& graph, vector<bool>& visited, int x){
  visited[x] = true;
  for(int y: graph[x]){
    if(visited[y]) continue;
    dfs(graph, visited, y);
  }
}

bool pathExists(const vector<vector<int>>& graph, int X, int Y){
  vector<bool> visited(graph.size(), false);
  dfs(graph, visited, X);
  if(visited[Y]) return true;
  fill(visited.begin(), visited.end(), false);
  dfs(graph, visited, Y);
  if(visited[X]) return true;
  return false;
}

int main(void){
  int N;
  cin >> N;
  vector<vector<int>> graph(N);
  for(int i = 0; i < N; ++i){
    int M;
    cin >> M;
    for(int j = 0; j < M; ++j){
      int y;
      cin >> y;
      graph[i].push_back(y);
    }
  }
  while(true){
    int X, Y;
    cin >> X >> Y;
    cout << "There's a path between " << X << " and " << Y << ": " << pathExists(graph, X, Y) << endl;
  }
}
