/*
Time: O(N)
Space: O(1)
Floyd's Cycle detection
 */

#include <bits/stdc++.h>
#include "LinkedList.cpp"
using namespace std;
ListNode* getCycleStart(LinkedList& list){
  ListNode *slower = list.head, *faster = list.head;
  while(faster != NULL && faster -> next != NULL){
    slower = slower -> next;
    faster = faster -> next -> next;
    if(slower == faster) break;
  }
  if(slower != faster) return NULL;
  faster = list.head;
  while(slower != faster){
    slower = slower -> next;
    faster = faster -> next;
  }
  return slower;
}
int main(void){
  int N, M;
  cin >> N >> M;
  LinkedList X;
  while(N--){
    int x;
    cin >> x;
    X.appendInTail(x);
  }
  ListNode *cycleS = X.tail;
  while(M--){
    int x;
    cin >> x;
    X.appendInTail(x);
  }
  X.tail -> next = cycleS;
  ListNode *start = getCycleStart(X);
  if(start != cycleS) cout << "oh uh\n I got " << start -> data << endl;
  else cout << "start at " << start -> data << endl;
}
