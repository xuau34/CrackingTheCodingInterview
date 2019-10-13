/*
Time : O(L * L!)
Space: O(L!)
 */

#include <bits/stdc++.h>
using namespace std;

string nextPermutation( string str ){
  size_t L = str.size() - 1;
  while(L > 0 && str[L] <= str[L - 1]) L -= 1;  //
  if(L == 0) return "";
  size_t bigger = str.size() - 1;
  while(str[L-1] >= str[bigger]) bigger -= 1; //
  swap(str[L-1], str[bigger]);
  reverse( begin(str) + L, end(str));
  return str;
}

vector<string> getPermutations(string str){
  sort(str.begin(), str.end());
  vector<string> permutations(1, str);
  while(true){
    str = nextPermutation(str);
    if(str.empty()) break;
    permutations.push_back(str);
  }
  return permutations;
}

int main(void){
  string str;
  cin >> str;
  auto permutations = getPermutations(str);
  for(const auto& permutation: permutations){
    cout << permutation << endl;
  }
}
