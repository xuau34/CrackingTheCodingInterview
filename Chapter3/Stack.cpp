#include <bits/stdc++.h>
using namespace std;

template <class T>
class StackNode{
  public:
    T data;
    StackNode<T> *next;
    StackNode<T>( T _data): data(_data), next(NULL){
    }
};

template <class T>
class Stack{
  private:
    StackNode<T> *head;
    size_t size;
  public:
    Stack(): head(NULL), size(0){
    }
    void push(T data){
      StackNode<T> *node  = new StackNode<T>(data);
      node -> next = head;
      head = node;
      size += 1;
    }
    T pop(){
      if(head == NULL) throw "Empty Stack";
      StackNode<T> *next = head -> next;
      T data = head -> data;
      delete(head);
      head = next;
      size -= 1;
      return data;
    }
    T peek(){
      if(head == NULL) throw "Empty Stack";
      return head -> data;
    }
    size_t getSize(){
      return size;
    }
    bool isEmpty(){
      return size == 0;
    }
};
