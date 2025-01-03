#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

/***************************************C-H-A-O-S**************************************/


int n;
vector<int> t[4*MAXN];


void build(int a[], int v, int tl, int tr) {  // O(n log n)
    if (tl == tr) {
        t[v] = vector<int>(1, a[tl]);
    } else { 
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),
              back_inserter(t[v]));
    }
}

void update(int v, int tl, int tr, int pos, int new_val) {  // O(log^2 n)
    t[v].erase(t[v].find(a[pos]));
    t[v].insert(new_val);
    if (tl != tr) {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
    } else {
        a[pos] = new_val;
    }
}

int query(int v, int tl, int tr, int l, int r, int x) { // O(log^2 n)
    if (l > r)
        return INF;
    if (l == tl && r == tr) {
        vector<int>::iterator pos = lower_bound(t[v].begin(), t[v].end(), x);
        if (pos != t[v].end())
            return *pos;
        return INF;
    }
    int tm = (tl + tr) / 2;
    return min(query(v*2, tl, tm, l, min(r, tm), x), 
               query(v*2+1, tm+1, tr, max(l, tm+1), r, x));
}

void solve() {

  int q;
  cin>>n>>q;
  
  int arr[n];

  rep(i,0,n,1) cin>>arr[i];

  build(arr, 1, 0, n-1);

  while(q--){
    ll a, b, c;
    cin>>a>>b>>c;
    if(a == 1){
      update(1, 0, n-1, b-1, c);
    }
    else{
      cout<<range_gcd(1, 0, n-1, b-1, c-1)<<endl;
    }
  }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}