/*
  L <= str.length()
  Time: O(LlogL)
  Space: O(1)

  or
  Time: O(L)
  Space: O(1)
 */

#include "bits/stdc++.h"
using namespace std;

bool hasAllUniqueCharacter(string str){
  sort(str.begin(), str.end());
  int c = 0;
  for(int i = 0; i < str.length(); ++i){
    if(str[i] > c + 'a') return false;
    else if(str[i] == c + 'a') c += 1;
  }
  return c == 26;
}

bool hasAllUniqueCharacter2(string str){
  vector<bool> bucketChecker(26, false);
  for(char c: str){
    bucketChecker[c - 'a'] = true;
  }
  for(int i = 0; i < 26; ++i){
    if(bucketChecker[i] == false) return false;
  }
  return true;
}

int main(void){
  string str;
  while(cin>>str){
    cout << hasAllUniqueCharacter(str) << endl;
  }
}
