/*
 
1)
  Use merge_sort, which needs to divide the whole dataset into 4 batches. One batch has 1 GB data, which is approximately 10^6 integers. So far, the time complexity is O(10^6 log 10^6).
  To get the minimum integer within these batches, use loser tree, which requires space for O(4) and time for O(log 4) for each minimum.
  Continue generate the missing integers til meeting the top of the loser tree, then repetatively maintaining the loser tree and generating missing integers.
  In overall, the time complexity is O(10^6 * log 10^6), and the space complexity is O(10^6)
   
  Or use radix sort to rearrange the data, so that we can find if colliding or not in O(k*10^6) time complexity, if and only if we can use the external memory unlimitedly.
 
 */
