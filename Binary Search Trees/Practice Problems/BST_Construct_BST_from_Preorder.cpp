/*
Problem: 1008. Construct Binary Search Tree from Preorder Traversal
Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/
Difficulty: Medium
Approach: Iterate through preorder and search valid left and right subtree sequence in Inorder
Time Complexity: O(nlogn)
Note:
    basically, first constructing the inorder sequence of the given tree by the following the principle 
    that the inorder traversal of a BST results in a sorted order of all the elements.
    therefore sorting the preorder array gives us the inorder sequence

    now use preorder and inorder to construct the bst as a regular tree

    ! scroll down for optimal solution !
*/

class Solution {
public:
    TreeNode* bstFromPreAndIn(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& inorderMap, int& i, int l, int r){
        if (l > r || i > preorder.size())
            return NULL;

        TreeNode* root = new TreeNode(preorder[i]);
        int inIdx = inorderMap[preorder[i++]];

        root->left = bstFromPreAndIn(preorder, inorder, inorderMap, i, l, inIdx-1);
        root->right = bstFromPreAndIn(preorder, inorder, inorderMap, i, inIdx+1, r);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;
        sort(inorder.begin(), inorder.end());

        unordered_map<int, int> inorderMap;
        for (int i=0; i<inorder.size(); i++)
            inorderMap[inorder[i]] = i;

        int i=0;
        TreeNode* root = bstFromPreAndIn(preorder, inorder, inorderMap, i, 0, inorder.size()-1);

        return root;
    }
};

/* --------------------------------------------------------------------------------------------------------------- */

// OPTIMAL SOLUTION O(n)
/*
    we follow the preorder traversal (Root, Left, Right) and maintain an Upper Bound (UB), initially INT_MAX,
    if a current node's value is less than the UB => we create the node, increment i and then move to the left
    when moving left => we know all nodes to the left of a node in BST are smaller than that, so UB = root->val
    when moving right => we know all nodes to the right of a node in BST are larger than that, so UB(new) = UB(old as received in func during recursion)

    if we surpass the preorder array or a node's value is > UB, we return NULL for curr node's left or right
    then proceed to check for the next valid place to insert that node (where preorder[i] or curr value < UB)
*/

class Solution {
public:
    TreeNode* bstFromPre(vector<int>& preorder, int& i, int UB){
        if (i >= preorder.size() || preorder[i] > UB)
            return NULL;

        TreeNode* root = new TreeNode(preorder[i++]);
        root->left = bstFromPre(preorder, i, root->val);
        root->right = bstFromPre(preorder, i, UB);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        TreeNode* root = bstFromPre(preorder, i, INT_MAX);
        return root;
    }
};