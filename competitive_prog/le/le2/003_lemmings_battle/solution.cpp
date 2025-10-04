#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n--)
    {
        priority_queue<int> sgArmy, sbArmy; // maxHeap

        int b, sg, sb;
        cin >> b >> sg >> sb;

        while (sg--)
        {
            int power;
            cin >> power;
            sgArmy.push(power);
        }

        while (sb--)
        {
            int power;
            cin >> power;
            sbArmy.push(power);
        }

        while (!sgArmy.empty() && !sbArmy.empty())
        {
            vector<int> resultSg, resultSb;

            for (int i = 0; i < b && !sgArmy.empty() && !sbArmy.empty(); i++)
            {
                int bestGreen = sgArmy.top();
                sgArmy.pop();
                int bestBlue = sbArmy.top();
                sbArmy.pop();

                if (bestGreen > bestBlue)
                    resultSg.push_back(bestGreen - bestBlue);
                else if (bestBlue > bestGreen)
                    resultSb.push_back(bestBlue - bestGreen);
            }

            for (int g : resultSg)
                sgArmy.push(g);
            for (int b : resultSb)
                sbArmy.push(b);
        }

        if (sgArmy.empty() && sbArmy.empty())
        {
            cout << "green and blue died" << endl;
        }
        else if (!sgArmy.empty())
        {
            cout << "green wins" << endl;
            while (!sgArmy.empty())
            {
                cout << sgArmy.top() << endl;
                sgArmy.pop();
            }
        }
        else
        {
            cout << "blue wins" << endl;
            while (!sbArmy.empty())
            {
                cout << sbArmy.top() << endl;
                sbArmy.pop();
            }
        }

        if (n)
            cout << endl;
    }

    return 0;
}
