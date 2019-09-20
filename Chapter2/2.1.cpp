#include <bits/stdc++.h>
using namespace std;
/*
Time: O(N^2)
Space: O(1)
 */

typedef struct _listNode{
  struct _listNode *next;
  int data;
  _listNode(int _data): next(NULL), data(_data){
  }
} listNode;

typedef struct _linkedList{
  listNode *head;

  _linkedList(): head(NULL){
  }
  void remove_if(int data, listNode *from = NULL){  //exclude the first one: from
    if(from == NULL) from = head;
    listNode *ptr = from;
    while(ptr -> next != NULL){
      if(ptr -> next -> data == data ){
        listNode *next = ptr -> next;
        ptr -> next = next -> next;
        delete(next);
      }else{
        ptr = ptr -> next;
      }
    }
  }
  void insertAsHead(int data){
    listNode *node = new listNode(data);
    node -> next = head;
    head = node;
  }

} linkedList;

void removeDups( linkedList& list ){
  listNode *ptr = list.head;
  while(ptr != NULL){
    list.remove_if(ptr -> data, ptr);
    ptr = ptr -> next;
  }
}

void outputList( const linkedList& list ){
  auto ptr = list.head;
  while(ptr != NULL){
    cout << (ptr -> data) << " ";
    ptr = ptr -> next;
  }
  cout << endl;
}

int main(void){
  while(true){
    int N;
    cin >> N;
    linkedList list;
    for(int i = 0; i < N; ++i){
      int data;
      cin >> data;
      list.insertAsHead(data);
    }
    outputList(list);
    cout << " => " << endl;
    removeDups(list);
    outputList(list);

  }
}
