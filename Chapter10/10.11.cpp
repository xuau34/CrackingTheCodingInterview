

// Time - O(NlogN); Space - O(N)
vector<int> sortInPeaks( vector<int> arr ){
  sort(arr.begin(), arr.end());
  for(int i = 1; i < arr.size(); i += 2){
    swap(arr[i-1], arr[i]);
  }
  return arr;
}

int findMaxIndexFromThree( const vector<int>& arr, int X ){
  int a = arr[X - 1];
  int b = arr[X];
  int c = arr[X + 1];
  if( a >= b && a >= c ) return X - 1;
  if( b >= a && b >= c ) return X;
  return X + 1;
}

// Time - O(N); Space - O(N)
// Would go wrong when allowing duplicate numbers e.g. 1 5 4 2 3 3
vector<int> sortInPeaks( vector<int> arr ){
  for(int i = 1; i+1 <= arr.size(); i += 2){
    int maxIndex;
    if(i + 1 == arr.size()){
      if(arr[i] > arr[i-1]) maxIndex = i;
      else maxIndex = i - 1;
    }else maxIndex = findMaxIndexFromThree( arr, i );
    swap( arr[i], arr[maxIndex] );
  } 
  return arr;
}
