/*
Problem: 100. Same Tree
Link: https://leetcode.com/problems/same-tree/description/
Difficulty: Easy
Approach: Preorder DFS
Time Complexity: O(n)
Note:
    
*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL || q==NULL)
            return p==q;

        bool isLeftSame = isSameTree(p->left, q->left);
        bool isRightSame = isSameTree(p->right, q->right);
        return (isLeftSame && isRightSame && p->val == q->val);
    }
};