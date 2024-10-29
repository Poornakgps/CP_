class Solution {
public:
    long long maximumValueSum(vector<vector<int>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<long long>> top_3;

        // Collect the top 3 values from each row with their positions
        for (int i = 0; i < n; i++) {
            priority_queue<pair<int, pair<int, int>>> pq;
            for (int j = 0; j < m; j++) {
                pq.push({board[i][j], {i, j}});
            }
            for (int k = 0; k < 3 && !pq.empty(); k++) {
                auto top = pq.top();
                pq.pop();
                top_3.push_back({top.first, top.second.first, top.second.second});
            }
        }

        // Sort top_3 by value in descending order
        sort(top_3.rbegin(), top_3.rend());

        long long ans =-3e9;
        long long s = top_3.size();
        long long limit = min(503LL, s);

        // Check for the maximum sum of values from unique rows and columns
        for (long long i = 0; i < limit; i++) {
            for (long long j = i + 1; j < limit; j++) {
                if (top_3[i][1] == top_3[j][1] || top_3[i][2] == top_3[j][2]) {
                    continue; // Skip if they share the same row or column
                }
                for (long long k = j + 1; k < limit; k++) {
                    if (top_3[k][1] != top_3[i][1] && top_3[k][2] != top_3[i][2] &&
                        top_3[k][1] != top_3[j][1] && top_3[k][2] != top_3[j][2]) {
                        ans = max(ans, top_3[i][0] + top_3[j][0] + top_3[k][0]);
                    }
                }
            }
        }

        return ans;
    }
};
