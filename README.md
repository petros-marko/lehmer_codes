# lehmer_codes
A set of functions to generate permutations of a character array using Lehmer Codes.

# What are Lehmer Codes?

My (not very thorough) understanding of Lehmer Codes is that each entry of the code gives the index of the next item in the permutation if the elements corresponding to all previous entries have been removed. This lines up nicely with the intuition (at least my intuition) about permutations which is that one selects the first element out of the entire array, then the next from the array except the first etc. Apparently, if the character array is initially sorted and Lehmer Codes taken sequentially, then the corresponding permutations are given in lexicographic order.

# How can we get a permutation from a Lehmer Code
1. The Naive Method: Go through the entries of the code sequentially, add the corresponding character (say the i-th) to the result and remove the character from the original array. This corresponds directly to the definition of Lehmer Codes and is very easy to implement, but it is rather inefficient, taking O(n^2^) time (where n is the size of the permutation) if done with either an underlying array or linked list.
2. The Count Tree Method: If instead of an array or a linked list we use a binary tree, lookups and deletes take O(logn) time, so the total runtime is O(nlogn). A slight improvement over that is what I call a count tree because I'm bad at naming things and I didn't look up if it already has a name: each node in the Count Tree also stores the number of leaves in its subtrees. This way, we don't need to actually remove any elements from the tree, so if we are careful to reset the counts after each time we find a permutation, we can reuse the same tree, saving time on allocating and deallocating memory.
