#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
#include <bitset>
using namespace std;
using namespace __gnu_pbds;
#define ss second
#define ff first
#define pb push_back
#define pf push_front
#define rep(i, a, b, c) for (ll i = a; i < (b); i += c)
#define all(x) begin(x), end(x)
typedef long long ll;
#define pii pair<ll, ll>
#define vi vector<ll>
#define fill(v) for(auto& i: v) cin>>i;
#define has(c, x) {return c.find(x)!=c.end();}
#define pr(v) for(auto i: v) cout<<i<<" "; cout<<endl;
#define pr1(v, i) for(auto j: v) cout<<j[i]<<" "; cout<<endl; 
#define del(s, x) if(s.find(x)!=s.end()) s.erase(s.find(x)) 
#define show(x) cout<<#x<<": "<<x<<" ";
#define rev(v) reverse(v.begin(), v.end())
#define endl() cout << endl
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define testcase_(i, val) cout<<"Case #"<<i<< ": "<< val<<endl;
#define mod_10 1000000007
#define mod_9 998244353
#define lmt 1000000000000000000
#define __builtin_popcount(x) count_ones(x)
#define Yes() cout << "YES\n"
#define No() cout << "NO\n"
#define  MAXN 300005
#define N_LMT 200200
#define endl "\n"

void debug(vi v){

    for(auto it: v){
        cerr<<it<<" ";
    }
    cerr<<endl;
}

ll gcd(ll a, ll b){ if(b==0) return a; else return gcd(b,a%b); }

int mex(vector<ll>& numberArray) {  // munda mex
    set<ll> sett;
    for(int i = 0; i < numberArray.size(); i++) 
        sett.insert(numberArray[i]);
    for(int i = 0; i < 1000001; i++)
        if(!sett.count(i)) return i;
    return -1;
}

ll binpow(ll a, ll b, ll m ) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res%m;
}
ll fac[2001];

ll inv(ll a){ return binpow(a,mod_10-2,mod_10); }
 
ll ncr(ll n, ll r){
    if(n<r || r<0){
        return 0;
    }
    if(r==0){
        return 1;
    }
    ll ans = 1;
    ans = (ans*fac[n])%mod_10;
    ans = (ans*inv(fac[r]))%mod_10;
    ans = (ans*inv(fac[n - r]))%mod_10;
    return ans%mod_10;
} 

void solve() {
    string s;
    cin>>s;

    ll ans = 0;
    ll n = s.size();
    ll m = n;
    for(int i=0; i<n;i++){
        if(s[i] == '0'){
            continue;
        }
        else{
            // cout<<m-1<<endl;
            ans += fac[i];
            ans = ans%mod_10;
        }
    }
    // ans -=1;
    cout<<ans<<endl;
    for(int i=1; i<=10; i++){
        cout<<fac[i]<<" "<<i<<endl;
    }
    cout<<endl;
}

signed main() {
    auto begin = std::chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // freopen("in",  "r", stdin);
    // freopen("out", "w", stdout);
    fac[1] = 0;
    for(int i=2; i<=2000; i++){
        fac[i] = (fac[i-1] + binpow(2, i-2, mod_10))%mod_10;
    }
    
    cin >> t;
    for(int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }
    // auto end = std::chrono::high_resolution_clock::now();
    // auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    // cerr << "Time measured: " << elapsed.count() * 1e-9 << " seconds.\n"; 
    return 0;
}