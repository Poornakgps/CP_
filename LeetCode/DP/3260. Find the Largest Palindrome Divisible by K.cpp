class Solution {
public:
    int n, k, req;
    bool od = false;
    int pref[100001], res[100001];
    int dp[100001][10];
    
    int rec(int i, int mod){

        if(i == req){
            return mod == 0;
        }

        if(dp[i][mod] != -1) return dp[i][mod];
        
        if(od == true && i == req - 1){
            for(int d=9; d>=0; d--){
                int currmod = 0;
                currmod = (mod + (pref[i]*d)%k)%k;
                int poss = rec(i+1, currmod);
                if(poss){
                    res[i] = d;
                    res[n-i-1] = d;
                    break;
                }
            }
        }
        else{
            for(int d=9; d>=0; d--){
                int currmod = 0;
                currmod = (mod + (pref[i]*d)%k + (pref[n-i-1]*d)%k)%k;
                int poss = rec(i+1, currmod);
                if(poss){
                    res[i] = d;
                    res[n-i-1] = d;
                    break;
                }
            }
        }
        if(res[i] == -1){
            return dp[i][mod] = 0;
        }
        return dp[i][mod] = 1;
    }
    string largestPalindrome(int nn, int kk) {
        n = nn, k = kk;
        req = n/2;
        od = false;
        memset(res, -1, sizeof(res));
        memset(dp, -1, sizeof(dp));
        if(n&1) od = true, req++;
        pref[0] = 1;
        for(int i=1; i<n; i++){
            pref[i] = (pref[i-1]*10)%k;
        }
        string ans(n, '0');
        int possible = rec(0, 0);

        for(int i=0; i<n; i++){
            ans[i] = ans[i] + res[i];
        }
        return ans;
    }
};