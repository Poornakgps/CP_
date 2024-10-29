class Solution {
public:
    int maxScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int mxn = m*n;
        vector<pair<int, int>> grid_1d(mxn);

        // converting into 1d grid storing the row and value
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                grid_1d[i*m + j] = {grid[i][j], i};
            }
        }
        int mx_ = (1<<n);
        vector<int> dp(mx_, 0);

        sort(grid_1d.rbegin(), grid_1d.rend()); 

        int l = 0, r = 0;
        while(l<mxn){
            while(r<mxn && grid_1d[l].first == grid_1d[r].first) r++;
            auto new_dp = dp;
            for(int mask = 0; mask<mx_; mask++){
                for(int i=l; i<r; i++){
                    auto [val, row_id] = grid_1d[i];

                    if((mask>>row_id) & 1) continue; 
                    new_dp[mask | (1<<row_id)] = max(new_dp[mask|(1<<row_id)], dp[mask] + val);
                }
            }
            dp = new_dp;
            l=r;
        }

        return *max_element(dp.begin(), dp.end());
    }
};
// reference: https://leetcode.com/problems/select-cells-in-grid-with-maximum-score/solutions/5732159/c-dp-optimized-with-bitmask/