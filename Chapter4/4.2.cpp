/*
Time : O(N)
Spcae: O(N)
 */

#include <bits/stdc++.h>
using namespace std;

class TreeNode{
  public:
    int data;
    TreeNode *left, *right;
    TreeNode(int _data): left(NULL), right(NULL), data(_data){
    }
}

TreeNode* minBinaryTree(const vector<int>& arr, int L = 0, int R = -1){
  if(R < 0) R = arr.size();
  if(L >= R) return NULL;
  if(L + 1 == R) return new TreeNode(arr[L]);
  int M = (L + R) >> 1;
  TreeNode *node = new TreeNode(arr[M]);
  node -> left = minBinaryTree(arr, L, M);
  node -> right = minBinaryTree(arr, M + 1, R);
  return node;
}

void outputTree(TreeNode *node){
  if(node == NULL) return; 
  outputTree(node -> left);
  cout << node -> data << endl;
  outputTree(node -> right);
}

