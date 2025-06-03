#include <iostream>
#include <list>
using namespace std;

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

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */