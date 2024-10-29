class Solution {
public:
    long long dp[101][101][2]; // ith column, jth row filling (0 for not fill 1 for fill with black)
    long long g[100][100], n;

    long long rec(int col, int fill, int curr){
        if(col == n-1){
            if(curr == 1) return 0;

            long long tot = fill? g[col][fill-1]: 0;
            return tot;
        }
        if(dp[col][fill][curr]!=-1){
            return dp[col][fill][curr];
        }
        long long ans = rec(col+1, n, 0);

        if(curr == 0){
            for(int take = 1; take<=n; take++){
                if(take<=fill){
                    long long tot = g[col][fill-1];
                    long long untake = fill-take;
                    if(untake)
                        tot -= g[col][untake-1];
                    long long val = tot + rec(col+1, untake, 0);
                    ans = max(ans, val);
                    
                }
                else{
                    long long val = g[col][take-1]+ rec(col+1, take, 1);
                    ans = max(ans, val);
                }
                
            }
        }
        else{
            for( int take = 1 ; fill + take <= n ; take++ ){
                long long d = fill + take;
                long long tot = g[col][d-1] ;
                if( fill )
                tot -= g[col][fill-1] ;
                long long val = tot + rec(col+1,d,1);
                ans = max(ans,val);
            } 
        }
        return dp[col][fill][curr] = ans;
    }
    long long maximumScore(vector<vector<int>>& grid) {
        n = grid.size();
        memset(dp, -1, sizeof(dp));
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) g[j][i] = grid[i][j] + ( i ? g[j][i-1] : 0 );
        }
        return rec(0,0,1);
    }
};
// https://leetcode.com/problems/maximum-score-from-grid-operations/description/
// You are given a 2D matrix grid of size n x n. Initially, all cells of the grid are colored white. In one operation, you can select any cell of indices (i, j), and color black all the cells of the jth column starting from the top row down to the ith row.

// The grid score is the sum of all grid[i][j] such that cell (i, j) is white and it has a horizontally adjacent black cell.

// Return the maximum score that can be achieved after some number of operations.