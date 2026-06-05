/*
Problem: 662. Maximum Width of Binary Tree
Link: https://leetcode.com/problems/maximum-width-of-binary-tree/description/
Difficulty: Medium
Approach: Level Order Iterative BFS
Time Complexity: 
Note:
    for a complete BT, if we follow 0 base indexing => if a parent nodes has an index i
    then left child has index 2*i + 1 and right child has 2*i + 2

    here we have to assume a complete BT, even if a node does not exist, indexing has to be as if it did exist
    at every level, width = maxIndex - minIndex + 1, out of all levels find the max and that's the ans

    using unsigned long long as at the worst, indexing can be in a right skewed trees which can only be handled like this
    or you need to normalise the indexes at every level such that at every level they start from 0
    how? deduct min index from all index vals in the same level,
    for a level 10, 11, 12, 13, 14 => (min=10) => 10-10=0, 11-10=1, 12-10=2, 13-10=3, 14-10=4 => new indices 10, 11, 12, 13, 14
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        int maxWidth=0, qsize=q.size();

        while(!q.empty()){
            qsize = q.size();
            unsigned long long first = (q.front()).second;
            unsigned long long last = (q.back()).second;
            maxWidth = max(maxWidth, (int)(last-first+1));

            for (int i=0; i<qsize; i++){
                TreeNode* curr = (q.front()).first;
                unsigned long long currIdx = (q.front()).second;
                q.pop();
                if (curr->left)
                    q.push({curr->left, 2*currIdx+1});
                if (curr->right)
                    q.push({curr->right, 2*currIdx+2});
            }
        }

        return maxWidth;        
    }
};