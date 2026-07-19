/*
Problem: Count Dominant Nodes in a Binary Tree©leetcode
Link: https://leetcode.com/contest/weekly-contest-511/problems/count-dominant-nodes-in-a-binary-tree/description/
Difficulty: Medium
Approach: Preorder DFS
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int count;
    int solve(TreeNode* root){
        if (root == NULL)
            return 0;

        int leftMax = solve(root->left);
        int rightMax = solve(root->right);

        if (root->val >= leftMax && root->val >= rightMax)
            this->count++;
        return max(root->val, max(leftMax, rightMax));
    }
    int countDominantNodes(TreeNode* root) {
        this->count = 0;
        solve(root);
        return count;
    }
};