/*
  Time: O(L)
  Space: O(L)
 */

#include <bits/stdc++.h>
using namespace std;

string strCompress(string str){
  string compressedStr;
  for(size_t i = 0; i < str.length(); ++i){
    size_t n = 1;
    while(i + 1 < str.length() && str[i + 1] == str[i]){
      i += 1;
      n += 1;
    }
    compressedStr.push_back( str[i] );
    compressedStr.append( to_string(n) );
  }
  if(compressedStr.length() < str.length()) return compressedStr;
  return str;
}

int main(void){
  string str;
  while(cin >> str){
    cout << strCompress(str) << endl;
  }
}
