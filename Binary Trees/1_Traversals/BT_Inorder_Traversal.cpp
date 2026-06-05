/*
Problem: 94. Binary Tree Inorder Traversal
Link: https://leetcode.com/problems/binary-tree-inorder-traversal/
Difficulty: Easy
Approach: Recursive DFS
Time Complexity: O(n)
Note:
    follow order - Left Root Right
*/

class Solution {
public:
    void inTrav(vector<int>& arr, TreeNode* root){
        if (root == NULL)
            return;
        
        inTrav(arr, root->left);
        arr.push_back(root->val);
        inTrav(arr, root->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> arr;
        inTrav(arr, root);
        return arr;
    }
};