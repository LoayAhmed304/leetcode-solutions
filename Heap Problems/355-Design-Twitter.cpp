class Twitter {
private:
    int time;
    unordered_map<int, vector<vector<int>>>tweets;
    map<int, set<int>>followMap;
public:
    Twitter() {
        time =0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        followMap[userId].insert(userId);
        auto compare = [&](vector<int>& p1, vector<int>& p2){
            return p1[0] < p2[0];
        };
        priority_queue<vector<int>, vector<vector<int>>, decltype(compare)>minHeap(compare);

        for(auto& followedUser: followMap[userId]){
            for(auto& tweet: tweets[followedUser]){
                minHeap.push(tweet);
            }
        }
        
        vector<int> res;
        for(int i =0; i<10 && !minHeap.empty(); i++){
            res.push_back(minHeap.top()[1]);
            minHeap.pop();
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followMap[followerId].erase(followeeId);
    }
};
