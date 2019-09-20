/*
Time: O(N)
Space: O(N)
 */

#include <bits/stdc++.h>
using namespace std;

typedef struct _listNode{
  _listNode *next;
  int data;
  _listNode( int _data ): next(NULL), data(_data) {
  }
} listNode;

typedef struct _linkedList {
  listNode *head, *tail;
  _linkedList():head(NULL), tail(NULL){
  }
  void appendInTail( int data ){
    if(head == NULL){
      tail = head = new listNode(data);
      return;
    }
    tail -> next = new listNode(data);
    tail = tail -> next;
  }
} linkedList;

int findNthToLast( listNode *ptr, listNode *nthPtr, int N){
  if(ptr == NULL) return 1;
  int nth = findNthToLast(ptr -> next, nthPtr, N);
  if(nth == N) nthPtr -> data = ptr -> data;
  return nth + 1;
}

int findNthToLast( linkedList& list, int N ){
  listNode *ptr = new listNode(-1);
  findNthToLast( list.head, ptr, N );
  return ptr -> data;
}

int main(void){
  int N;
  cin >> N;
  linkedList list;
  while(N--){
    int x;
    cin >> x;
    list.appendInTail(x);
  }
  while(true){
    int query;
    cin >> query;
    cout << findNthToLast(list, query) << endl;
  }
}
