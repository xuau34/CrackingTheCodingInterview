/*
Time : O(N)
Space: O(N)
*/
int getPathNum(shared_ptr<TreeNode> node, int target, int sum = 0){
  if(node == nullptr) return 0;
  sum += node -> data;
  int pathNum = (sum == target);
  pathNum += getPathNum(node -> left, target, sum);
  pathNum += getPathNum(node -> right, target, sum);
  return pathNum;
}
