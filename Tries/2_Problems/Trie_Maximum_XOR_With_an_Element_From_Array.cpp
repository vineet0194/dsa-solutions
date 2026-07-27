/*
Problem: 1707. Maximum XOR With an Element From Array
Link: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/
Difficulty: Hard
Approach: Bit Trie
Time Complexity: O(NlogN+QlogQ+32(N+Q))​
Note:
    
*/

class Node{
public:
    Node* left = {NULL};
    Node* right = {NULL};
    int num = -1;
};

class Trie{
public:
    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(int &num){
        Node* curr = root;
        for (int i=31; i>=0; i--){
            int ith_bit = (num >> i) & 1;
            if (ith_bit == 0){
                if (curr->left == NULL)
                    curr->left = new Node();
                curr = curr->left;
            }
            else{
                if (curr->right == NULL)
                    curr->right = new Node();
                curr = curr->right;
            }
        }
        curr->num = num;
    }

    int solve(int &num){
        Node* curr = root;
        for (int i=31; i>=0; i--){
            int ibit_num = (num >> i) & 1;

            if (ibit_num == 0){
                if (curr->right != NULL)
                    curr = curr->right;
                else if (curr->left != NULL)
                    curr = curr->left;
                else
                    return -1;
            }
            else{
                if (curr->left != NULL)
                    curr = curr->left;
                else if (curr->right != NULL)
                    curr = curr->right;
                else
                    return -1;
            }
        }
        return num ^ curr->num;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        Trie myTrie = Trie();

        int q = queries.size();
        vector<vector<int>> queryNew;
        
        for (int i=0; i<q; i++)
            queryNew.push_back({queries[i][0], queries[i][1], i});
        
        sort(queryNew.begin(), queryNew.end(), [](const auto &a, const auto &b){
            return a[1] < b[1];
        });

        int idx=0;
        vector<int> ans(q);

        for (int i=0; i<q; i++){
            int x = queryNew[i][0];
            int m = queryNew[i][1];
            int j = queryNew[i][2];
            while (idx < nums.size() && nums[idx] <= m){
                myTrie.insert(nums[idx]);
                idx++;
            }
            int temp = myTrie.solve(x);
            ans[j] = temp;
        }

        return ans;
    }
};