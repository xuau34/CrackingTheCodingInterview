/*
  Time: O(len)
  Space: O(len)

  or

  Time: O(len log len)
  Space: O(1)
 */

vector<int> getBucketCnt(const string& str){
  vector<int> counts(26, 0);
  for(char c: str){
    if( c < 'a' || c > 'z' ) continue;
    counts[c - 'a'] += 1;
  }
  return counts;
}

bool couldBePalindrome(stinrg str){
  vector<int> bucketCnt = getBucketCnt(str);
  bool hasOddCnt = false;
  for(int i = 0; i < 26; ++i){
    if(bucketCnt[i] & 1){
      if(hasOddCnt) return false;
      hasOddCnt = true;
    }
  }
  return true;
}
