/*
Time : O(logN)
Space: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

int findHighestInRotated(const vector<int>& arr){
  int L = 0, M, R = arr.size();
  while(L + 1 < R){
    M = (L + R) >> 1;
    if(arr[M] >= arr[0]) L = M;
    else R = M;
  }
  return L;
}

int findNum(const vector<int>& arr, int x, int L, int R){
  if(x < arr[L] || x > arr[R - 1]) return -1;
  int M;
  while(L + 1 < R){
    M = (L + R) >> 1;
    if(arr[M] <= x) L = M;
    else R = M;
  }
  if(arr[L] == x) return L;
  return -1;
}

int findNumInRotated(const vector<int>& arr, int x){
  int highest = findHighestInRotated(arr);
  int targetIndex = findNum(arr, x, 0, highest + 1);
  if(targetIndex >= 0) return targetIndex;
  targetIndex = findNum(arr, x, highest + 1, arr.size());
  return targetIndex;
}

int main(void){
  int N;
  cin >> N;
  vector<int> arr(N);
  for(int i = 0; i < N; ++i) cin >> arr[i];
  int x;
  while( cin >> x ){
    cout << findNumInRotated(arr, x) << endl;
  }
}
