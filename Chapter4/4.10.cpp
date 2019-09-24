/*
Time : O(T1)
Space: O(T1);
 */
bool isSubtree(const TreeNode* node, const TreeNode* X){
  if(X == node) return true;
  if(node == NULL) return false;
  if(isSubtree(node->left, X) || isSubtree(node->right, X)) return true;
  return false;
} 
bool isSubtree(const Tree& tree1, const Tree& tree2){ //tree1 > tree2
  return isSubtree(tree1.root, tree2.root);
}
