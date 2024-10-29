class Solution {
public:
    vector<vector<vector<int>>> func(int n, int k, vector<int>& nums){
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k+1, vector<int>(128, 0)));
        dp[0][0][0] = 1;
        for(int i=0; i<n; i++)
            dp[i][0][0] = 1;
        dp[0][1][nums[0]] = 1;

        for(int i=1; i<n; i++){
            for(int j=1; j<=k; j++){
                for(int val = 0; val<128; val++){
                    dp[i][j][val] |= dp[i-1][j][val];
                    dp[i][j][nums[i] | val] |= dp[i-1][j-1][val];
                }
            }
        }
        return dp;        
    }
    int maxValue(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<int>>> left = func(n, k, nums);
        reverse(begin(nums), end(nums));
        vector<vector<vector<int>>> right = func(n, k, nums);
        int res = 0;

        for(int i=k-1; i+k<n; i++){
            for(int a=0; a<128; a++){
                for(int b=0; b<128; b++){
                    if (left[i][k][a] && right[n-i-2][k][b]) {
                        res = max(res, a ^ b);
                    }
                }
            }
        }
        return res;
    }
};
// https://leetcode.com/problems/find-the-maximum-sequence-value-of-array/