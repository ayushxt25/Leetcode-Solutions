class Twitter {
    int time = 0;
    unordered_map<int, unordered_set<int>> following;
    unordered_map<int, vector<pair<int, int>>> tweets;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<tuple<int, int, int, int>> pq;
        vector<int> users(following[userId].begin(), following[userId].end());
        users.push_back(userId);

        for (int uid : users) {
            if (!tweets[uid].empty()) {
                int idx = tweets[uid].size() - 1;
                auto [t, tweetId] = tweets[uid][idx];
                pq.push({t, tweetId, uid, idx});
            }
        }

        vector<int> feed;

        while (!pq.empty() && feed.size() < 10) {
            auto [t, tweetId, uid, idx] = pq.top();
            pq.pop();

            feed.push_back(tweetId);

            if (idx > 0) {
                auto [nt, nid] = tweets[uid][idx - 1];
                pq.push({nt, nid, uid, idx - 1});
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};