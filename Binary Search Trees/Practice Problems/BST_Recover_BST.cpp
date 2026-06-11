/*
Problem: 99. Recover Binary Search Tree
Link: https://leetcode.com/problems/recover-binary-search-tree/description/
Difficulty: Medium
Approach: Inorder DFS
Time Complexity: O(n)
Note:
    Explore the BST in Inorder traversal and maintain first, middle, second and last
    if (last==NULL) => no elements traversed yet
        so always start from the checks from the second node
    if (root < last->val) => a violation has occured fill into first or second accordingly
        if first is NULL => this is the first violation => fill in first (also maintain a MID if the swap is adjacent)
                ! adjacent swaps wont be caught in 2 violation => for them, second will be NULL !
        if first is not NULL => this is the second violation => fill in second
    let the entire tree be traversed

    after that, if second != NULL => a second violation has occured => non-adjacent swap => swap(first, second)
                if second == NULL => an adjacent swap has occured => swap(first, middle)
*/

class Solution {
public:
    void swapValues(TreeNode*& A, TreeNode*& B){
        int tempA = A->val;
        A->val = B->val;
        B->val = tempA;
        return;
    }

    void helper(TreeNode* root, TreeNode*& first, TreeNode*& middle, TreeNode*& second, TreeNode*& last){
        if (root == NULL)
            return;
        
        helper(root->left, first, middle, second, last);

        if (last!=NULL){            // not the first elem
            if (root->val < last->val){     // violation occurs
                if (first==NULL){   // first is NULL => first violation
                    first = last;
                    middle = root;
                }
                else                // first is not NULL => second violation
                    second = root;
            }
        }
        last = root;

        helper(root->right, first, middle, second, last);
    }

    void recoverTree(TreeNode* root) {
    TreeNode* first = NULL;     // first violation
    TreeNode* middle = NULL;    // first's mid
    TreeNode* second = NULL;    // second violation
    TreeNode* last = NULL;      // last node visited
    
    helper(root, first, middle, second, last);
    
    if (second == NULL)
        swapValues(first, middle);
    else
        swapValues(first, second);
    
    return;
    }
};