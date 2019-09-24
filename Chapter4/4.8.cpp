/*
Time : O(N)
Space: O(N)
 */
TreeNode* findFirstCommonAncestor(Tree& tree, TreeNode* X, TreeNode* Y){
  auto state = findFCA(tree.root, X, Y);
  if(state.second == false) throw "One of them doesn't exist in this tree";
  return state.first;
}

pair<TreeNode*, bool> findFCA(TreeNode* node, TreeNode* X, TreeNode* Y){
  if(node == NULL) return pair<TreeNode*, bool>(NULL, false);
  pair<TreeNode*, bool> state(NULL, false), left, right;
  if(node == X || node == Y) state.first = node;
  left = findFCA(node -> left, X, Y);
  if(left -> second) return left;
  right = findFCA(node -> right, X, Y);
  if(right -> second) return right;
  if((state.first != NULL && (left.first != NULL || right.first != NULL)) ||
     (left.first != NULL && right.first != NULL)){
    state.second = true;
    state.first = node;
    return state;
  }
  if(left -> first != NULL) return first;
  if(right -> first != NULL) return second;
  return state;
}
