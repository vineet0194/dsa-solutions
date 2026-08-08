/*
Problem: 355. Design Twitter
Link: https://leetcode.com/problems/design-twitter/description/
Difficulty: Medium
Approach: Max Heap
Time Complexity:
    - postTweet(): O(log T)
    - follow(): O(1) average
    - unfollow(): O(1) average
    - getNewsFeed(): O(F*logT + F*log F)
Note:
    
*/

class Twitter {
public:
    vector<unordered_set<int>> follows;    // user[0] = {1,2,3 followed};
    vector<priority_queue<pair<int, int>>> tweets;    // user[0] = pq(tweet)
    int idx;  // tweetIndex

    Twitter() {
        (this->follows).resize(501);
        (this->tweets).resize(501);
        this->idx = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push({idx++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> res;

        // followers' tweets
        for (auto& followee : follows[userId]){
            vector<pair<int, int>> temp;
            for (int i=0; i<10; i++){
                if (!tweets[followee].empty()){
                    auto& tweet = tweets[followee].top();
                    res.push(tweet);
                    temp.push_back(tweet);
                    tweets[followee].pop();
                }
            }
            for (auto& tweet: temp)
                tweets[followee].push(tweet);
        }

        // self's tweets
        vector<pair<int, int>> temp;
        for (int i=0; i<10; i++){
            if (!tweets[userId].empty()){
                auto& tweet = tweets[userId].top();
                res.push(tweet);
                temp.push_back(tweet);
                tweets[userId].pop();
            }
        }
        for (auto& tweet: temp)
            tweets[userId].push(tweet);

        vector<int> ans;
        while (!res.empty()){
            if (ans.size() == 10)
                break;
            if (!res.empty()){
                auto& tweet = res.top();
                ans.emplace_back(tweet.second);
                res.pop();
            }
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;
        
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (followerId == followeeId)
            return;
        
        follows[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */