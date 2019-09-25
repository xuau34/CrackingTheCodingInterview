/*
Time : O(bit number)
Space: O(bit number)
 */

#include <bits/stdc++.h>
using namespace std;

template <size_t N>
int conversion( bitset<N> X, bitset<N> Y){
  int num = 0;
  for(int i = 0; i < X.size(); ++i){
    if(X[i] != Y[i]) num += 1;
  }
  return num;
}

int main(void){
  bitset<32> X, Y;
  cin >> X >> Y;
  cout << conversion(X,Y) << endl;
}
