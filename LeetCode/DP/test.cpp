#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<int> a(n); for(auto &i: a) cin>>i;
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        sort(a.begin(), a.end());
        int ans = 0;
        if(n&1){
            map<int, int> mp;
            for(int i=1; i<n; i++){
                mp[a[i]-a[i-1]]++;
            }    
            auto it = mp.end();
            it--;
            if(it->second>1){
                ans = it->first;
            }
            else{
                mp[it->first]--;
                mp[it->first/2]++;
                mp[it->first/2 + (it->first&1)]++;
                it = mp.end();
                it--;
                ans = it->first;
            }
        }
        else{
            for(int i=1; i<n; i+=2){
                ans = max(ans, a[i]-a[i-1]);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}