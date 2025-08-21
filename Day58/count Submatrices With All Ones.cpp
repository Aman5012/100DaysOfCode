1504. Count Submatrices With All Ones

//QUESTION LINK: https://leetcode.com/problems/count-submatrices-with-all-ones/?envType=daily-question&envId=2025-08-21

TOPIC: Array
Dynamic Programming
Stack
Matrix
Monotonic Stack


CODE:
// Time Complexity: O(m^2 *n)
// Space Complexity: O(m∗n)

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m= mat.size();
        int n= mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n,0));
        int total=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1){
                    {
                        if(j>0){
                            dp[i][j]= 1+ dp[i][j-1];

                        }
                        else{
                            dp[i][j]=1;
                        }
                    }

                    int minWidth =dp[i][j];
                    for(int k=i; k>=0; k--){
                        minWidth = min(minWidth, dp[k][j]);
                        if(minWidth==0) break;
                        total +=minWidth;
                    }
                }
            }
        }

        return total;

    }
};
