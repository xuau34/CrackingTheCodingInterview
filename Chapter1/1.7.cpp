/*
  Time: O(N^2)
  Space: O(1)
 
 */
#include <bits/stdc++.h>
using namespace std;

void rotateMatrix( vector<vector<int>>& matrix, bool left ){
  int N = matrix.size();
  for(int i = 0; i < N; ++i){
    for(int j = i + 1; j < N; ++j){
      swap(matrix[i][j], matrix[j][i]);
    }
  }
  if(left) return;
  for(int i = 0; i < N; ++i){
    for(int j = 0; j < (N - j - 1); ++j){
      swap(matrix[i][j], matrix[i][N - j - 1]);
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
    vector<vector<int>> rotated = matrix;
    rotateMatrix(rotated, true);
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        cout << rotated[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
    rotated = matrix;
    rotateMatrix(rotated, false);
    for(int i = 0; i < N; ++i){
      for(int j = 0; j < N; ++j){
        cout << rotated[i][j] << " ";
      }
      cout << endl;
    }
  }
}
