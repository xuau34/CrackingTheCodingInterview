/*
Time: O(32) = O(1)
Space: O(1)
 */

#include <bits/stdc++.h>
using namespace std;

bool equal(double x, double y){
  return (x - y) == 0;  //!!!!!
}

string binaryToString( double num ){
  if(num > 1 || num < 0) return "invalid input";
  if( equal(num, 1) ) return "1";
  if( equal(num, 0) ) return "0";
  double two = 1;
  double sum = 0;
  string str( "0." );
  while( !equal(num, sum) && str.length() < 32 ){
    two /= 2;
    if(sum + two > num) str.push_back( '0' );
    else{
      str.push_back( '1' );
      sum += two;
    }
  }
  if( !equal(num,sum) ){
    return "ERROR.";
  }
  return str;
}

int main(void){
  double num;
  cin >> num;
  cout << binaryToString(num) << endl;
}
