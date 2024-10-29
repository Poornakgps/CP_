class Solution {
public:
    const int mod = 1e9 + 7;

    int countOfPairs(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<vector<int>> dp(nums.size(), vector<int>(mx+1, 0));
        int n = nums.size();

        // Initialize the base case for the first element
        for (int i = 0; i <= nums[0]; i++) {
            dp[0][i] = 1;
        }

        // Calculate dp table for each position
        for (int i = 1; i < n; i++) {
            int ways = 0;
            int prev = 0;
            for (int cur = 0; cur <= nums[i]; cur++) {
                if (prev <= min(cur, cur - nums[i] + nums[i - 1])) {
                    ways = (ways + dp[i - 1][prev]) % mod;
                    prev++;
                }
                dp[i][cur] = ways;
            }
        }

        int ans = 0;
        for (int i = 0; i <= nums[n - 1]; i++) {
            ans = (ans + dp[n - 1][i]) % mod;
        }

        return ans;
    }
};
