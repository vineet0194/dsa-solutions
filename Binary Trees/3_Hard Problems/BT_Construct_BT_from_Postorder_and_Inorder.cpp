/*
Problem: 106. Construct Binary Tree from Inorder and Postorder Traversal
Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
Difficulty: Medium
Approach: Iterate through preorder and search valid left and right subtree sequence in Inorder
Time Complexity: O(n)
Note:
    Follow Reverse of Postorder => ROOT-->RIGHT-->LEFT, rest everything is same as preorder and inorder
    make sure while doing so, make the right subtree first as we traverse right before left in reverse postorder
*/

class Solution {
public:
    TreeNode* buildTreeUsingInAndPost(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& inordMap, int& postInd, int l, int r){
        if (l > r || postInd >= postorder.size())
            return NULL;

        TreeNode* root = new TreeNode(postorder[postInd]);
        int inInd = inordMap[postorder[postInd++]];

        root->right = buildTreeUsingInAndPost(inorder, postorder, inordMap, postInd, inInd+1, r);
        root->left = buildTreeUsingInAndPost(inorder, postorder, inordMap, postInd, l, inInd-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i=0, j=postorder.size()-1;
        // reverse postorder array => follow ROOT->RIGHT->LEFT
        while (i<j){
            int temp = postorder[i];
            postorder[i++] = postorder[j];
            postorder[j--] = temp;
        }
        unordered_map<int, int> inordMap;
        for (int k=0; k<inorder.size(); k++){
            inordMap[inorder[k]]=k;
        }
        int postInd=0;
        TreeNode* ans = buildTreeUsingInAndPost(inorder, postorder, inordMap, postInd, 0, inorder.size()-1);

        return ans;
    }
};