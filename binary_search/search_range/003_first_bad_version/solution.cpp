// The API isBadVersion is defined for you.
bool isBadVersion(int version); // Function prototype

class Solution
{
public:
    int firstBadVersion(int n)
    {
        return binSearch(1, n);
    }

    int binSearch(int l, int r)
    {
        while (l < r)
        {
            int m = l + (r - l) / 2;

            if (isBadVersion(m))
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }

        return r;
    }
};