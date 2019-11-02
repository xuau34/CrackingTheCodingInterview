/*
Time : O(A + B)
Spcae: O(A)
*/

#include <bits/stdc++.h>
using namespace std;

void mergeToA(vector<int>& A, vector<int> B, int Alen){
  for(int a = 0, b = 0; a < A.size() && b < B.size(); ){
    if(a >= Alen){
      A[a++] = B[b++];  //!!!
    }else if(A[a] <= B[b]) a += 1;
    else{
      swap( A[a], B[b] );
    }
  }
}

int main(void){
  int N, M;
  cin >> N >> M;
  vector<int> A(N + M), B(M);
  for(int i = 0; i < N; ++i) cin >> A[i];
  for(int i = 0; i < M; ++i) cin >> B[i];
  mergeToA(A, B, N);
  for(int x : A){
    cout << x << " ";
  }
  cout << endl;
}
