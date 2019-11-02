/*
Time : O(rows * log cols)
Spcae: O(1)
 */

size_t findInSortedArray( const vector<int>& array, int X ){
  if(array.front() > X || array.back() > X ) return -1;
  size_t L = 0, M, R = array.size();
  while(L + 1 < R){
    M = (L + R) >> 1;
    if(array[M] <= X) L = M;
    else R = M;
  }
  if(array[L] == X) return L;
  return -1;
}

pair<size_t, size_t> findInSortedMatrix( const vector<vector<int>>& matrix, int X){
  for(size_t row = 0; row < matrix.size(); ++row){
    size_t col = findInSortedArray( matrix[row], X );
    if(col >= 0) return make_pair(row, col);
  }
  return make_pair(-1, -1);
}
