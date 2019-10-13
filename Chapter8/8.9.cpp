/*
Time : O(N^2 * combination), combination <= (N/2)!
Space: O(N*combination)
 
 */

#include <bits/stdc++.h>
using namespace std;

vector<string> append( vector<string> strs, char c ){
  for( string& str: strs ) str.push_back(c);
  return strs;
}

vector<string> getParens(int N, int M = 0){
  static vector<vector< vector<string> >> dp(1, vector< vector<string> >(1, vector<string>(1, "") ) );
  if(N < 0 || M < 0 || N < M) return vector<string>();
  if( dp.size() <= N ) dp.resize(N+1);
  if( dp[N].size() <= M ) dp[N].resize(M+1);
  if(dp[N][M].size() > 0) return dp[N][M];
  dp[N][M] = append( getParens(N - 1, M - 1 ), '(' ); //
  auto tempParens = append( getParens(N, M + 1), ')' ); //
  dp[N][M].insert( dp[N][M].end(), tempParens.begin(), tempParens.end() );
  return dp[N][M];
}

int main(void){
  int N ;
  cin >> N;
  vector<string> res = getParens(N);
  for(const string& str: res){
    cout << str << endl;
  }
}
