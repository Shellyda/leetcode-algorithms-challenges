#include <unordered_map>
#include <list>
using namespace std;

class LRUCache
{
private:
    int capacity;
    list<int> order;
    unordered_map<int, pair<int, list<int>::iterator>> cache;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (cache.find(key) == cache.end())
            return -1;

        order.erase(cache[key].second);
        order.push_front(key);
        cache[key].second = order.begin();
        return cache[key].first;
    }

    void put(int key, int value)
    {
        if (cache.find(key) != cache.end())
        {
            order.erase(cache[key].second);
        }
        else if (cache.size() == capacity)
        {
            int lru = order.back();
            order.pop_back();
            cache.erase(lru);
        }

        order.push_front(key);
        cache[key] = {value, order.begin()};
    }
};
