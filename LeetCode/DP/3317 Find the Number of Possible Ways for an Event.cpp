// https://leetcode.com/problems/find-the-number-of-possible-ways-for-an-event/
using ll = long long;
int mod_10 = 1e9 + 7;
class Solution {
public:
    ll mod = 1e9 + 7;
    ll y, x, n;
    ll dp[1005][1005];

    ll rec(ll i, ll j){  // till i members placed in j number of bands there

        if(j>x){
            if(i==n)return 1;
            else return 0;
        }
        if(i==n){
            // cout<<y<<" "<<ncr(x, j)<<endl;
            return 1;
        }

        if(dp[i][j] != -1) return dp[i][j];

        int ans = (((y*(x-j))%mod)*(rec(i+1, j+1))%mod)%mod;
        if(j!=0)
            ans = (ans + (j*rec(i+1, j))%mod)%mod;

        return dp[i][j] =ans;
    }

    int numberOfWays(int nn, int xx, int yy) {
        memset(dp, -1, sizeof(dp));
        fac[0] = 1;
        for (ll i = 1; i <= 1000; ++i) {
            fac[i] = (fac[i - 1] * i) % mod_10;
        }
        y = yy;
        x = xx;
        n = nn;
        return rec(0, 0);
    }
};