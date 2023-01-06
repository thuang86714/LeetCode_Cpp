//credit still goes to archit91
/*
DFS:
The problem doesn't intuitively fall under BFS but it can be solved using this traversal approach as well.
Time Complexity : O(N), standard time complexity of a BFS. Each node is only visited once.
Space Complexity : O(N), atmost (N+1)/2 elements will be stored in queue in case of complete binary tree.
*/
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        while(q.size()) {
            auto [n, cur] = q.front(); q.pop();
            cur = cur * 10 + n -> val;
            if(n -> left) q.push({n -> left, cur});      
            if(n -> right) q.push({n -> right, cur});
            if(!n -> left && !n -> right) sum += cur;   // add to total sum if we are at leaf node
        }
        return sum;
    }
};
/*Morris Traversal
This solution involves using the morris traversal technique to solve the problem. 
The advantage of this traversal is that we can traverse the tree in O(1) space complexity. 
The basic idea is to link predecessors to root nodes so we can trace it back once we have 
traversed a side without need of using a stack. It's a bit hard to explain in words so I have 
attached an image of how it works below. 
Time Complexity : O(N)
Space Complexity : O(1)*/
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int sum = 0, cur = 0, depth = 0;
        while(root) {
            if(root -> left) {
                auto pre = root -> left;
                depth = 1;
                while(pre -> right && pre -> right != root) 
                    pre = pre -> right, depth++;
                if(!pre -> right) {
                    pre -> right = root;
                    cur = cur * 10 + root -> val;
                    root = root -> left;
                } else {
                    pre -> right = nullptr;
                    if(!pre -> left) sum += cur;
                    cur /= pow(10, depth);
                    root = root -> right;
                }
            } else {
                cur = cur * 10 + root -> val;
                if(!root -> right) sum += cur;
                root = root -> right;
            }
        }
        return sum;
    }
};