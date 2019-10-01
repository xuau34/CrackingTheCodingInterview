#include <bits/stdc++.h>
using namespace std;
/*
hash table<T1, T2>: T1 is for hashing, T2 for data
hash function
table of linked list
* getHashValue
* access(T1) or access(hashValue(T1)) return reference for further use
* add(T1, T2) or add(hashValue(T1), T2)
 */


template<class T>
class ListNode{
  public:
    shared_ptr<T> next;
    T data;
    ListNode(const T& _data): next(nullptr), data(_data){
    }
};

template<class T>
class LinkedList{
  shared_ptr<ListNode<T>> head, tail;
  public:
    LinkedList():head(nullptr), tail(nullptr){
    }
    void append(const T& data){
      if(tail == nullptr){
        head = tail = make_shared<T>(data);
        return;
      }
      tail -> next = make_shared<T>(data);
      tail = tail -> next;
    }
};

template<class Key, class Data>
class HashTable{
  function<size_t(Key)> hashFunction;
  vector<LinkedList<Data>> table;
  public:
    HashTable( function<size_t(Key)> _hashFunction, size_t range):
      hashFunction(_hashFunction), table(range){
    }
    size_t getHashValue(Key key){
      size_t hashValue = hashFunction(key);
      if(hashValue >= table.size()) throw "Hash function produces value over the range";
      return hashValue;
    }
    LinkedList& access(Key key){
      return access( getHashValue(key) );
    }
    LinkedList& access(size_t hashValue){
      return table[hashValue];
    }
    void add(Key key, const Data& data){
      add( getHashValue(key, data) );
    }
    void add(size_t hashValue, const Data& data){
      table[hashValue].append(data);
    }
};
