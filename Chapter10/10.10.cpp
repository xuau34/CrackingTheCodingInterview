/*
time:
  track: O(logN), if worst O(N)
  getRankOfNumber: O(logN), if worst O(N)
space: O(N)
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct _BinaryTreeNode{
  shared_ptr<_BinaryTreeNode> left, right;
  int value;
  size_t sizeL;
  _BinaryTreeNode( int _value ): left(nullptr), right(nullptr), value(_value), sizeL(0){
  }
} BinaryTreeNode;

class BST{
  shared_ptr<BinaryTreeNode> root;
  shared_ptr<BinaryTreeNode> _track(int X, shared_ptr<BinaryTreeNode> node){
    if( node == nullptr ) {
      return make_shared<BinaryTreeNode> (X);
    }
    if(X == node -> value){
      node -> sizeL += 1;
      return node;
    }
    if(X < node -> value){
      node -> left = _track(X, node -> left);
      node -> sizeL += 1;
    }else node -> right = _track(X, node -> right);
    return node;
  }
  int _getRankOfNumber(int X, shared_ptr<BinaryTreeNode> node){
    if(node == nullptr) return 0;
    if(node -> value == X){
      return node -> sizeL;
    }
    if(X < node -> value) return _getRankOfNumber(X, node -> left);
    else return node -> sizeL + 1 + _getRankOfNumber(X, node -> right);
  }
  public:
  BST(): root(nullptr){
  }
  void track(int X){
    root = _track(X, root);
  }
  int getRankOfNumber(int X){
    return _getRankOfNumber(X, root);
  }
};

int main(void){
  int inst;
  BST tree;
  while(cin >> inst){
    int X;
    cin >> X;
    if(inst == 1){
      tree.track(X);
      cout << "track " << X << endl;
    }else if(inst == 0){
      cout << tree.getRankOfNumber(X) << endl;
    }
  }
}
