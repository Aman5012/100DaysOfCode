1039. Minimum Score Triangulation of Polygon
//QUESTION LINK: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/?envType=daily-question&envId=2025-09-29

TOPIC: Array
Dynamic Programming


CODE:
// Time Complexity: O(n³)
// Space Complexity: O(n²)

class Solution {
public:

    int solve(int i, int j, vector<vector<int>>& dp, vector<int> & values){
        if(j-i<2) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;

///////////////////////  matrix chain multiplication formate   /////////////
        for(int k=i+1; k<j; k++){
            int val = values[i]* values[j]*values[k]
                        + solve(i, k, dp, values)
                        + solve(k, j, dp, values);
            ans = min(ans, val);
        }
        return dp[i][j] = ans;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();

        vector<vector<int>> dp (n, vector<int>(n, -1));
        return solve(0, n-1, dp, values);
    }
};
