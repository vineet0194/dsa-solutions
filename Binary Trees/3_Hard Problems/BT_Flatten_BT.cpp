/*
Problem: 114. Flatten Binary Tree to Linked List
Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/
Difficulty: Medium
Approach: DFS with reverse Preorder (Right, Left, Root)
Time Complexity: O(n)
Note:
    
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* nextRight=NULL;
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        root->left = NULL;
        root->right = nextRight;
        nextRight = root;
    }
};