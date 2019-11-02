/*
Time : O(NL)
Spcae: O(NL)
 */

#include <bits/stdc++.h>
using namespace std;

vector<size_t> getBuckets(string str, size_t size){
  vector<size_t> buckets(size, 0);
  for(char c: str) buckets[c] += 1;
  return buckets;
}

vector<string> groupAnagrams(vector<string> strs){
  int N = strs.size();
  vector< pair<vector<size_t>, int> > buckets(N); //with original index
  for(int i = 0; i < N; ++i){
    buckets[i] = make_pair( getBuckets(strs[i], 257), i );
  }
  sort(buckets.begin(), buckets.end());
  vector<string> resultStrs(N);
  for(int i = 0; i < N; ++i){
    resultStrs[i] = strs[ buckets[i].second ];
  }
  return resultStrs;
}

int main(void){
  int N;
  cin >> N;
  vector<string> strs(N);
  for(int i = 0; i < N; ++i){
    cin >> strs[i];
  }
  strs = groupAnagrams(strs);
  for(int i = 0; i < N; ++i){
    cout << strs[i] << endl;
  }
}
