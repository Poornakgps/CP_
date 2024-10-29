class Solution {
public:
    int a[100001], b[100001];
    int n;

    long long rec(int i, long long canAdd) {
        // Base case: If we reach the end of the array
        if (i == n) return 0;

        // Current difference
        long long curr = b[i] - a[i];

        // Recursive cases based on previous difference (canAdd) and current difference (curr)
        if (canAdd == 0 || curr == 0) {
            // If there was no previous addition/subtraction or current difference is zero
            return abs(curr) + rec(i + 1, curr);
        } else if (canAdd > 0) {
            // If previous adjustment was positive
            if (curr > 0) {
                // Both current and previous differences are positive
                return max(curr - canAdd, 0LL) + rec(i + 1, curr);
            } else {
                // Current difference is negative
                return abs(curr) + rec(i + 1, curr);
            }
        } else {
            // If previous adjustment was negative
            if (curr < 0) {
                // Both current and previous differences are negative
                return max(canAdd - curr, 0LL) + rec(i + 1, curr);
            } else {
                // Current difference is positive
                return curr + rec(i + 1, curr);
            }
        }
        return 0;
    }

    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        n = nums.size();
        for (int i = 0; i < n; i++) {
            a[i] = nums[i];
            b[i] = target[i];
        }
        return rec(0, 0);
    }
};