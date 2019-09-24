/*
Time : O(N)
Space: O(N * 2^( (N-1)/2 ))
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
vector<vector<int>> getConcate(vector<vector<int>> child, vector<vector<int>>& cache){
  vector<vector<int>> seq;
  for(int i = 0; i < child.size(); ++i){
    for(int j = 0; j < cache.size(); ++j){
      vector<int> order(cache[j].begin(), cache[j].end());
      order.insert(order.end(), child[i].begin(), child[i].end());
      seq.push_back(order);
      if(cache[j].size() > 1){
        order = cache[j];
        order.insert(order.begin() + 1, child[i].begin(), child[i].end());
        seq.push_back(order);
      }
    }
  }
  return seq;
}

vector<vector<int>> getBSTSeq(const TreeNode* node){
  if(node == NULL) return vector<vector<int>>();
  vector<vector<int>> seq, cache;
  cache.push_back( {node -> data} );
  seq = getConcate(getBSTSeq(node -> left), cache);
  if(seq.size() != 0){
    swap(seq, cache);
    seq.clear();
  }
  seq = getConcate(getBSTSeq(node -> right), cache);
  if(seq.size() == 0) return cache;
  return seq;
}

vector<vector<int>> getBSTSeq(const Tree& tree){
  return getBSTSeq(tree.root);
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
