/*
Problem: 145. Binary Tree Postorder Traversal
Link: https://leetcode.com/problems/binary-tree-postorder-traversal/
Difficulty: Easy
Approach: Recursive DFS
Time Complexity: O(n)
Note:
    follow order - Left Right Root
*/

class Solution {
public:
    void postTrav(vector<int>& arr, TreeNode* root){
        if (root == NULL)
            return;
        
        postTrav(arr, root->left);
        postTrav(arr, root->right);
        arr.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> arr;
        postTrav(arr, root);
        return arr;
    }
};