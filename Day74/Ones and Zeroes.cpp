474. Ones and Zeroes
//QUESTION LINK: https://leetcode.com/problems/ones-and-zeroes/?envType=daily-question&envId=2025-11-11

TOPIC:Array
String
Dynamic Programming


CODE:
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {

        vector<vector<int>> dp (m+1, vector<int>(n+1, 0));
        for(auto s: strs){
            int ones = count(s.begin(), s.end(), '1');
            int zeros = count(s.begin(), s.end(), '0');

            for(int i=m; i>=zeros; i--){
                for(int j=n; j>=ones; j--){
                    dp[i][j] = max(dp[i][j], dp[i- zeros][j- ones] + 1);
                }
            }
        }
        return dp[m][n];
    }
};

