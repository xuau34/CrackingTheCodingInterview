/*
Time : O(N^2*(combinations))
Space: O(N * combinations ))
 */

#include <bits/stdc++.h>
using namespace std;

class TreeNode{
  public:
    TreeNode *left, *right;
    int data;
    TreeNode(int _data): data(_data), left(NULL), right(NULL){
    }
};
class Tree{
  TreeNode* insert(TreeNode* node, int x){
    if(node == NULL) return new TreeNode(x);
    if(x < node -> data){
      node -> left = insert(node -> left, x);
    }else{
      node -> right = insert(node -> right, x);
    }
    return node;
  }
  public:
  TreeNode *root;
  Tree(): root(NULL){
  }
  void insert(int x){
    root = insert(root, x);
  }
};

void outputSeqs(vector<vector<int>>& seqs){
  for(const auto& seq: seqs){
    for(int x: seq){
      cout << x << " ";
    }
    cout << endl;
  }
}
vector<vector<int>> getBSTSeq(const Tree& tree){
  queue< pair<TreeNode*, TreeNode*> > que;
  que.push( make_pair(tree.root, nullptr) );
  vector<vector<int>> seqs, cache;
  while(!que.empty()){
    TreeNode* node = que.front().first;
    TreeNode* parent = que.front().second;
    que.pop();
    if(node == NULL) continue;
    if(parent == NULL){
      seqs.push_back( vector<int>(1, node -> data) );
    }else{
      for(vector<int>& seq: seqs){
        for(int i = seq.size() - 1; i >= 0; --i){
          vector<int> copy(seq.size() + 1);
          for(int j = 0; j < seq.size() + 1; ++j){
            if(j <= i) copy[j] = seq[j];
            else if(j == i + 1) copy[j] = node -> data;
            else copy[j] = seq[j - 1];
          }
          cache.push_back(copy);
          if(seq[i] == parent -> data){
            break;
          }
        }
      }
      swap(seqs, cache);
      cache.clear();
    }
    que.push( make_pair(node -> left, node) );
    que.push( make_pair(node -> right, node) );
  }
  return seqs;
}

int main(void){
  int N;
  cin >> N;
  Tree tree;
  for(int i = 0; i < N;++i){
    int x;
    cin >> x;
    tree.insert(x);
  }
  auto seqs = getBSTSeq(tree);
  outputSeqs(seqs);
}
