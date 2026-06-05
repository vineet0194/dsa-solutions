/*
Problem: 101. Symmetric Tree
Link: https://leetcode.com/problems/symmetric-tree/description/
Difficulty: Easy
Approach: Preorder DFS
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    bool isIdentical(TreeNode* p, TreeNode* q){
        if (p==NULL || q==NULL)
            return p==q;
        bool leftSame = isIdentical(p->left, q->right);
        bool rightSame = isIdentical(p->right, q->left);
        return (leftSame && rightSame && p->val==q->val);
    }
    bool isSymmetric(TreeNode* root) {
        if (root->left == NULL && root->right == NULL)
            return true;
        return isIdentical(root->left, root->right);
    }
};