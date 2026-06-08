/*
Problem: 222. Count Complete Tree Nodes
Link: https://leetcode.com/problems/count-complete-tree-nodes/description/
Difficulty: Hard
Approach: DFS
Time Complexity: O(logn)
Note:
    if a tree is perfect (automatically complete) then the node count formula stands=> 2^h - 1
    so if we compute slant height in left and slant height in right, if they are same
    that means the nodes in the middle must be filled (complete BT is guaranteed). so the nodeCount = 2^h - 1
    h = left slant or right slant height (doesnt matter as both are equal)

    NOTE: these are slant heights (not actual heigh/depth of a tree)

    if not, then we count the current node as total count (recursively) and move to the next node in left and right subtrees
    and check for perfectness there and repeat these steps in recursion to find the total number of nodes in 
    a complete BT in o(logN) [ down from O(n) from regular DFS ].

    this is what makes this a diff : Hard
*/

class Solution {
public:
    // left slant height
    int leftSlantHeight(TreeNode* curr){
        int ht = 0;
        while (curr){
            ht++;
            curr = curr->left;
        }
        return ht;
    }
    // right slant height
    int rightSlantHeight(TreeNode* curr){
        int ht = 0;
        while (curr){
            ht++;
            curr = curr->right;
        }
        return ht;
    }

    int countNodes(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        int leftSlantH = leftSlantHeight(root);   // including root
        int rightSlantH = rightSlantHeight(root); // including root

        if (leftC == rightC)        // perfect tree found
            return (1<<leftC)-1;
        
        // count current node then look for perfect
        // trees down the Left and Right subtrees
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};