/*
Time: O(NlogN) Map
Space : O(N)
 */
class InOrder{
  private:
    map<TreeNode*, TreeNode*> nextTable;
    vector<TreeNode*> getInOrder(const Tree& tree){
      vector<TreeNode*> inorder;
      getInOrder(tree.root, inorder);
      return inorder;
    }
    void getInOrder(const TreeNode* node, vector<TreeNode*>& inorder){
      if(node == NULL) return;
      getInOrder(node -> left, inorder);
      inorder.push_back(node);
      getInOrder(node -> right, inorder);
    }
  public:
    InOrder(const Tree& tree){
      vector<TreeNode*> inorder = getInOrder(tree);
      for(int i = 0; i + 1 < inorder.size(); ++i){
        nextTable[ inorder[i] ] = inorder[i + 1];
      }
      nextTable[ inorder.back() ] = inorder.front();
    }

    TreeNode* getNext(TreeNode* node){
      auto ite = nextTable.find(node);
      if(ite == NULL) throw "This node doesn't exist!";
      return ite -> second;
    }
};
