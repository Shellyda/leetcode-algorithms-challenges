# Design Twitter

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/design-twitter/)
- 🚦 Difficulty: 🟡 Medium

## 💡 Approach

- **Design:**
  Each user stores:

  - A list of their own tweets as `(timestamp, tweetId)`
  - A set of user IDs they follow (including themselves by default)

- **Tweet Posting: O(1)**

  - Each new tweet is stored in the user's tweet list with a global timestamp.

- **Feed Generation (`getNewsFeed`): O(N log K)**

  - Collect the last few tweets (up to 10) from the user and their followees.
  - Push all into a max-heap (priority queue) ordered by timestamp.
  - Extract the top 10 most recent tweet IDs.

- **Follow/Unfollow: O(1)**

  - Simply add or remove user IDs from the `following` set.
  - No need to modify or store a feed.

## 🕒 Time and Space Complexity

- Time: O(N log K)
- Space: O(N)

> where `N = total tweets` considered (`user + followees`), `K = 10`

## ✅ Solution

```cpp
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
```
