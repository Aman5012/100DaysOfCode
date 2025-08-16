Palindromic Partitioning

//QUESTION LNK: https://www.geeksforgeeks.org/problems/palindromic-patitioning4845/1

TOPIC: Dynamic Programming


CODE:
/////////////////////  approach 1  ////////////////////////
// tC: O(n²)  
// SC: O(n²)  
class Solution {
  public:
    int palPartition(string &s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        vector<int> dp(n, INT_MAX);

        // Step 1: Precompute palindrome table
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len <= 2) isPal[i][j] = true;
                    else isPal[i][j] = isPal[i+1][j-1];
                }
            }
        }

        // Step 2: Fill dp[]
        for (int i = 0; i < n; i++) {
            if (isPal[0][i]) {
                dp[i] = 0; // whole substring is palindrome
            } else {
                for (int j = 0; j < i; j++) {
                    if (isPal[j+1][i]) {
                        dp[i] = min(dp[i], dp[j] + 1);
                    }
                }
            }
        }

        return dp[n-1];
    }
};

////////////////////////////////////////  appraoch 2  //////////////////////////////////
// TC: O(n³)
// SC: O(n²)  

class Solution {
  public:
  
    int solve(string &s, int i, int j, vector<vector<int>>& dp, vector<vector<bool>>& isPal) {
        if (i >= j) return 0;
        if (isPal[i][j]) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int minCut = INT_MAX;
        for (int k = i; k < j; k++) {
            if (isPal[i][k]) { // Only cut if left part is palindrome
                int right = solve(s, k + 1, j, dp, isPal);
                minCut = min(minCut, 1 + right);
            }
        }
        return dp[i][j] = minCut;
    }
o
    int palPartition(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        vector<vector<bool>> isPal(n, vector<bool>(n, false));

        // Precompute palindrome table
        for (int len = 1; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j]) {
                    if (len <= 2) isPal[i][j] = true;
                    else isPal[i][j] = isPal[i+1][j-1];
                }
            }
        }

        return solve(s, 0, n - 1, dp, isPal);
    }
};
