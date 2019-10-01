/*
for(:T) => T must have begin() and end() function
both return some class like iterator that has operator *, ++, !=, == functions 

Here I use linked list to perform the rotation, which costs O(N) time, for finding the the new tail
insert: O(N)
for(:) : O(1) for each
space: O(N)
 */

#include <bits/stdc++.h>
using namespace std;

template<class T>
class ListNode{
public:
  int data;
  shared_ptr<ListNode> next;
  ListNode(int _data): data(_data), next(nullptr){
  }
};

template<class T>
class CircularArray{
  shared_ptr<ListNode<T>> head, tail;
  size_t size;
public:
  class iterator{
    shared_ptr<ListNode<T>> ptr;
    public:
    iterator(shared_ptr<ListNode<T>> _ptr): ptr(_ptr){
    }
    iterator operator++(){
      ptr = ptr -> next;
      return *this;
    }
    bool operator==(iterator other) const{
      return ptr == other.ptr;
    }
    bool operator!=(iterator other) const{
      return ptr != other.ptr;
    }
    T& operator*(){
      return ptr -> data;
    }
  };
  CircularArray(): head(nullptr), tail(nullptr), size(0){
  }
  void insert(size_t ith, T data){
    if(head == nullptr){
      head = tail = make_shared<ListNode<T>>(data);
      size += 1;
      return;
    }
    if(ith == 0){
      auto newHead = make_shared<ListNode<T>>(data);
      newHead -> next = head;
      head = newHead;
      size += 1;
      return;
    }
    if(ith >= size){
      tail -> next = make_shared<ListNode<T>>(data);
      tail = tail -> next;
      size += 1;  //!!!
      return;
    }
    ith -= 1;
    shared_ptr<ListNode<T>> ptr = head;
    while(ith--){
      ptr = ptr -> next;
    }
    auto next = ptr -> next;
    ptr -> next = make_shared<ListNode<T>>(data);
    ptr -> next -> next = next;
    size += 1;
  }
  void push_back(T data){
    insert(size, data);
  }
  void rotate(size_t shift){
    shift %= size;
    if(shift == 0) return;
    shared_ptr<ListNode<T>> newTail = head;
    while(--shift){
      newTail = newTail -> next;
    }
    tail -> next = head;
    head = newTail -> next;
    newTail -> next = nullptr;
    tail = newTail;
  }
  iterator begin(){
    return iterator( head );
  }
  iterator end(){
    return iterator( nullptr );
  }
};


int main(void){
  int N;
  CircularArray<int> arr;
  cin >> N;
  while(N--){
    int x;
    cin >> x;
    arr.push_back(x);
  }
  while(true){
    int inst;
    cin >> inst;
    if(inst == 1){
      cout << "push back: ";
      int x;
      cin >> x;
      arr.push_back(x);
    }else if(inst == 2){
      cout << "shift: ";
      int x;
      cin >> x;
      arr.rotate(x);
    }else if(inst == 3){
      cout << "insert: ";
      int ith, data;
      cin >> ith >> data;
      arr.insert(ith, data);
    }else if(inst == 0){
      for(auto ele: arr){
        cout << ele << ", ";
      }
      cout << endl;
    }else if(inst == -1){
      for(auto& ele: arr){
        ele = 0;
      }
    }
  }
}
