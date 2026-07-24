/*
Problem: 208. Implement Trie I
Link: https://leetcode.com/problems/implement-trie-prefix-tree/description/
Difficulty: Medium
Approach: Trie (Prefix Trees)
Time Complexity:                L => length of string
                Insert: O(L)
                Search: O(L)
                StartsWith: O(L)
Note:
    A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys
    in a dataset of strings. There are various applications of this data structure, such as autocomplete and 
    spellchecker.

    class TrieNode{
    public:
        TrieNode* children[26];
        bool isEnd;
    };

    here, 
    children array: Stores pointers/references to the current node's child nodes. Each index corresponds to a 
    character (e.g., children[0] → 'a', children[1] → 'b', ..., children[25] → 'z'). If children[i] is NULL, that 
    character does not continue from the current node.
    
    isEnd flag: A boolean that indicates whether the current node marks the end of a complete word. This 
    distinguishes complete words from mere prefixes. For example, if "cat" is inserted, the node for 't'
    has isEnd = true, while the nodes for 'c' and 'a' have isEnd = false.
*/

class TrieNode {
public:
    TrieNode* children[26] = {nullptr};
    bool isEnd = false;
};

class Trie {
private:
    TrieNode* root;

public:
    // Trie constructor (creates a root node)
    Trie() {
        this->root = new TrieNode();
    }
    
    void insert(string word) {                  // O(L)
        TrieNode* curr = root;
        for (int i=0; i<word.size(); i++){
            int idx = word[i] - 'a';
            
            if (curr->children[idx] == NULL)
                curr->children[idx] = new TrieNode();
            
            curr = curr->children[idx];
        }
        curr->isEnd = true;
    }
    
    bool search(string word) {                  // O(L)
        TrieNode* curr = root;
        for (int i=0; i<word.size(); i++){
            int idx = word[i] - 'a';

            if (curr->children[idx] == NULL)
                return false;

            curr = curr->children[idx];
        }
        return curr->isEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (int i=0; i<prefix.size(); i++){
            int idx = prefix[i] - 'a';

            if (curr->children[idx] == NULL)
                return false;

            curr = curr->children[idx];
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */