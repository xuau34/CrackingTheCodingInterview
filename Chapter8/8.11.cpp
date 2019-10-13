/*
Time : O(N)
Space: O(N)
*/

int getCoinsCombinationNumber(int n){
  const static vector<int> coins = {25, 10, 5, 1};
  vector<int> combinations(n, 0);
  if(n < 0) return 0;
  combinations[0] = 1;
  for(int coin: coins){
    int maxNum = n / coin;
    for(int num = 1; num <= maxNum; ++num){
      combinations[ num * coin ] += combinations[ (num - 1) * coin ];
    }
  }
  return combinations[n];
}
