/*
Problem: Implement Trie II
Link: https://www.naukri.com/code360/problems/implement-trie_1387095?leftPanelTabValue=PROBLEM
Difficulty: Medium
Approach: Trie
Time Complexity: O(L) for all operations
Note:
    here, you just need to maintain a count for prefix and ends
*/

#include <bits/stdc++.h> 
class TrieNode {
public:
    TrieNode* children[26] = {NULL};
    int prefixCount = 0;
    int endCount = 0;
};

class Trie{
public:
    TrieNode* root;
    
    Trie(){
        root = new TrieNode();
    }

    void insert(string &word){
        TrieNode* curr = root;
        for (int i=0; i<word.size(); i++){
        	int idx = word[i] - 'a';
            
            if (curr->children[idx] == NULL)
                curr->children[idx] = new TrieNode();
           
            curr = curr->children[idx];
            curr->prefixCount += 1;
        }
        curr->endCount += 1;
    }

    int countWordsEqualTo(string &word){
        TrieNode* curr = root;
        for (int i=0; i<word.size(); i++){
            int idx = word[i] - 'a';

            if (curr->children[idx] == NULL)
                return 0;
            
            curr = curr->children[idx];
        }
        return curr->endCount;
    }

    int countWordsStartingWith(string &word){
        TrieNode* curr = root;
        for (int i=0; i<word.size(); i++){
            int idx = word[i] - 'a';

            if (curr->children[idx] == NULL)
                return 0;
            
            curr = curr->children[idx];
        }
        return curr->prefixCount;
    }

    void erase(string &word){
        TrieNode* curr = root;
        for (int i=0; i<word.size(); i++){
        	int idx = word[i] - 'a';
            curr = curr->children[idx];
            curr->prefixCount -= 1;
        }
        curr->endCount -= 1;
    }
};
