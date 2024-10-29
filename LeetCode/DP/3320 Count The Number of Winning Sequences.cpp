// https://leetcode.com/problems/count-the-number-of-winning-sequences/
class Solution {
public:

    int dp[1005][2005][4];
    string s;
    int mod = 1e9 + 7;
    int shift = 1000;
    int rec(int i, int score_bob, int prev){
        // cout<<score_bob<<" "<<i<<" "<<prev<<endl;
        int shifted_score = shift + score_bob;
        if(i == s.size()){
            return score_bob>0;
        }

        if(dp[i][shifted_score][prev]!=-1) return dp[i][shifted_score][prev];

        int ans = 0;
        if(prev != 1){ // fire
            if(s[i] == 'E'){
                ans = (ans + rec(i+1, score_bob + 1, 1))%mod ;
            }
            else if(s[i] == 'W'){
                ans = (ans + rec(i+1 , score_bob - 1, 1))%mod;
            }
            else{
                ans = (ans + rec(i+1 , score_bob, 1))%mod;
            }
        }

        if(prev != 2){ // rock
            if(s[i] == 'W'){
                ans = (ans + rec(i + 1, score_bob + 1, 2))%mod ;
            }
            else if(s[i] == 'F'){
                ans = (ans + rec(i + 1, score_bob - 1, 2))%mod ;
            }
            else{
                ans = (ans + rec(i + 1, score_bob, 2))%mod;
            }
            
        }

        if(prev != 3){ // water
            if(s[i] == 'F'){
                ans = (ans + rec(i + 1, score_bob + 1 , 3))%mod ;
            }
            else if(s[i] == 'E'){
                ans = (ans+ rec(i+1, score_bob - 1, 3))%mod;
            }
            else{
                ans = (ans+ rec(i+1, score_bob, 3))%mod;
            }
            
        } 

        return dp[i][shifted_score][prev] = ans;
    }
    int countWinningSequences(string st) {
        
        memset(dp, -1, sizeof(dp));
        s = st;
        return rec(0, 0, 0);
    }
};