#include<bits/stdc++.h>
using namespace std;
mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());

#define ll long long
#define ss second
#define ff first
#define pb push_back

const int MOD = 998244353;

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


ll p[200200];

void solve() {
    int n;
    cin >> n;

    vector<ll> a(n + 1);
    ll mn = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mn = min(mn, sum);
    }
    // use 2 only once
    if(mn==0){
        cout<<p[n]<<endl;
        return;
    }
    sum = 0;
    ll ans = 0, freq = 0; 
    for(int i=0; i<n; i++){
        sum += a[i];

        if(sum == mn){
            ans = (ans + p[n-i+freq-1])%MOD;
        }
        if(sum>=0) freq++;
    }

    cout<<ans<<endl;
} 
 
signed main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    
    cin >> t;
    p[0] = 1;

    for(int i=1; i<200200; i++){
        p[i] = (p[i-1]*2)%MOD;
    }
    for(int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}