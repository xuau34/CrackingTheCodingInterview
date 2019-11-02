/*
 
20GB => Memory problem that we can't have so much memory at one time. Therefore, we have to segment them as batches. The size of batches is based on the maximum memory that we can have.
For each batch, we can sort them each by each.
Then using winner tree or loser tree to select the maximun/minimum element of these batches, and fill these numbers orderly into one file.

For each batch, the time complexity is O(NlogN).
For the loser tree, the time complexity of each loser/winner is O(log(batch size)), and the space complexity is O(batch size)
So the total time complexity will be O(batch size * (NlogN + log(batch size)))
 
*/
