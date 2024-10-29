class Solution {
public:
    vector<int> maximumSubarrayXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for(int i=0; i<=n; i++){
            for(int j=0; j+i<n; j++){
                if(i==0){
                    dp[j][i] = nums[j];
                    continue;
                }
                dp[j][i] = dp[j][i-1]^dp[j+1][i-1];
            }
        }
        for(int len = 1; len<=n; len++){
            for(int r = 0; r+len<n; r++){
                dp[r][len] = max(dp[r][len], max(dp[r][len-1], dp[r+1][len-1]));
            }
        }
        vector<int> ans;
        for(auto it: queries){
            int l = it[0], r = it[1];
            ans.push_back(dp[l][r-l]);
        }
        return ans;
    }
};