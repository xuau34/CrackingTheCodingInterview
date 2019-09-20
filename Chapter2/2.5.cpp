/*
  Time: O(X + Y)
  Space: O(1)

  Time: O(X + Y)
  Space: O(X + Y)
 */
#include <bits/stdc++.h>
#include "LinkedList.cpp"
using namespace std;

LinkedList sumListFromHead(LinkedList& x, LinkedList& y){
  LinkedList list;
  int carry = 0;
  ListNode *ptrX = x.head, *ptrY = y.head;
  while(ptrX != NULL && ptrY != NULL){
    int sum = ptrX -> data + ptrY -> data + carry;
    carry = sum / 10;
    list.appendInTail( sum % 10 );
    ptrX = ptrX -> next;
    ptrY = ptrY -> next;
  }
  while(ptrX != NULL){
    int sum = ptrX -> data + carry;
    carry = sum / 10;
    list.appendInTail( sum % 10 );
    ptrX = ptrX -> next;
  }
  while(ptrY != NULL){
    int sum = ptrY -> data + carry;
    carry = sum / 10;
    list.appendInTail( sum % 10 );
    ptrY = ptrY -> next;
  }
  return list;
}

LinkedList sumListFromTail(LinkedList& x, LinkedList& y){
  LinkedList reX = reverseList(x), reY = reverseList(y);
  return reverseList( sumListFromHead(reX, reY) );
}
int main(void){
  int N, M;
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
  sum1 = sumListFromHead(X, Y);
  sum2 = sumListFromTail(X, Y);
  outputList(sum1);
  outputList(sum2);
}
