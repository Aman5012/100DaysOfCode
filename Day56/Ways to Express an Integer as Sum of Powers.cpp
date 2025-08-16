2787. Ways to Express an Integer as Sum of Powers
//QUESTION LNK: https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/description/?envType=daily-question&envId=2025-08-12

TOPIC: Dynamic Programming


CODE:

//////////////////////////////   recursion  ////////////////// 
// TC: O(2^⌊n^(1/x)⌋)
// SC: O(n^(1/x))
class Solution {
public:

    int solve(int n, int num, int x){
        // base case 
        if(n==0) return 1;
        if(n<0 ) return 0;
        int currentPow= pow(num, x);
        if(currentPow> n) {
            return 0; 
        }

        int take = solve(n - currentPow, num+1, x);
        int skip = solve(n, num+1, x);

        return take+skip;
    }
    int numberOfWays(int n, int x) {
        return solve(n, 1, x);
    }
};

/////////////////////////////////////  recursion + dp    ////////////////////////////
// TC: O(n * n^(1/x))
// SC: O(n²)

class Solution {
public:
        long long MOD = 1e9+7;
    int solve(int n, int num, int x, vector<vector<int>>& dp){
        // base case 
        if(n==0) return 1;
        if(n<0 ) return 0;
        int currentPow= pow(num, x);
        if(currentPow> n) {
            return 0; 
        }
        if(dp[n][num]!=-1) return dp[n][num];

        int take = solve(n - currentPow, num+1, x, dp);
        int skip = solve(n, num+1, x, dp);

        return (dp[n][num])=(take+skip)%MOD;
    }
    int numberOfWays(int n, int x) {
        
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(n, 1, x, dp);
    }
};
