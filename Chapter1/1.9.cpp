/*
  Time: O(L)
  Space: O(L)
 */
#include "bits/stdc++.h"
using namespace std;

bool isSubstring(string x, string y){
  return x.find(y) != string::npos;
}

vector< vector<int> > getBuckets(string x){
  vector< vector<int> > ret(x.length());
  vector<int> cnts(256, 0);
  for( int i = 0; i < x.length(); ++i){
    cnts[ x[i] ] += 1;
    ret[i] = cnts;
  }
  return ret;
}

bool isRotated(string a, string b){
  if(a.length() != b.length()) return false;
  size_t L = a.length();
  vector< vector<int> > bucketsA = getBuckets(a);
  vector< vector<int> > bucketsB = getBuckets(b);
  int l = 0;
  for(; l < L; ++l){
    bool next = false;
    for(int i = 0; i < 256; ++i){
      int cntA = bucketsA.back()[i];
      if(L - l > 1) cntA -= bucketsA[L - l - 2][i];
      if(cntA != bucketsB[l][i]){
        next = true;
        break;
      }
    }
    if(!next) break;
  }
  if(l == L) return false;
  l += 1;
  return isSubstring(a, b.substr(l, L-l) + b.substr(0, l));
}

int main(){
  string a, b;
  while( cin >> a >> b){
    if( isRotated(a, b) ) cout << "yes" << endl;
    else cout << "oh uh" << endl;
  }

}
