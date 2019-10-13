#include <bits/stdc++.h>
using namespace std;

/*
Top down without memorization:
Time: O(3^N)
Space: O(N)
*/

/*
Time: O(N), averagely O(1)
Space: O(N)
 */
long long tripleStep(int N){
  static vector<long long> dp(2, 1);
  if(N < 0) return 0;
  if(dp.size() < 3) dp.push_back(2);
  for(int i = dp.size(); i <= N; ++i){
    dp.push_back( dp[i - 1] + dp[i - 2] + dp[i - 3]);
  }
  return dp[N];
}

/*
Time: O(N), averagely O(N)
Space: O(1)
*/
long long tripleStep1(int N){
  long long a = 2, b = 1, c = 1;
  if(N < 0) return 0;
  if(N <= 1) return 1;
  if(N == 2) return 2;
  for(int i = 3; i <= N; ++i){
    long long current = a + b + c;
    c = b;
    b = a;
    a = current;
  }
  return a;
}

vector<vector<long long>> multiply(const vector<vector<long long>>& X, const vector<vector<long long>>& Y){
  if(X[0].size() != Y.size()) throw "Invalid matrix size";
  vector<vector<long long>> product(X.size(), vector<long long>(Y[0].size(), 0));
  for(int row = 0; row < X.size(); ++row){
    for(int col = 0; col < Y[0].size(); ++col){
      for(int k = 0; k < Y.size(); ++k){
        product[row][col] += X[row][k] * Y[k][col];
      }
    }
  }
  return product;
}

long long tripleStep2(int N){
  if(N < 0) return 0;
  vector<vector<long long>> A{{1, 0, 0}};
  vector<vector<long long>> P{{1,1,0}, {1,0,1}, {1,0,0}};
  vector<vector<long long>> product{{1,0,0}, {0,1,0}, {0,0,1}};
  
  while(N){
    if(N & 1) product = multiply(product, P);
    P = multiply(P, P);
    N >>= 1;
  }
  A = multiply(A, product);
  return A[0][0];
}

int main(void){
  int N;
  while(cin >> N){
    cout << "tripleStep(" << N << ") = " << tripleStep(N) << endl;
    cout << "tripleStep1(" << N << ") = " << tripleStep1(N) << endl;
    cout << "tripleStep2(" << N << ") = " << tripleStep2(N) << endl;
  }
}
