#include<bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define ll long long
#define ss second
#define ff first
#define pb push_back


vector<int> z_function(string s){
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;

    for(int i=1; i<n; i++){
        if(i<r){
            z[i] = min(r-i, z[i-l]);
        }
        while(i+z[i]<n && s[z[i]] == s[i + z[i]]){
            z[i]++;
        }
        if(i+z[i]>r){
            l = i;
            r=i+z[i];
        }
    }
    return z;
}

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<ll, ll> dp; 

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        map<ll, ll> new_dp; 
        for (auto& [c_val, ways] : dp) {
            new_dp[c_val + a[i]] = (new_dp[c_val + a[i]] + ways) % MOD;

            new_dp[abs(c_val + a[i])] = (new_dp[abs(c_val + a[i])] + ways) % MOD;
        }
        dp = new_dp; 
    }
    ll max_c = 0;
    ll ways_to_achieve_max_c = 0;

    for (auto& [c_val, ways] : dp) {
        if (c_val > max_c) {
            max_c = c_val;
            ways_to_achieve_max_c = ways;
        } else if (c_val == max_c) {
            ways_to_achieve_max_c = (ways_to_achieve_max_c + ways) % MOD;
        }
    }

    // Output the results
    cout << ways_to_achieve_max_c << endl;
} 
 
int main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
  //  cin >> t;
    for(int i = 1; i <= t; i++) 
    {
        //cout << "Case #" << i << ": ";
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}