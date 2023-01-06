/*
Given an integer n, return the number of structurally unique BST's (binary search trees) 
which has exactly n nodes of unique values from 1 to n.
Example:
Input: n = 3
Output: 5
*/
//credit to archit91
//we will use recursive
/*
BST consisting of n nodes, we can start by taking any of the node 1...n as the root node. 
Let the chosen root node be i. Then, we have a BST where the root node is i, 
the left child consist of all nodes from 1...i-1 (since left sub-tree must have only less 
than root's value) and right child consist of all nodes from i+1...n.
The total number of structurally unique BSTs formed having root i will be equal to product of 
these two, i.e, numTrees(i-1) * numTrees(n-i). The same can be followed recursively till we reach 
base case - numTrees(0) = numTrees(1) = 1 because we can form only a single empty BST and single 
node BST in these cases respectively.*/
class Solution {
public:
    int numTrees(int n) {
        if (n<=1)return 1;
        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += numTrees(i-1)* numTrees(n-i);
        }
        return ans;
    }
};
/*
Time Complexity : O(3N), where N is the given number of nodes in BST. Read here for proof.
Space Complexity : O(N), the maximum recursive stack depth.*/