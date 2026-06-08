/*
Problem: Left View of Binary Tree
Link: https://www.geeksforgeeks.org/problems/left-view-of-binary-tree/1
Difficulty: Easy
Approach: Level order BFS
Time Complexity: O(n)
Note:
    catch the first elem, push in ans, use rest only to push children nodes
*/

class Solution {
  public:
    void lsv(Node* root, vector<int>& ans){
        queue<Node*> q;
        q.push(root);
        int qsize = q.size();
        while (qsize>0){
            for (int i=0; i<qsize; i++){
                Node* curr = q.front();
                q.pop();
                if (i == 0)
                    ans.push_back(curr->data);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            qsize = q.size();
        }
    }
    vector<int> leftView(Node *root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
        lsv(root, ans);
        
        return ans;
    }
};