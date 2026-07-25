/*
Problem: Longest Valid Word with All Prefixes
Link: https://www.geeksforgeeks.org/problems/longest-valid-word-with-all-prefixes/1
Difficulty: Medium
Approach: Trie
Time Complexity: O(nlog(n)*L + n*L)
                    n = number of words
                    l = maximum length of a word
                
                O(nlog(n)*L) for sorting as each comparison may take at max O(l) time
                O(L) for each solve operation and for 'n' => O(nL)
Note:
    
*/

class Node{
public:
    Node* children[26] = { NULL };
    bool isEnd=false;
};

class Trie{
public:
    Node* root;
    
    Trie(){
        root = new Node();
    }
    
    void insert(string& word){
        Node* curr = root;
        for (int i=0; i<word.size(); i++){
            int idx = word[i]-'a';
            
            if (curr->children[idx] == NULL)
                curr->children[idx] = new Node();
            
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool solve(string& word){
        Node* curr = root;
        for (int i=0; i<word.size(); i++){
            int idx = word[i]-'a';
            
            curr = curr->children[idx];
            
            if (curr->isEnd == false)
                return false;
        }
        return true;
    }
};


class Solution {
public:
    string longestValidWord(vector<string>& words) {
        
        sort(words.begin(), words.end());
        
        Trie myTrie = Trie();
        
        for (auto& word : words)
            myTrie.insert(word);
        
        string ans = "";
        for (auto& word : words){
            if (myTrie.solve(word)){
                if (word.size() > ans.size())
                    ans = word;
            }
        }
        
        return ans;
    }
};
