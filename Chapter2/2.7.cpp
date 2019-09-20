/*
Time: O(XlogX + Y)
Space: O(X)
 */

#include <bits/stdc++.h>
#include "LinkedList.cpp"
using namespace std;

bool isIntersected(LinkedList& X, LinkedList& Y){
  set<ListNode*> S;
  ListNode *ptr = X.head;
  while(ptr != NULL){
    S.insert(ptr);
    ptr = ptr -> next;
  }
  ptr = Y.head;
  while(ptr != NULL){
    if(S.find(ptr) != S.end()) return true;
    ptr = ptr -> next;
  }
  return false;
}
int main(void){
  int N, M, K;
  cin >> N >> M;
  LinkedList X, Y, sum1, sum2;
  while(N--){
    int x;
    cin >> x;
    X.appendInTail(x);
  }
  while(M--){
    int x;
    cin >> x;
    Y.appendInTail(x);
  }
  cout << "Is intersected? " << isIntersected(X, Y) << endl;
  cin >> K;
  while(K--){
    int x;
    cin >> x;
    ListNode *ptr = new ListNode(x);
    X.appendInHead(ptr);
    Y.appendInHead(ptr);
  }
  cout << "Is intersected? " << isIntersected(X, Y) << endl;
}

