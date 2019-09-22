/*
Time: operator O(1), dequeueAny: averagely O(1)
Space: O(C+D)
 
 */

#include <bits/stdc++.h>
using namespace std;

enum Type{
  any, dog, cat
};

class QueueNode{
  public:
    QueueNode *next;
    QueueNode *anyNode;
    Type type;
    bool adopted;
    QueueNode(Type _type, QueueNode *_anyNode = NULL): type(_type), next(NULL), adopted(false), anyNode(_anyNode){
    }
};

class Queue{
    void clearAdopted(){
      while(head != NULL && head -> adopted == true){
        QueueNode *ptr = head;
        head = head -> next;
        delete(ptr);
      }
    }
  public:
    QueueNode *head, *tail;
    Queue(): head(NULL), tail(NULL){
    }
    void enqueue( QueueNode *node ){
      if(head == NULL){
        head = tail = node;
        return;
      }
      tail -> next = node;
      tail = node;
    }
    Type dequeue(){
      if(head == NULL) throw "Empty Queue";
      if(head -> anyNode == NULL){
        clearAdopted();
      }else{
        head -> anyNode -> adopted = true;
      }
      Type retVal = head -> type;
      QueueNode *ptr = head;
      head = head -> next;
      delete(ptr);
      return retVal;
    }
    
};

class Shelter{
  private:
    Queue any, dog, cat;
    void enqueueDog(){
      QueueNode *anyNode = new QueueNode(Type::dog);
      QueueNode *node = new QueueNode(Type::dog, anyNode);
      any.enqueue(anyNode);
      dog.enqueue(node);
    }
    void enqueueCat(){
      QueueNode *anyNode = new QueueNode(Type::cat);
      QueueNode *node = new QueueNode(Type::cat, anyNode);
      any.enqueue(anyNode);
      cat.enqueue(node);
    }
  public:
    void enqueue( Type type ){
      if(type == Type::dog) enqueueDog();
      else if(type == Type::cat) enqueueCat();
      else throw "Enqueue type error";
    }
    Type dequeueAny(){
      return any.dequeue();
    }
    Type dequeueDog(){
      return dog.dequeue();
    }
    Type dequeueCat(){
      return cat.dequeue();
    }
};

int main(void){
  Shelter shelter;
  while(1){
    int x;
    cin >> x;
    if(x == 1){
      int N;
      cin >> N;
      if(N == 1) shelter.enqueue( Type::dog );
      else if(N == 2) shelter.enqueue( Type::cat );
    }else if(x == 0){
      int N;
      cin >> N;
      if(N == 0) cout << "pop any - " << shelter.dequeueAny() << endl;
      else if(N == 1) cout << "pop dog - " << shelter.dequeueDog() << endl;
      else if(N == 2) cout << "pop cat - " << shelter.dequeueCat() << endl;
    }
  }
}
