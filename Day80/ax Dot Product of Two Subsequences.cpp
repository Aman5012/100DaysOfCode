1458. Max Dot Product of Two Subsequences
//QUESTION LINK: https://leetcode.com/problems/max-dot-product-of-two-subsequences/?envType=daily-question&envId=2026-01-08

TOPIC: DP


CODE:
// TC: O(m.n)
// SC: O(m.n)
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int m= nums1.size();
        int n= nums2.size();

        vector<vector<int>> dp(m, vector<int>(n));
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int currProd = nums1[i]*nums2[j];
                dp[i][j] = currProd;

                if(i>0 && j>0){
                    dp[i][j] += max(0, dp[i-1][j-1]);
                }
                if(i>0){
                    dp[i][j] = max(dp[i-1][j], dp[i][j]);
                }
                if(j>0){
                    dp[i][j] = max(dp[i][j-1], dp[i][j]);
                }
            }
        }
        return dp[m-1][n-1];
       
    }
};
