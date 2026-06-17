/*
Problem: 127. Word Ladder
Link: https://leetcode.com/problems/word-ladder/description/
Difficulty: Hard
Approach: BFS + Hashing
Time Complexity: O(NL^2)        =>  L = length of each word, N = no. of words
Note:
    wordSet represents all the non-visited words (nodes) in the given graph
    if we visit a node we remove that word from the set (so a match cant appear again in the BFS tree and we dont re-visit)
    brute forcely try all combinations that exist for curr[i] and check if it exists in the wordSet

    BFS guarantees that in a non-weighted graph, first apperance of a node is definetly its shortest path from source
    in terms of number of edges (as what is suggested by non-weighted => number of edges = total weight)

    so source->curr = wordLength
*/

class Solution {
public:
    int bfsLadder(string beginWord, string endWord, unordered_set<string>& set){
        queue<pair<string, int>> q;

        q.push({beginWord, 1});
        set.erase(beginWord);
        
        int qsize = q.size();

        while (!q.empty()){
            int qsize = q.size();
            for (int i=0; i<qsize; i++){
                string curr = q.front().first;
                int currLength = q.front().second;
                q.pop();
                if (curr == endWord)
                    return currLength;
                for (int i=0; i<curr.size(); i++){
                    char temp = curr[i];                // store the original letter in curr[i] place
                    for (char j='a'; j<'z'+1; j++){     // check all possible combinations a-z for curr[i] place
                        if (j == temp) continue;
                        curr[i] = j;
                        if (set.find(curr)!=set.end()){
                            q.push({curr, currLength+1});
                            set.erase(curr);                // removing from set => visited
                        }
                    }
                    curr[i] = temp;             // all processed for curr[i], restore and move to next letter
                }
            }
        }

        return 0;
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        if (wordSet.find(endWord) == wordSet.end())
            return 0;

        int length = bfsLadder(beginWord, endWord, wordSet);

        return length;
    }
};