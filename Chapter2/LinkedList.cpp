#include <bits/stdc++.h>
using namespace std;

typedef struct _listNode{
  _listNode *next;
  int data;
  _listNode( int _data ): next(NULL), data(_data) {
  }
} ListNode;

typedef struct _linkedList {
  ListNode *head, *tail;
  _linkedList():head(NULL), tail(NULL){
  }
  void appendInHead( int data ){
    appendInHead( new ListNode(data) );
  }
  void appendInHead( ListNode *ptr ){
    if(head == NULL){
      tail = head = ptr;
      ptr -> next = NULL; //!!!
      return;
    }
    ptr -> next = head;
    head = ptr;
  }
  void appendInTail( int data ){
    if(head == NULL){
      tail = head = new ListNode(data);
      return;
    }
    tail -> next = new ListNode(data);
    tail = tail -> next;
  }
} LinkedList;
_linkedList reverseList(const _linkedList &x){
  _linkedList reversed;
  const ListNode *ptr = x.head;
  while(ptr != NULL){
    reversed.appendInHead(ptr -> data);
    ptr = ptr -> next;
  }
  return reversed;
}

void outputList(LinkedList &list){
  ListNode *ptr = list.head;
  while(ptr != NULL){
    cout << ptr -> data << " ";
    ptr = ptr -> next;
  }
  cout << endl;
}

