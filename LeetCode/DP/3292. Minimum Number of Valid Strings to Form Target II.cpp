// https://leetcode.com/problems/minimum-number-of-valid-strings-to-form-target-ii/
#define ll long long
class Solution {
public:
    vector<int>z_fun(string &w,string &s){
        string t=w+"?"+s;
        int n=t.size();
        vector<int>z(n,0);
        int l=0,r=0;
        for(int i=1;i<n;i++){
            if(i<r) z[i]=min(r-i,z[i-l]);
            while(i+z[i]<n && t[i+z[i]]==t[z[i]]) z[i]++;
            if(i+z[i]>r){
                r=i+z[i];
                l=i;
            }
        }
        vector<int>ans;
        for(int i=w.size()+1;i<n;i++){
            ans.push_back(z[i]);
        }
        return ans;
    }
    int minValidStrings(vector<string>& a, string s) {
        int n=s.size();
        vector<int>mx(n,-1);
        for(int i=0;i<a.size();i++){
            vector<int>temp=z_fun(a[i],s);
            for(int j=0;j<s.size();j++) mx[j]=max(mx[j],temp[j]);
        }
        priority_queue<pair<int,int> >pq;// index and right boundary
        set<int>st;
        vector<int>dp(n,1e9);
        for(int i=0;i<n;i++){
            pq.push({-(mx[i]+i-1),i});
            st.insert(i);
            while(!pq.empty() && -pq.top().first<i){
                st.erase(pq.top().second);
                pq.pop();
            }
            if(pq.empty()) return -1;
            int ind=*st.begin();
            // cout<<mx[i]<<" ";
            if(ind==0){
                dp[i]=1;
            }else dp[i]=dp[ind-1]+1;
        }
        return dp[n-1];
    }
};