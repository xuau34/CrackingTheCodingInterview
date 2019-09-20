/*

  Time: O(len^2)  because string::find && string::substr is generally linear in the len
  Space: O(len)

*/

#include "bits/stdc++.h"
using namespace std;

string URLify(string str, int len){
  string url;
  bool isFirstWord = true;
  int prevN = 0;
  for(auto n = str.find(' ', prevN); n <= len; n = str.find(' ', prevN)){
    if(!isFirstWord) url.append("%20");
    isFirstWord = false;
    url.append(str.substr(prevN, n-prevN));
    prevN = n + 1;
  }
  return url;
}

int main(void){
  cout << URLify("Mr John Smith    ", 13) << endl;
}
