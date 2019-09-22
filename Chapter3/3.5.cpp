#include <bits/stdc++.h>
#include "Stack.cpp"
using namespace std;

Stack<int> sort(Stack<int> X){
  Stack<int> Y, cache;
  while(!X.isEmpty()){
    int Max = X.pop();
    while(!X.isEmpty()){
      int data = X.pop();
      if(data > Max){
        cache.push(Max);
        Max = data;
      }else cache.push(data);
    }
    Y.push(Max);
    swap(cache, X);
  }
  return Y;
}

int main(void){
  Stack<int> s;
  int N;
  cin >> N;
  while(N--){
    int x;
    cin >> x;
    s.push(x);
  }
  s = sort(s);
  while(!s.isEmpty()){
    cout << s.pop() << " ";
  }
  cout << endl;
}
