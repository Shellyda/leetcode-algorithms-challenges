# Design browser history

- 🧩 Problem link: [Leetcode](https://leetcode.com/problems/design-browser-history/)
- 🚦 Difficulty: 🟡 Medium

## Purpose

You have a browser of one tab where you start on the `homepage` and you can visit another `url`, get back in the history number of `steps` or move forward in the history number of `steps`.

## ✅ Solution

```cpp
class BrowserHistory
{
private:
    list<string> history; // doubly linked list in c++
    std::list<std::string>::iterator currentPage;

public:
    BrowserHistory(string homepage)
    {
        history.push_back(homepage);
        currentPage = prev(history.end());
    }

    void visit(string url)
    {
        history.erase(next(currentPage), history.end());
        history.push_back(url);
        currentPage = prev(history.end());
    }

    string back(int steps)
    {
        while (steps-- > 0 && currentPage != history.begin())
        {
            --currentPage; // points to prev element
            // pre increment -> --Before, excludes the need for a var to store value after change!
        }
        return *currentPage;
    }

    string forward(int steps)
    {
        while (steps-- > 0 && next(currentPage) != history.end())
        {
            ++currentPage; // points to next element
        }
        return *currentPage;
    }
};
```
