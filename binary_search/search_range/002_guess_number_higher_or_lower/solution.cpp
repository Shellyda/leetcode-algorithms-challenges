/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

bool guess(int num);
class Solution
{
public:
    int guessNumber(int n)
    {
        int l = 1, r = n;

        while (l <= r)
        {
            int m = l + ((r - l) / 2);

            if (guess(m) < 0)
            {
                r = m - 1;
            }
            else if (guess(m) > 0)
            {
                l = m + 1;
            }
            else
            {
                return m;
            }
        }

        return -1;
    }
};