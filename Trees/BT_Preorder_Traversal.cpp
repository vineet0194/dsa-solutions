/*
Problem: 144. Binary Tree Preorder Traversal
Link: https://leetcode.com/problems/binary-tree-preorder-traversal/
Difficulty: Easy
Approach: Recursive DFS
Time Complexity: O(n)
Note:
    follow order - Root Left Right
*/

class Solution {
public:
    void preTrav(vector<int>& arr, TreeNode* root){
        if (root == NULL)
            return;
        
        arr.push_back(root->val);
        preTrav(arr, root->left);
        preTrav(arr, root->right);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> arr;
        preTrav(arr, root);
        return arr;
    }
};