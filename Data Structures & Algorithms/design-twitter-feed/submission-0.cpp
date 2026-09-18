class Twitter {
public:
    int ts = 0;
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int, unordered_set<int>> follows;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({ts++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto tweet: tweets[userId]) pq.push(tweet);
        for(auto follow: follows[userId]){
            for(auto tweet: tweets[follow]){
                pq.push(tweet);
            }
        }
        vector<int> result;
        while(!pq.empty()&&result.size()<10){
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
    
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follows[followerId].erase(followeeId);
    }
};
