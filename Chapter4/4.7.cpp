/*
Time : O(N)
Space: O(N)
 */

#include <bits/stdc++.h>
using namespace std;

typedef struct _Node{
  string title;
  vector<int> children;
  int degree;
  _Node(): degree(0){
  }
} Node;

vector<string> buildOrder(const vector<string>& projects, const vector<vector<string>>& dependencies){
  unordered_map<string, int> indexes;
  vector<Node> nodes(projects.size());
  for(int i = 0; i < projects.size(); ++i){
    indexes[projects[i]] = i;
    nodes[i].title = projects[i];
  }
  for(const auto& dependency: dependencies){
    int x = indexes[dependency[0]], y = indexes[dependency[1]];
    nodes[x].children.push_back(y);
    nodes[y].degree += 1; //in-degree
  }
  queue<int> que;
  for(int i = 0; i < nodes.size(); ++i){
    if(nodes[i].degree == 0) que.push(i);
  }
  vector<string> order;
  while(!que.empty()){
    int X = que.front();
    que.pop();
    order.push_back( nodes[X].title );
    for(int child: nodes[X].children){
      nodes[child].degree -= 1;
      if(nodes[child].degree == 0) que.push(child);
    }
  }
  if(order.size() < projects.size()) throw "There's no valid order to complete them all";
  return order;
}

int main(void){
  int N;
  cin >> N;
  vector<string> projects;
  for(int i = 0; i < N; ++i){
    string str;
    cin >> str;
    projects.push_back(str);
  }
  int M;
  cin >> M;
  vector<vector<string>> dependencies;
  for(int i = 0; i < M; ++i){
    string x, y;
    cin >> x >> y;
    dependencies.push_back({x,y});
  }
  vector<string> order = buildOrder(projects, dependencies);
  for(int i = 0; i < order.size(); ++i){
    if(i) cout << ", ";
    cout << order[i];
  }
  cout << endl;
}
