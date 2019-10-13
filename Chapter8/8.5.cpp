/*
Time : O(log( min(a, b) ))
Space: O(log( min(a, b) ))
 */

#include <bits/stdc++.h>
using namespace std;

int _multiply(int a, int b){
  if(b == 0) return 0;
  if(b & 1){
    return a + (_multiply(a, b>>1) << 1);
  }
  return _multiply(a, b>>1) << 1;
}

int multiply(int a, int b){
  if(a < b) swap(a, b);
  return _multiply(a, b);
}

int main(void){
  int a, b;
  cin >> a >> b;
  cout << multiply(a, b) << endl;
}
