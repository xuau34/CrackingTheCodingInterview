/*
  Time: O(N)
  Space: O(1)
 */
#include <bits/stdc++.h>
#include "LinkedList.cpp"
using namespace std;


void partition(LinkedList& list, int x){
  LinkedList first, second;
  ListNode *ptr = list.head;
  while(ptr != NULL){
    ListNode *next = ptr -> next;
    if(ptr -> data < x){
      first.appendInHead(ptr);
    }else{
      second.appendInHead(ptr);
    }
    ptr = next;
  }
  if(first.head == NULL){
    list = second;
  }else if(second.head == NULL){
    list = first;
  }else{
    first.tail -> next = second.head;
    list.head = first.head;
    list.tail = second.tail;
  }
}

int main(void){
  int N;
  cin >> N;
  LinkedList list;
  while(N--){
    int x;
    cin >> x;
    list.appendInTail(x);
  }
  while(true){
    int query;
    cin >> query;
    partition(list, query);
    outputList(list);
  }
}
