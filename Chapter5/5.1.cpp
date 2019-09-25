/*
Time : O(1)
Space: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

bitset<32> insertion(bitset<32> N, bitset<32> M, int i, int j){
  bitset<32> mask = ~(((1 << (j - i + 1)) - 1) << i);
  N &= mask;
  N |= M << i;
  return N;
}

int main(void){
  bitset<32> N, M;
  int i, j;
  cout << "N, M: ";
  cin >> N >> M;
  cout << "i, j: ";
  cin >> i >> j;
  cout << insertion(N, M, i, j) << endl;
}
