class Solution
{
public:
    int climbStairs(int n)
    {
        if (n <= 2)
            return n;

        int prev1 = 1; // n-2
        int prev2 = 2; // n-1
        int current = 0;

        for (int i = 3; i <= n; ++i)
        {
            current = prev1 + prev2;
            prev1 = prev2;
            prev2 = current;
        }

        return current;
    }
};
