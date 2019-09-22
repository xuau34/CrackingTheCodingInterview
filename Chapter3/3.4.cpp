#include <bits/stdc++.h>
#include "Stack.cpp"
using namespace std;

class Queue{
  private:
    Stack<int> reversedS, cachedS;
    size_t size;
    void reverse(){
      while(!cachedS.isEmpty()){
        reversedS.push( cachedS.pop() );
      }
    }
  public:
    Queue(): size(0){
    }
    void push(int data){
      cachedS.push(data);
      size += 1;
    }
    int pop(){
      if(reversedS.getSize() == 0) reverse();
      size -= 1;
      return reversedS.pop();
    }
    int peek(){
      if(reversedS.getSize() == 0) reverse();
      return reversedS.peek();
    }
    bool isEmpty(){
      return size == 0;
    }
};

int main(void){
  Queue que;
  while(1){
    int x;
    cin >> x;
    if(x == 1){
      int N;
      cin >> N;
      que.push(N);
    }else if(x == 0){
      try{
        cout << "pop - " << que.pop() << endl;
      }catch( const char* err ){
        cout << err << endl;
      }
    }
    if(que.isEmpty()) cout << "Queue are empty" << endl;
    else cout << que.peek() << endl;
  }
}
