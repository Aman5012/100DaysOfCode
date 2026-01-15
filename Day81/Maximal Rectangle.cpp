85. Maximal Rectangle
//QUESTION LINK: https://leetcode.com/problems/maximal-rectangle/?envType=daily-question&envId=2026-01-11

TOPIC: Array
Dynamic Programming
Stack
Matrix


CODE:
// TC: O(n.n)
// SC: O(n.n)

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<int>> dp(row, vector<int>(col, 0));

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if (matrix[i][j] == '1') {
                    // If it's the first row, height is 1, else add to the height above
                    // dp[i][j] = (i == 0) ? 1 : dp[i-1][j] + 1;
                    if(i==0) dp[i][j]= 1;
                    else {
                        dp[i][j]= dp[i-1][j]+1;
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        int maxiA = 0;

        for(int i = row - 1; i >= 0; i--) {
            for(int j = col - 1; j >= 0; j--) {
                if (dp[i][j] == 0) continue;

                int minHeight = dp[i][j];
                // Traverse backwards from current column to find max area in corrent row's 
                for (int k = j; k >= 0; k--) {
                    if (dp[i][k] == 0) break; //stop if height is 0

                    minHeight = min(minHeight, dp[i][k]);
                    
                    // Width is the distance between column j and column k
                    int width = j - k + 1;
                    int area = minHeight * width;
                    
                    maxiA = max(maxiA, area);
                }
            }
        }
        return maxiA;
    }
};
