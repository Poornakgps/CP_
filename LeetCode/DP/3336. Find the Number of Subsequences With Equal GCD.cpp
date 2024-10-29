class Solution {
public:
    int n, mod = 1e9+7;
    int dp[205][205][205]; // till index i number of sequences having j gcd first sequence k gcd for second sequence 
    int a[205];
    int rec(int i, int first, int second){
        if(i == n){
            return (first && second) && (first == second);
        }
        if(dp[i][first][second] !=-1) return dp[i][first][second];

        int skip = rec(i+1, first, second);

        int take1 = rec(i+1, gcd(first, a[i]), second);
        int take2 = rec(i+1, first, gcd(second, a[i]));

        return dp[i][first][second] = (0ll +skip + take1 + take2)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        n = nums.size();
        for(int i=0; i<n; i++){
            a[i] = nums[i];
        }
        memset(dp, -1, sizeof(dp));
        return rec(0, 0, 0);
    }
};