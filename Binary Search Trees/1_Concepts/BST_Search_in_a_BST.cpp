/*
Problem: 700. Search in a Binary Search Tree
Link: https://leetcode.com/problems/search-in-a-binary-search-tree/description/
Difficulty: Easy
Approach: Binary Search
Time Complexity: O(logn)
Note:
    
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL)
            return NULL;
        
        if (val < root->val)
            return searchBST(root->left, val);
        else if (val > root->val)
            return searchBST(root->right, val);
        else
            return root;
    }
};