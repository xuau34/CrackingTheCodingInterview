/*
 
Time : O( W * H * D )
Space: O( W * H * D )
 
 */

#include <bits/stdC++.h>
using namespace std;

typedef struct{
  int width, height, depth;
}Box;


int getMaxStackDepth(vector<Box> boxes){
  unordered_map<int, unordered_map<int, unordered_map<int, int> > > dp;
  dp[0][0][0] = 0;
  int maxDepth = 0;
  for(Box box: boxes){
    int& target = dp[box.width][box.height][box.depth];
    for(int width = 0; width < box.width; ++width){
      auto ite = dp.find(width);
      if(ite == dp.end()) continue;
      auto& subDp = ite -> second;
      for(int height = 0; height < box.height; ++height){
        auto ite = subDp.find(height);
        if(ite == subDp.end()) continue;
        auto& subSubDp = ite -> second;
        for(int depth = 0; depth < box.depth; ++depth){
          auto ite = subSubDp.find(depth);
          if(ite == subSubDp.end()) continue;
          target = max(target, box.depth + ite -> second);
        }
      }
    }
    if(target > maxDepth) maxDepth = target;
  }
  return maxDepth;
}

int main(void){
  int N;
  cin >> N;
  vector<Box> boxes(N);
  for(int i = 0; i < N; ++i){
    cin >> boxes[i].width >> boxes[i].height >> boxes[i].depth;
  }
  cout << getMaxStackDepth(boxes) << endl;
}
