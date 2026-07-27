/*
Problem: Count of distinct substrings
Link: https://www.geeksforgeeks.org/problems/count-of-distinct-substrings/1
Difficulty: Medium
Approach: Trie
Time Complexity: O(n^2)
Note:
    
*/

class Node{
public:
    Node* children[26]= { NULL };
}; 

class Trie{
public:
    Node* root;
    int count;
    
    Trie(){
        root = new Node();
        count = 0;
    }
    
    int insert(string& word){
        Node* curr = root;
        for (int i=0; i<word.size(); i++){
            int idx = word[i] - 'a';
            
            if (curr->children[idx] == NULL){
                curr->children[idx] = new Node();
                count++;
            }

            curr = curr->children[idx];
        }
        return count;
    }
};

class Solution {
  public:
    int countSubs(string& s) {
        int n = s.size();
        vector<string> suffix;
    
        // Suffix Array Generation
        for (int i=n-1; i>=0; i--){
            string temp = "";
            
            for (int j=i; j<n; j++)
                temp += s[j];
                
            suffix.push_back(temp);
        }
        
        // Prefix Tree of Suffixes
        Trie myTrie = Trie();
        for (auto& sf: suffix)
            myTrie.insert(sf);
        
        return myTrie.count;
    }
};