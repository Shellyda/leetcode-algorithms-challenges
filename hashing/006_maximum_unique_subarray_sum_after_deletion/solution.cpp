class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> set;

        int sum = 0, negative = INT_MIN;

        for (int n : nums) {
            if (!set.count(n)) {
                set.insert(n);
                if (n <= 0) {
                    negative = max(negative, n);
                } else {
                    sum += n;
                }
            }
        }

        return negative != INT_MIN && sum == 0 ? negative : sum;
    }
};