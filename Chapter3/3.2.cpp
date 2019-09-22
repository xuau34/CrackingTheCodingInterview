#include <bits/stdc++.h>
using namespace std;

class StackNode{
  public:
    int data;
    int minData;
    StackNode *next;
    StackNode( int _data, int _minData): data(_data), minData(min(_data, _minData)), next(NULL){
    }
};

class Stack{
  private:
    StackNode *head;
  public:
    Stack(): head(NULL){
    }
    void push(int data){
      StackNode *node = NULL;
      if(head == NULL) node = new StackNode(data, data);
      else node = new StackNode(data, head -> minData);
      node -> next = head;
      head = node;
    }
    int pop(){
      if(head == NULL) throw "Empty Stack";
      StackNode *next = head -> next;
      int data = head -> data;
      delete(head);
      head = next;
      return data;
    }
    int peek(){
      if(head == NULL) throw "Empty Stack";
      return head -> data;
    }
    int min(){
      if(head == NULL) throw "Empty Stack";
      return head -> minData;
    }
};

int main(void){
  Stack s;
  while(1){
    int x;
    cin >> x;
    if(x == 1){
      int N;
      cin >> N;
      s.push(N);
    }else if(x == 0){
      try{
        cout << "pop - " << s.pop() << endl;
      }catch( const char* err ){
        cout << err << endl;
      }
    }
    cout << s.peek() << ", " << s.min() << endl;
  }
}
