#include <bits/stdc++.h>
using namespace std;

size_t searchSparse(vector<string> strs, string target){
  int L = 0, M, R = strs.size();
  while(L + 1 < R){
    M = (L + R) >> 1;
    if(strs[M].length() == 0){
      int l = M - 1, r = M + 1;
      while(l > 0 && strs[l].length() == 0) l -= 1;
      while(r < strs.size() && strs[r].length() == 0) r += 1;
      if(strs[l] == target) return l;
      else if(strs[r] == target) return r;
      else if(strs[l] > target) R = l;
      else L = r;
    }else{
      if(strs[M] <= target) L = M;
      else R = M;
    }
  }
  return L;
}

int main(void){
  vector<string> strs{"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""};
  string target;
  while(cin >> target){
    cout << searchSparse(strs, target) << endl;
  }
}
