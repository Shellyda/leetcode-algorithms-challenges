#include <unordered_map>
#include <vector>
#include <utility>
#include <string>

using namespace std;

class TimeMap
{
private:
    unordered_map<string, vector<pair<int, string>>> keyStore;

public:
    TimeMap() {}

    void set(string key, string value, int timestamp)
    {
        keyStore[key].emplace_back(timestamp, value);
    }

    string get(string key, int timestamp)
    {
        auto &timeline = keyStore[key];
        int left = 0, right = timeline.size() - 1;
        string result = "";

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (timeline[mid].first <= timestamp)
            {
                result = timeline[mid].second;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return result;
    }
};