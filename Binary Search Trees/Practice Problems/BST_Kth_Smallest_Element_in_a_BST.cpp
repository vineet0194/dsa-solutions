/*
Problem: 230. Kth Smallest Element in a BST
Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
Difficulty: Medium
Approach: Inorder DFS
Time Complexity: O(n)
Note:
    BST follows Inorder Traversal => sorted order
    Hence we can do Inorder Traversal and keep a count of the nodes visited,
    when count == k => we have found the kth smallest element
*/

class Solution {
public:
    void helper(TreeNode* root, int k, int& i, int& kSmallest){
        if (root == NULL)
            return;
        
        helper(root->left, k, i, kSmallest);
        i++;
        if (i == k)
            kSmallest = root->val;
        helper(root->right, k, i, kSmallest);
    }

    int kthSmallest(TreeNode* root, int k) {
        int i=0;
        int kSmallest = -1;
        helper(root, k, i, kSmallest);

        return kSmallest;
    }
};