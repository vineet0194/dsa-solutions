/*
Problem: 105. Construct Binary Tree from Preorder and Inorder Traversal
Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
Difficulty: Medium
Approach: Iterate through preorder and search valid left and right subtree sequence in Inorder
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    TreeNode* buildTreeUsingPnI(vector<int>& preorder, vector<int>& inorder, unordered_map<int,int>& inorderMap, int& preIdx, int l, int r){
        // this is the only basecheck required so as to maintain the L and R limits of a node's subtree
        if (l > r || preIdx >= preorder.size())
            return NULL;

        TreeNode* root = new TreeNode(preorder[preIdx]);

        int inIdx = inorderMap[preorder[preIdx++]];

        root->left = buildTreeUsingPnI(preorder, inorder, inorderMap, preIdx, l, inIdx-1);
        root->right = buildTreeUsingPnI(preorder, inorder, inorderMap, preIdx, inIdx+1, r);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        unordered_map<int, int> inorderMap;
        for (int i=0; i<inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        return buildTreeUsingPnI(preorder, inorder, inorderMap, preIdx, 0, inorder.size()-1);
    }
};