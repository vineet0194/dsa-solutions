/*
Problem: 543. Diameter of Binary Tree
Link: https://leetcode.com/problems/diameter-of-binary-tree/description/
Difficulty: Easy
Approach: Preorder DFS
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    int calcDiam(TreeNode* root, int& ans){
        if (root == NULL)
            return 0;
        int leftH = calcDiam(root->left, ans);
        int rightH = calcDiam(root->right, ans);
        ans = max(leftH+rightH, ans);
        return 1+max(leftH, rightH);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int temp = -1;
        calcDiam(root, temp);
        return temp;
    }
};