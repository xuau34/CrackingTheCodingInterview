/*
T(N) = 2*T(N-1) + T(1)
     = 4*T(N-2) + 3*T(1)
     = ( 1+2+4+8+...+2^(N-1) ) * T(1)
Time : O(2^N)
Space: O(2^N)
 */

#include <bits/stdc++.h>
using namespace std;

void _HanoiTowers( vector<stack<int>>& stacks, int N, int from, int pool, int to){
  if(N > 1){
    _HanoiTowers( stacks, N - 1, from, to, pool );
  }
  stacks[to].push( stacks[from].top() );
  stacks[from].pop();
  //printf("%d => %d: plate - %d\n", from, to, stacks[to].top());
  if(N > 1){
    _HanoiTowers( stacks, N - 1, pool, from, to );
  }
}

void HanoiTowers( vector<stack<int>>& stacks ){
  if(stacks.size() < 3) exit(-1);
  int N = stacks.front().size();
  if(stacks.front().size() == 0) return;
  _HanoiTowers( stacks, N, 0, 1, 2);
}

int main(void){
  int N;
  cin >> N;
  vector<stack<int>> stacks(3);
  for(int i = N; i > 0; --i) stacks.front().push(i);
  HanoiTowers( stacks );
  for(int i = 0; i < 3; ++i ){
    cout << i << ": ";
    while(stacks[i].size()){
      cout << stacks[i].top() << " ";
      stacks[i].pop();
    }
    cout << endl;
  }
}
