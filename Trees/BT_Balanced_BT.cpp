/*
Problem: 110. Balanced Binary Tree
Link: https://leetcode.com/problems/balanced-binary-tree/
Difficulty: Easy
Approach: Recursive DFS
Time Complexity: O(n)
Note:
    basically, calculating height at each node and checking if diff of left & right subtree height > 1
*/

class Solution {
public:
    int balanceCheck(TreeNode* root, bool& flag){
        if (root == NULL)
            return 0;
        int leftH = balanceCheck(root->left, flag);
        int rightH = balanceCheck(root->right, flag);

        if (abs(leftH-rightH)>1)
            flag = false;
        return 1+max(leftH, rightH);
    }
    bool isBalanced(TreeNode* root) {
        if (root == NULL)
            return true;
        bool flag = true;
        balanceCheck(root, flag);
        return flag;
    }
};