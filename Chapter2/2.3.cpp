/*
  Time : O(N)
  Space : O(1)
 */

/*
  Time: O(N)
  Space: O(1)
 */
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
  void appendInTail( int data ){
    if(head == NULL){
      tail = head = new ListNode(data);
      return;
    }
    tail -> next = new ListNode(data);
    tail = tail -> next;
  }
} LinkedList;

void deleteMiddle( LinkedList& list ){
  ListNode *slower = list.head, *faster = list.head;
  ListNode *prevSlower = NULL;
  while(faster != list.tail && faster -> next != list.tail ){
    prevSlower = slower;
    slower = slower -> next;
    faster = faster -> next -> next;
  }
  if(slower == list.head ) return;
  prevSlower -> next = slower -> next;
  delete(slower);
}

void outputList(LinkedList &list){
  ListNode *ptr = list.head;
  while(ptr != NULL){
    cout << ptr -> data << " ";
    ptr = ptr -> next;
  }
  cout << endl;
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
    deleteMiddle(list);
    outputList(list);
  }
}
