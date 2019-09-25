/*
Time: O(bit number)
Space: O(bit number);
 */

#include <bits/stdc++.h>
using namespace std;

int flipBitToWin( int num ){
  int maxLen = 0;
  bitset<32> bitNum(num);
  for(int l = 0, i = 0, r = 0; i < 32; ++i){
    if(r <= i){
      r = i;
      while(r + 1 < bitNum.size() && bitNum[r + 1]){
        r += 1;
      } 
    }

    if(i - 1 >= 0 && !bitNum[i - 1]){
      l = i;
    }
    int len = r - l + 1;
    if(len > maxLen) maxLen = len;
  }
  return maxLen;
}

int main(void){
  bitset<32> num;
  cin >> num;
  cout << flipBitToWin(num.to_ulong()) << endl;
}
