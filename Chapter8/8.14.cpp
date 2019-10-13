/*
Time : O(len * len)
Space: O(len * len)
 */

#include <bits/stdc++.h>
using namespace std;

int booleanParen(string str, bool result, vector< vector<vector<int>>>& dp, int L, int R){
  if((R - L) & 1 == false) return 0;
  if( dp[L][R][result] >= 0 ) return dp[L][R][result];
  if(R - L == 1){
    if( str[L] - '0' == result ) return dp[L][R][result] = 1;
    else return dp[L][R][result] = 0;
  }
  dp[L][R][result] = 0;
  for(int oper = L + 1; oper < R; oper += 2 ){
    switch( str[oper] ){
      case '&':
        if(result){
          dp[L][R][result] += booleanParen(str, true, dp, L, oper) * booleanParen(str, true, dp, oper+1, R);
        }else{
          dp[L][R][result] += booleanParen(str, true, dp, L, oper) * booleanParen(str, false, dp, oper+1, R);
          dp[L][R][result] += booleanParen(str, false, dp, L, oper) * booleanParen(str, true, dp, oper+1, R);
          dp[L][R][result] += booleanParen(str, false, dp, L, oper) * booleanParen(str, false, dp, oper+1, R);
        }
        break;
      case '|':
        if(result){
          dp[L][R][result] += booleanParen(str, true, dp, L, oper) * booleanParen(str, true, dp, oper+1, R);
          dp[L][R][result] += booleanParen(str, true, dp, L, oper) * booleanParen(str, false, dp, oper+1, R);
          dp[L][R][result] += booleanParen(str, false, dp, L, oper) * booleanParen(str, true, dp, oper+1, R);
        }else{
          dp[L][R][result] += booleanParen(str, false, dp, L, oper) * booleanParen(str, false, dp, oper+1, R);
        }
        break;
      case '^':
        if(result){
          dp[L][R][result] += booleanParen(str, true, dp, L, oper) * booleanParen(str, false, dp, oper+1, R);
          dp[L][R][result] += booleanParen(str, false, dp, L, oper) * booleanParen(str, true, dp, oper+1, R);
        }else{
          dp[L][R][result] += booleanParen(str, true, dp, L, oper) * booleanParen(str, true, dp, oper+1, R);
          dp[L][R][result] += booleanParen(str, false, dp, L, oper) * booleanParen(str, false, dp, oper+1, R);
        }
        break;
    }
  }
  return dp[L][R][result];
}

int booleanParen(string str, bool result){
  int len = str.length();
  vector< vector<vector<int>> > dp( len, vector<vector<int>>(len+1, vector<int>(2,-1)) );
  return booleanParen(str, result, dp, 0, len);
}

int booleanParen2(string str, bool result){
  int operandLen = (str.length() >> 1) + 1;
  vector< vector<vector<int>> > dp( operandLen, vector<vector<int>>(operandLen+1, vector<int>(2,0)) );
  for(int range = 1; range <= operandLen; range += 1){
    for(int L = 0, R = range; R <= operandLen; L += 1, R += 1){
      if(R - L == 1){
        if(str[L<<1] - '0' == result){
          dp[L][R][result] = 1;
        }else{
          dp[L][R][result^1] = 1;
        }
        continue;
      }
      for(int oper = (L<<1) + 1; oper < (R<<1); oper += 2){
        int r = (oper >> 1) + 1;
        switch( str[oper] ){
          case '&':
            dp[L][R][1] += dp[L][r][1] * dp[r][R][1];
            dp[L][R][0] += dp[L][r][1] * dp[r][R][0];
            dp[L][R][0] += dp[L][r][0] * dp[r][R][1];
            dp[L][R][0] += dp[L][r][0] * dp[r][R][0];
            break;
          case '|':
            dp[L][R][1] += dp[L][r][1] * dp[r][R][1];
            dp[L][R][1] += dp[L][r][1] * dp[r][R][0];
            dp[L][R][1] += dp[L][r][0] * dp[r][R][1];
            dp[L][R][0] += dp[L][r][0] * dp[r][R][0];
            break;
          case '^':
            dp[L][R][1] += dp[L][r][1] * dp[r][R][0];
            dp[L][R][1] += dp[L][r][0] * dp[r][R][1];
            dp[L][R][0] += dp[L][r][1] * dp[r][R][1];
            dp[L][R][0] += dp[L][r][0] * dp[r][R][0];
            break;
        }

      }
    }
  }
  return dp[0][operandLen][result];
}

int main(void){
  string str;
  int res;
  cin >> str >> res;
  cout << booleanParen2(str, res) << endl;
}
