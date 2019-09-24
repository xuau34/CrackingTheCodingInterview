/*
Time : O(N)
Space: O(N)
 */

bool isBST(const Tree& tree){
  return isBST(tree.root);
}
bool isBST(const TreeNode* node){
  if(node == NULL) return true;
  if(node -> left != NULL){
    if(node -> data <= node -> left -> data || isBST(node -> left) == false){
      return false;
    }
  }
  if(node -> right != NULL){
    if(node -> data > node -> right -> data || isBST(node -> right) == false){
      return false;
    }
  }
  return true;
}
