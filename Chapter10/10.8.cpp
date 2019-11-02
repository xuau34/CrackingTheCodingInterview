/*

   4KB = 4 * 2^10 bytes = 32 * 2^10 bits > 32*10^3
   1 ~ N, N <= 32 * 10^3
   If no care about print duplicately, but just correctly, then we can use a boolean array with size of 32000, and print the value everytime the value has been marked as visited.

   If not allowed to print duplicately, then we must seperate the memory - two boolean arrays with half size, one indicates it has been visited; the other indicates it's duplicated.
   It costs 2 passes totally.

   If we cannot make so tight memory use, then we will need at least three passes to finish it. 
   To seperate the dataset evenly, 32000/3 = 10666.666. This size will still need to use two boolean array but not integer array.
 
 */
