/*
Time : O(bit number)
Space: O(bit number)
*/

#include <bits/stdc++.h>
using namespace std;

template <size_t N>
bitset<N> pairwiseSwap(bitset<N> X){
  for(int i = 0; i + 1 < X.size(); i += 2){
    bool bit = X[i];
    X[i] = X[i+1];
    X[i+1] = bit;
  }
  return X;
}

int main(void){
  bitset<32> X;
  cin >> X;
  cout << pairwiseSwap(X) << endl;
}
