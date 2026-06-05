/*
Problem: Level of a Node in Binary Tree
Link: https://www.geeksforgeeks.org/problems/level-of-a-node-in-binary-tree/1
Difficulty: Easy
Approach: Preorder DFS
Time Complexity: O(n)
Note:
    going down a level => current depth +1
    assuming root node is at level 1, therefore we pass currH = 1 initially
*/

class Solution {
  public:
    int getLevelOfNode(Node* root, int currH, int target){
        if (root == NULL)
            return 0;
        if (root->data == target)
            return currH;
        int a = getLevelOfNode(root->left, currH+1, target);
        int b = getLevelOfNode(root->right, currH+1, target);
        return max(a,b);
    }
    int getLevel(struct Node *node, int target) {
        return getLevelOfNode(node, 1, target);
    }
};