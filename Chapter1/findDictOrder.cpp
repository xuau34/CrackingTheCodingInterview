#include <bits/stdc++.h>
using namespace std;

typedef struct _node{
  vector<bool> children;
  int indegree;
  _node(): indegree(-1), children(26, 0){
  }
} node;

void insertToGraph( vector<node>& nodes, const vector<string>& dictionary, int L = 0, int R = -1, int ith = 0){
  if(R < 0) R = dictionary.size();
  int curIdx = tolower(dictionary[L][ith]) - 'a';
  for(int i = L+1; i < R; ++i){
    int nextIdx = tolower(dictionary[i][ith]) - 'a';
    if(curIdx == nextIdx) continue;
    nodes[curIdx].children[nextIdx] = true;
    nodes[nextIdx].indegree += 1;
    curIdx = nextIdx;
  }
  for(int l = L, r; l < R; l = r ){
    r = l + 1;
    if(dictionary[l].size() == ith+1) continue;
    for(; r < R; ++r){
      if(dictionary[l][ith] != dictionary[r][ith]) break;
    }
    if(r == l + 1) continue;
    insertToGraph(nodes, dictionary, l, r, ith+1);
  }
}

string getLexicalOrder(vector<string> dictionary){
  vector<node> nodes(26);

  for(const string& word: dictionary){
    for(char c: word){
      int idx = tolower(c) - 'a';
      nodes[idx].indegree = 0;
    }
  }

  insertToGraph( nodes, dictionary ); // modified nodes, indegree, lower_case

  string order;
  queue<int> que;
  for(int i = 0; i <26; ++i){
    if(nodes[i].indegree == 0){
      que.push(i);
    }
  }
  while(!que.empty()){
    int curIdx = que.front();
    que.pop();
    order.push_back( curIdx + 'a');
    for(int i = 0; i < 26; ++i){
      if(nodes[curIdx].children[i] == false) continue;
      nodes[i].indegree -= 1;
      if(nodes[i].indegree == 0) que.push(i);
    }
  }
  return order;
}

int main(void){
  int T = 1;
  while(T--){
    int N;
    cin >> N;
    vector<string> dict(N);
    for(int i = 0; i < N; ++i) cin >> dict[i];
    cout << getLexicalOrder(dict) << endl;
  }
}
