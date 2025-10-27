//https://leetcode.com/problems/design-twitter
class Twitter {
public:
    unordered_map<int, unordered_set<int>> m_follow;//each user -> other user id
    unordered_map<int, priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>> m_tweet;//each user -> time, tweetid
    int t = 0;
    Twitter() {
    }
    
    void postTweet(int userId, int tweetId) {
        if(m_tweet[userId].empty() || m_tweet[userId].size() < 10)
            m_tweet[userId].push({t, tweetId});
        else{
            m_tweet[userId].pop();
            m_tweet[userId].push({t, tweetId});
        }
        t++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> pq;
        vector<int> user(m_follow[userId].begin(), m_follow[userId].end());
        user.push_back(userId);
        for(auto u: user){
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> temp = m_tweet[u];
            while(!temp.empty()){
                pq.push({temp.top().first, temp.top().second});
                temp.pop();
            }
        }
        vector<int> res;
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
            if(res.size() == 10)
                return res;
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
        m_follow[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        m_follow[followerId].erase(followeeId);
    }
};


// ["Twitter", "postTweet", "unfollow", "getNewsFeed", "follow", "unfollow", "unfollow", "follow", "postTweet", "unfollow", "getNewsFeed"]
// [[], [3, 0], [3, 1], [1], [3, 2], [1, 3], [1, 3], [3, 2], [2, 1], [2, 1], [3]]
// ["Twitter", "follow", "getNewsFeed", "follow", "follow", "follow", "postTweet", "getNewsFeed", "follow", "unfollow", "postTweet", "getNewsFeed", "follow", "getNewsFeed", "unfollow", "postTweet", "follow", "follow", "postTweet", "unfollow", "getNewsFeed"]
// [[], [1, 2], [1], [1, 2], [2, 3], [2, 1], [1, 0], [1], [2, 1], [3, 1], [3, 1], [3], [1, 3], [1], [3, 2], [1, 2], [3, 2], [3, 1], [3, 3], [2, 1], [2]]
// ["Twitter", "postTweet", "unfollow", "getNewsFeed", "unfollow", "unfollow", "postTweet", "follow", "follow", "postTweet", "unfollow", "postTweet", "postTweet", "getNewsFeed", "follow", "postTweet", "unfollow", "getNewsFeed", "follow", "getNewsFeed", "follow", "follow", "follow", "follow", "follow", "follow", "unfollow", "follow", "postTweet", "getNewsFeed", "unfollow", "unfollow", "follow", "getNewsFeed", "getNewsFeed", "follow", "postTweet", "postTweet", "unfollow", "unfollow", "unfollow", "unfollow", "unfollow", "unfollow", "postTweet", "follow", "getNewsFeed", "unfollow", "getNewsFeed", "getNewsFeed", "postTweet", "getNewsFeed", "unfollow", "unfollow", "unfollow", "follow", "getNewsFeed", "getNewsFeed", "getNewsFeed", "unfollow", "follow", "postTweet", "postTweet", "follow", "follow", "follow", "unfollow", "getNewsFeed", "getNewsFeed", "getNewsFeed", "postTweet", "getNewsFeed", "postTweet", "unfollow", "follow", "unfollow", "postTweet", "unfollow", "follow", "getNewsFeed", "postTweet", "follow", "getNewsFeed", "unfollow", "getNewsFeed", "getNewsFeed", "getNewsFeed", "getNewsFeed", "postTweet", "getNewsFeed", "getNewsFeed", "getNewsFeed", "getNewsFeed", "getNewsFeed", "unfollow", "postTweet", "follow", "unfollow", "getNewsFeed", "unfollow", "unfollow"]
// [[], [2, 0], [5, 1], [5], [4, 2], [2, 5], [4, 1], [2, 4], [1, 4], [3, 2], [2, 4], [3, 3], [3, 4], [5], [4, 2], [5, 5], [1, 3], [1], [2, 3], [3], [4, 2], [3, 5], [3, 1], [2, 4], [3, 2], [4, 3], [5, 2], [4, 2], [2, 6], [3], [2, 4], [3, 4], [3, 5], [2], [4], [1, 5], [2, 7], [4, 8], [2, 4], [4, 1], [3, 1], [5, 2], [3, 2], [5, 2], [3, 9], [2, 1], [3], [1, 2], [2], [1], [3, 10], [5], [4, 5], [5, 3], [4, 2], [5, 2], [2], [1], [2], [1, 5], [5, 2], [2, 11], [4, 12], [5, 1], [4, 2], [5, 2], [4, 3], [1], [2], [3], [5, 13], [3], [5, 14], [2, 4], [2, 1], [2, 1], [2, 15], [2, 5], [1, 2], [4], [5, 16], [2, 3], [2], [2, 3], [2], [3], [4], [3], [2, 17], [1], [2], [3], [3], [1], [2, 1], [3, 18], [4, 3], [1, 4], [1], [1, 5], [2, 1]]
// ["Twitter","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","postTweet","getNewsFeed"]
// [[],[1,5],[1,3],[1,101],[1,13],[1,10],[1,2],[1,94],[1,505],[1,333],[1,22],[1,11],[1]]
