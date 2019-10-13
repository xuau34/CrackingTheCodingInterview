#include <bits/stdc++.h>
using namespace std;

bool duplicated( const vector<int>& A ){
  for(int i = 1; i < A.size(); ++i){
    if(A[i] == A[i - 1]) return true;
  }
  return false;
}

int findMagicIndexD(const vector<int>& A){
  for(int i = 0; i < A.size(); ++i){
    if( A[i] == i ) return i;
    if( A[i] > i && A[i] < A.size() && A[ A[i] ] == A[i]) return A[i];
    while(i + 1 < A.size() && A[i] == A[i + 1]) ++i;
  }
  return -1;
}

//Wrong
int findMagicIndexD2(const vector<int>& A){
  vector<pair<int, int>> ranges;
  vector<int> compressedA;
  int L = 0;
  for(int i = 1; i < A.size(); ++i){
    if(A[i] == A[i - 1]) continue;
    compressedA.push_back(A[i - 1]);
    ranges.push_back( pair<int,int>(L, i) );
    L = i;
  }
  compressedA.push_back(A.back());
  ranges.push_back( pair<int,int>(L, A.size()) );
  int M, R = compressedA.size();
  L = -1;
  while(L + 1 < R){
    M = (L + R) >> 1;
    int l = ranges[M].first, r = ranges[M].second;
    int value = compressedA[M];
    if(value < l) R = M;
    else if(value >= r) L = M;
    else return value;
  }
  return -1;
}

int findMagicIndex(const vector<int>& A){
  if( duplicated(A) ) return findMagicIndexD(A);
  int L = -1, M, R = A.size();
  while(L + 1 < R){
    M = (L + R) >> 1;
    if(A[M] > M) R = M;
    else if(A[M] == M) return M;
    else L = M;
  }
  return -1;
}

int main(void){
  int N;
  cin >> N;
  vector<int> A;
  while(N--){
    int x;
    cin >> x;
    A.push_back(x);
  }
  cout << findMagicIndex(A) << endl;
}
