/*
  Time O(N)
  Space O(N)
 */

#include <bits/stdc++.h>
#include "LinkedList.cpp"
using namespace std;
bool isPalindrome(LinkedList& list){
  LinkedList reversed = reverseList(list);
  ListNode *ptrX = list.head, *ptrY = reversed.head;
  while(ptrX != NULL && ptrY != NULL){
    if(ptrX -> data != ptrY -> data) return false;
    ptrX = ptrX -> next;
    ptrY = ptrY -> next;
  }
  return true;
}
int main(void){
  int N, M;
  cin >> N;
  LinkedList X;
  while(N--){
    int x;
    cin >> x;
    X.appendInTail(x);
  }
  cout << "Is palindrome? " << isPalindrome(X) << endl;
}
