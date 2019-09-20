/*
  length of a = A, length of b = B
  1: sort && check -
    Time: O(AlogA + BlogB)
    Space: O(1)
  2: bucket sort && check - 
    Time: O(A + B)
    Space: O(A + B)
 */

vector<int> getBucketCnt(const string& str){
  vector<int> bucketCnt(26, 0);
  for(char c: str){
    bucketCnt[c - 'a'] += 1;
  }
  return bucketCnt;
}

bool checkPermutation(string a, string b){
  auto bucketCntA = getBucketCnt(a);
  auto bucketCntB = getBucketCnt(b);
  for(int i = 0; i < 26; ++i){
    if(bucketCntA[i] != bucketCntB[i]) return false;
  }
  return true;
}
