120. Triangle
//QUESTION LINK: https://leetcode.com/problems/triangle/?envType=daily-question&envId=2025-09-25

TOPIC: Array
Dynamic Programming


CODE:
////////////// buute force ///////////////////

// TC: O(n.n)
// SC: O(1) 

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        for(int row = n-2; row>=0; row--){
            for(int col=0; col<triangle[row].size(); col++){
                triangle[row][col] += min(triangle[row+1][col], triangle[row+1][col+1]);
            }
        }
        return triangle[0][0];
    }
};

///////////////////    using Dp  ///////////////////////

// TC: O(n.n)
// SC: O(n.n)
class Solution {
public:

    int dfs(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>& dp){
                // Base case: if we reach last row
        if (i == triangle.size() - 1) {
            return triangle[i][j];
        }

        if(dp[i][j]!= INT_MAX) return dp[i][j];
                // Recursive: go down-left and down-right
        int down = dfs(i + 1, j, triangle, dp);
        int downRight = dfs(i + 1, j + 1, triangle, dp);

        // Store min path sum
        dp[i][j] = triangle[i][j] + min(down, downRight);
        return dp[i][j];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp (n, vector<int>(n, INT_MAX));
        return dfs(0, 0, triangle, dp);

    }
};
