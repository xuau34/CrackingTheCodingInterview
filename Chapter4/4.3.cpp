/*
Time: O(N)
Space: O(N)
 */

void getListsOfDepth(const TreeNode* node, vector<LinkedList<TreeNode*>>& lists, int depth){
  lists[depth].insert(0, node);
  for(const TreeNode* child: node.children){
    getListsOfDepth(child, lists, depth + 1);
  }
}


vector<LinkedList> getListsOfDepth(const Tree& tree){
  vector<LinkedList<TreeNode*>> lists;
  getListsOfDepth(tree.root, lists, 0);
  return lists;
}

vector<LinkedList> getListsOfDepth2(const Tree& tree){
  vector<LinkedList<TreeNode*>> lists;
  queue<TreeNode*> que;
  que.push(tree.root);
  que.push(NULL);
  while(!que.empty()){
    lists.push_back( LinkedList<TreeNode*>() );
    while(que.front() != NULL){
      TreeNode *node = que.front();
      que.pop();
      lists.back().insert(0, node);
      for(const TreeNode* child: node.children){
        que.push(child);
      }
    }
    que.pop();
  }

}
