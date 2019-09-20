/*
  Time: O(N^2)
  Space: O(N)
 */

#include <bits/stdc++.h>
using namespace std;

void zeroMatrix( vector<vector<int>>& matrix ){
  size_t N = matrix.size();
  vector<bool> zeroRows(N, false);
  vector<bool> zeroCols(N, false);
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      if(matrix[i][j] != 0) continue;
      zeroRows[i] = true;
      zeroCols[j] = true;
    }
  }
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < N; ++j){
      if(!zeroRows[i] && !zeroCols[j]) continue;
      matrix[i][j] = 0;
    }
  }
}

int main(void){
  while(true){
    int N;
    cin >> N;
    vector<vector<int>> matrix(N, vector<int>(N, 0));
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        cin >> matrix[i][j];
      }
    }
    zeroMatrix(matrix);
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        cout << matrix[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
}
