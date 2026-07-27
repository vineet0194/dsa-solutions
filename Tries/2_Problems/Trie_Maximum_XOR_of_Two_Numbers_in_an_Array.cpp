/*
Problem: 421. Maximum XOR of Two Numbers in an Array
Link: https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array/description/
Difficulty: Medium
Approach: Bit Trie
Time Complexity: O(32 * n)
Note:
    
*/

class Node{
public:
    Node* left = NULL;
    Node* right = NULL;
    int num = -1;   // also marks eow
};

class Trie{
public:
    Node* root = NULL;

    Trie(){
        root = new Node();
    }

    void insert(int& num){
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

    int solve(int& num){
        Node* curr = root;
        for (int i=31; i>=0; i--){
            int ith_bit = (num >> i) & 1;
            if (ith_bit == 0){
                if (curr->right != NULL)
                    curr = curr->right;
                else
                    curr = curr->left;
            }
            else{
                if (curr->left != NULL)
                    curr = curr->left;
                else
                    curr = curr->right;
            }
        }
        return num ^ (curr->num);
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie myTrie = Trie();

        for (auto& num : nums)
            myTrie.insert(num);

        int maxi = -1;
        for (auto& num: nums){
            int temp = myTrie.solve(num);
            maxi = max(maxi, temp);
        }

        return maxi;
    }
};