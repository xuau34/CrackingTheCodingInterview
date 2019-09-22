/*
  Time: O(1), popAt = O(nodes/maxSize)
  Space: O(nodes)
 */

#include <bits/stdc++.h>
#include "Stack.cpp"
using namespace std;

class ListNode{
  Stack<int> stack;
  public:
    ListNode *next;
    ListNode(): next(NULL){
    }
    void push(int data){
      stack.push(data);
    }
    int pop(){
      return stack.pop();
    }
    int peek(){
      return stack.peek();
    }
    size_t getSize(){
      return stack.getSize();
    }
};

class SetOfStacks{
  private:
    ListNode *head;
    size_t MaxSize;
    size_t listSize;
  public:
    SetOfStacks( size_t _MaxSize): MaxSize(_MaxSize), head(NULL), listSize(0){
    }
    void push(int data){
      if(head == NULL){
        head = new ListNode();
        listSize += 1;
      }else if( head -> getSize() == MaxSize){
        ListNode *node = new ListNode();
        node -> next = head;
        head = node;
        listSize += 1;
      }
      head -> push(data);
    }
    int pop(){
      if(head == NULL) throw "Stacks are empty";
      int retVal = head -> pop();
      if(head -> getSize() == 0){
        ListNode *ptr = head;
        head = head -> next;
        delete(ptr);
        listSize -= 1;
      }
      return retVal;
    }
    int peek(){
      if(head == NULL) throw "Stacks are empty";
      return head -> peek();
    }
    int popAt(int idx){
      if(idx <= 0 || idx > listSize) throw "Invalid index";
      idx = listSize - idx;
      ListNode *ptr = head, *prev = NULL;
      for(int i = 0; i < idx; ++i){
        prev = ptr;
        ptr = ptr -> next;
      }

      int retVal = ptr -> pop();
      if(ptr -> getSize() == 0){
        if(prev == NULL) head = head -> next;
        else prev -> next = ptr -> next;
        delete(ptr);
        listSize -= 1;
      }
      return retVal;
    }
    bool isEmpty(){
      return listSize == 0;
    }
};

int main(void){
  int maxN;
  cin >> maxN;
  SetOfStacks stacks(maxN);
  while(1){
    int x;
    cin >> x;
    if(x == 1){
      int N;
      cin >> N;
      stacks.push(N);
    }else if(x == 0){
      try{
        cout << "pop - " << stacks.pop() << endl;
      }catch( const char* err ){
        cout << err << endl;
      }
    }else if(x == 2){
      int idx;
      cin >> idx;
      try{
        cout << "pop at - " << stacks.popAt(idx) << endl;
      }catch( const char* err ){
        cout << err << endl;
      }
    }
    if(stacks.isEmpty()) cout << "Stacks are empty" << endl;
    else cout << stacks.peek() << endl;
  }
}
