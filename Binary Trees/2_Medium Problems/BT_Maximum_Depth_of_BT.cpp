/*
Problem: 104. Maximum Depth of Binary Tree
Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
Difficulty: Easy
Approach: Recursive BFS Postorder
Time Complexity: O(n)
Note:
    at a certain node, max height is the max path from current node to any leaf in the node's subtrees
    max(left, right) will give that max path lenght + 1 for the current node's level will be returned
*/

class Solution {
public:
    int calcHeight(TreeNode* root){
        if (root == NULL)
            return 0;
        int a = calcHeight(root->left);
        int b = calcHeight(root->right);
        return 1+max(a,b);
    }
    int maxDepth(TreeNode* root) {
        return calcHeight(root);
    }
};