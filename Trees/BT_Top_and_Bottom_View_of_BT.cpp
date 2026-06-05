/*
Problem: Top View of Binary Tree
         Bottom View of Binary Tree
Link: https://www.geeksforgeeks.org/problems/top-view-of-binary-tree/1
Difficulty: Medium
Approach: Level order BFS
Time Complexity: O(n)
Note:
    
*/

// TOP VIEW:
class Solution {
  public:
    void getTopView(Node* root, map<int, Node*>& mp){
        queue<pair<int, Node*>> q;
        q.push({0, root});
        
        while (!q.empty()){
            Node* curr = (q.front()).second;
            int hd = (q.front()).first;
            q.pop();
            
            if (mp.find(hd) == mp.end())
                mp[hd] = curr;
            if (curr->left != NULL)
                q.push({hd-1, curr->left});
            if (curr->right != NULL)
                q.push({hd+1, curr->right});
        }
    }
  
    vector<int> topView(Node *root) {
        vector<int> topArr;
        map<int, Node*> mp;
        getTopView(root, mp);
        
        for (auto& it: mp){
            topArr.emplace_back(it.second->data);
        }
        
        return topArr;
    }
};

// BOTTOM VIEW:
class Solution {
  public:
      void getBottomView(Node* root, map<int, Node*>& mp){
        queue<pair<int, Node*>> q;
        q.push({0, root});
        
        while (!q.empty()){
            Node* curr = (q.front()).second;
            int hd = (q.front()).first;
            q.pop();
            
            mp[hd] = curr;
            if (curr->left != NULL)
                q.push({hd-1, curr->left});
            if (curr->right != NULL)
                q.push({hd+1, curr->right});
        }
    }
  
    vector<int> bottomView(Node *root) {
        vector<int> bottomArr;
        map<int, Node*> mp;
        getBottomView(root, mp);
        
        for (auto& it: mp){
            bottomArr.emplace_back(it.second->data);
        }
        
        return bottomArr;
    }
};