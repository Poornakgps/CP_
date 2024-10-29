class Solution {
public:
    int dp[2001][51][51];
    int n;
    int arr[2001];
    const int mod = 1e9 + 7;

    int rec(int i, int a, int b){
        if(i==n)
            return 1;
        
        if(dp[i][a][b] != -1) return dp[i][a][b];
        int ans = 0;
        for(int j = a; j<=arr[i]; j++){
            int y = arr[i] - j;
            if(b>=y){
                ans += rec(i+1, j, arr[i]-j);
                ans = ans%mod;
            }
        }
        return dp[i][a][b] = ans;
    }
    int countOfPairs(vector<int>& nums) {
        int ans = 0;
        n = nums.size();
        for(int i=0; i<n; i++){
            arr[i] = nums[i];
        }
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<=nums[0]; i++){
            ans += rec(1, i, nums[0]-i);
            ans = ans%mod;
        }    
        return ans;   
    }
};