#include <unordered_set>
#include <vector>
#include <utility>
#include <unordered_map>
#include <memory>
#include <queue>
using namespace std;

class User
{
public:
    int id;
    unordered_set<int> following;
    vector<pair<int, int>> tweets; // {timestamp, tweetId}

    User(int userId) : id(userId)
    {
        following.insert(userId);
    }

    void post(int time, int tweetId)
    {
        tweets.push_back({time, tweetId});
    }
};

class Twitter
{
private:
    int timestamp = 0;
    unordered_map<int, shared_ptr<User>> users;

public:
    Twitter() {}

    void postTweet(int userId, int tweetId)
    {
        if (!users.count(userId))
            users[userId] = make_shared<User>(userId);

        users[userId]->post(timestamp++, tweetId);
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> result;
        if (!users.count(userId))
            return result;

        // max heap: {timestamp, tweetId}
        priority_queue<pair<int, int>> pq;

        for (int followeeId : users[userId]->following)
        {
            if (!users.count(followeeId))
                continue;
            auto &tweets = users[followeeId]->tweets;

            for (int i = tweets.size() - 1; i >= 0 && i >= (int)tweets.size() - 10; --i)
            {
                pq.push(tweets[i]);
            }
        }

        int count = 0;
        while (!pq.empty() && count++ < 10)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }

        return result;
    }

    void follow(int followerId, int followeeId)
    {
        if (!users.count(followerId))
            users[followerId] = make_shared<User>(followerId);
        if (!users.count(followeeId))
            users[followeeId] = make_shared<User>(followeeId);

        users[followerId]->following.insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (!users.count(followerId) || followeeId == followerId)
            return;

        users[followerId]->following.erase(followeeId);
    }
};
