

size_t findSize( const Listy& list ){
  if(list.elementAt(0) < 0) return 0;
  size_t L, M, R = 1;
  while( list.elementAt(R) >= 0 ){
    R <<= 1;
  }
  L = R >> 1;
  while(L + 1 < R){
    M = (L + R) >> 1;
    if(list.elementAt(M) < 0) R = M;
    else L = M;
  }
  return R;
}

size_t findElement( const Listy& list, unsigned int x){
  size_t L = 0, M, R = findSize(list);
  if(x < list.elementAt(L) || x > list.elementAt(R - 1)) return -1;
  while(L + 1 < R){
    M = (L + R) >> 1;
    if(list.elementAt(M) <= x) L = M;
    else R = M;
  }
  if(list.elementAt(M) == x) return L;
  return -1;
}
