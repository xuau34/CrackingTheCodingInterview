/*
Time : O(N)
Space: O(N)
 */

bool isBalanced(const Tree& tree){
  bool balanced = true;
  checkBalanced(tree.root, balanced);
  return balanced;
}

int checkBalanced(TreeNode* node, bool& balanced){
  int lheight = checkBalanced(node -> left, balanced);
  int rheight = checkBalanced(node -> right, balanced);
  if(abs(lheight-rheight) > 1) balanced = false;
  return max(lheight, rheight) + 1;
}
