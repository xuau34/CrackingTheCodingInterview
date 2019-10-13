#include <bits/stdc++.h>
using namespace std;

/*
Time : O(2^N)
Space: O(2^N)
*/

vector<vector<int>> getPowerSet(vector<int> array){
  vector<vector<int>> powerSet;
  for(const auto& element: array){
    for(size_t i = 0, size =  powerSet.size(); i < size; ++i){
      vector<int> newSet(powerSet[i].begin(), powerSet[i].end());
      newSet.push_back(element);
      powerSet.push_back(newSet);
    }
    powerSet.push_back( vector<int>( 1, element) );
  }
  return powerSet;
}

int main(void){
  int N;
  cin >> N;
  vector<int> A;
  while(N--){
    int x;
    cin >> x;
    A.push_back(x);
  }
  vector<vector<int>> res = getPowerSet(A);
  for(const auto& row: res){
    for(const auto& ele: row){
      cout << ele << " ";
    }
    cout << endl;
  }
}
