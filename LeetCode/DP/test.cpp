#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;
int maxScore = 0;

bool is_valid_placement(vector<vector<int>>& grid, int x, int y, int length, bool is_horizontal) {
    // Check horizontal placement
    if (is_horizontal) {
        if (y + length > N) return false;
        for (int i = 0; i < length; i++)
            if (grid[x][y + i] != 0) return false;
    } 
    // Check vertical placement
    else {
        if (x + length > M) return false;
        for (int i = 0; i < length; i++)
            if (grid[x + i][y] != 0) return false;
    }
    return true;
}

void place_block(vector<vector<int>>& grid, int x, int y, int length, bool is_horizontal, int value) {
    // Place or remove a block based on value (1 to place, 0 to remove)
    if (is_horizontal) {
        for (int i = 0; i < length; i++) grid[x][y + i] = value;
    } else {
        for (int i = 0; i < length; i++) grid[x + i][y] = value;
    }
}

int clear_full_rows(vector<vector<int>>& grid) {
    int score = 0;
    for (int i = 0; i < M; i++) {
        if (all_of(grid[i].begin(), grid[i].end(), [](int cell) { return cell == 1; })) {
            fill(grid[i].begin(), grid[i].end(), 0);
            score += 10;
        }
    }
    return score;
}

void backtrack(vector<vector<int>>& grid, vector<vector<int>>& blocks, int blockIdx, int currentScore) {
    if (blockIdx >= blocks.size()) {
        maxScore = max(maxScore, currentScore);
        return;
    }
    
    // Try placing each block in the block set
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            for (int orientation = 0; orientation < 2; orientation++) {
                bool is_horizontal = (orientation == 0);
                
                // Try placing the block if valid
                if (is_valid_placement(grid, i, j, blocks[blockIdx][0], is_horizontal)) {
                    place_block(grid, i, j, blocks[blockIdx][0], is_horizontal, 1);
                    
                    int gainedScore = clear_full_rows(grid);
                    backtrack(grid, blocks, blockIdx + 1, currentScore + gainedScore);
                    
                    // Undo the placement
                    place_block(grid, i, j, blocks[blockIdx][0], is_horizontal, 0);
                }
            }
        }
    }
}

int main() {
    cin >> M >> N;
    int num;
    cin >> num;

    vector<vector<int>> blocks(num, vector<int>(3));
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> blocks[i][j];
        }
    }

    vector<vector<int>> grid(M, vector<int>(N, 0));
    backtrack(grid, blocks, 0, 0);
    
    cout << maxScore << endl;
    return 0;
}