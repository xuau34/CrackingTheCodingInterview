/*
Time : O(bit number)
Space: O(bit number)
 */

#include <bits/stdc++.h>
using namespace std;

bitset<32> nextLarger( bitset<32> num ){
  int idx = 0;
  for(; idx + 1 < num.size(); ++idx){
    if(num[idx] && !num[idx + 1]) break;
  }
  if(idx + 1 == num.size()) return num;
  num ^= ((1<<2)-1) << idx;
  return num;
}

bitset<32> nextSmaller( bitset<32> num ){
  int idx = 0;
  for(; idx + 1 < num.size(); ++idx){
    if(!num[idx] && num[idx + 1]) break;
  }
  if(idx + 1 == num.size()) return num;
  num ^= ((1<<2)-1) << idx;
  return num;
}

int main(void){
  bitset<32> num;
  cin >> num;
  cout << nextLarger(num) << ", " << nextSmaller(num) << endl;
}
