/*
  Time: O( min(A,B) )
  Space: O(1)
 */

bool isOneWay(string A, string B){
  if(abs(A.length() - B.length()) > 1) return false;
  int operations = 0;
  for(int i = 0, j = 0; i < A.length() && j < B.length() && operations < 2; ++i, ++j ){
    if(A[i] != B[i]){
      if(j + 1 < B.length() && A[i] == B[j + 1]){
        j += 1;
        operations += 1;
        continue;
      }
      if(i + 1 < A.length()){
        if(A[i + 1] == B[j]){
          i += 1;
          operations += 1;
          continue;
        }else if(j + 1 < B.length() && A[i + 1] == B[j + 1]){
          operations += 1;
          continue;
        }
      }
      return false;
    }
  }
  return operations < 2;
}
