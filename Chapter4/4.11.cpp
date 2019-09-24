/*
insert: O(N)
find: O(N)
delete: O(N)
random: O(N)
 */

#include <bits/stdc++.h>
using namespace std;

class TreeNode: public enable_shared_from_this<TreeNode>  //must be public inheritance
{
  public:
    shared_ptr<TreeNode> left, right;
    int data;
    size_t size;
    TreeNode(int _data): left(/*nullptr*/), right(), size(1), data(_data){
    }
    shared_ptr<TreeNode> getIdxNode(int idx){ //idx in post-order
      if(size - 1 == idx) return shared_from_this();
      if(left != nullptr){
        if(idx < left -> size) return left -> getIdxNode(idx);
        idx -= left -> size;
      }
      if(right != nullptr) return right -> getIdxNode(idx);
      return nullptr;
    }
    shared_ptr<TreeNode> insert(int _data){
      if(this == nullptr) return make_shared<TreeNode>(_data);  //must create shared_ptr before using share_from_this
      if(_data < data) left = left -> insert(_data);
      else right = right -> insert(_data);
      size += 1;
      return shared_from_this();
    }
    shared_ptr<TreeNode> find(int _data){
      if(this == nullptr) return NULL;
      if(_data == data) return shared_from_this();
      if(_data < data) return left -> find(_data);
      return right -> find(_data);
    }
    ~TreeNode(){
      if(this == nullptr) return;
      cout << "del " << data << endl;
      //delete left;
      //delete right;
    }
};

class BST{
  shared_ptr<TreeNode> root;
  public:
    BST(): root(nullptr){
    }
    void insert(int data){
      root = root -> insert(data);
    }
    shared_ptr<TreeNode> find(int data){
      return root -> find(data);
    }
    shared_ptr<TreeNode> getRandom(){
      if(root == nullptr) return nullptr;
      int idx = random() % (root -> size);
      return root -> getIdxNode(idx);
    }
    ~BST(){
      //delete root;
    }

};

int main(void){
  BST tree;
  while(1){
    int x;
    cin >> x;
    if(x == 1){
      cout << "insert ";
      int n;
      cin >> n;
      tree.insert(n);
    }else if(x == 2){
      cout << "find ";
      int n;
      cin >> n;
      auto ptr = tree.find(n);
      if(ptr == nullptr) cout << ">> find nullptr" << endl;
      else cout << ">> find " << ptr -> data << endl;
    }else if(x == 3){
      auto ptr = tree.getRandom();
      cout << "get random " << ptr -> data << endl;
    }else if(x == 0){
      cout << "delete tree - " << endl;
      break;
    }
  }
}
