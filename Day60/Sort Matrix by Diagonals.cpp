446. Sort Matrix by Diagonals
//QUESTION LINK: https://leetcode.com/problems/sort-matrix-by-diagonals/?envType=daily-question&envId=2025-08-28

TOPIC: Array
Sorting
Matrix


CODE:

// Time Complexity: O(n² log n)
// Space Complexity: O(n)
class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        // Bottom-left diagonals (including main diagonal) -> non-increasing (descending)
        for (int startRow = 0; startRow < n; startRow++) {
            vector<int> temp;
            int r = startRow, c = 0;
            while (r < n && c < n) {
                temp.push_back(grid[r][c]);
                r++; c++;
            }

            sort(temp.rbegin(), temp.rend());  // descending

            r = startRow, c = 0;
            int idx = 0;
            while (r < n && c < n) {
                grid[r][c] = temp[idx++];
                r++; c++;
            }
        }

        // Top-right diagonals (excluding main diagonal) -> non-decreasing (ascending)
        for (int startCol = 1; startCol < n; startCol++) {
            vector<int> temp;
            int r = 0, c = startCol;
            while (r < n && c < n) {
                temp.push_back(grid[r][c]);
                r++; c++;
            }

            sort(temp.begin(), temp.end());  // ascending

            r = 0, c = startCol;
            int idx = 0;
            while (r < n && c < n) {
                grid[r][c] = temp[idx++];
                r++; c++;
            }
        }

        return grid;
    }
};

