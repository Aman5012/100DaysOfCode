1277. Count Square Submatrices with All Ones
//QUESTION LINK: https://leetcode.com/problems/count-square-submatrices-with-all-ones/?envType=daily-question&envId=2025-08-20

TOPIC: Array
Dynamic Programming
Matrix


CODE:
// TC: 𝑂(m.n. min(m, n)^3)
// sc: O(1)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
        
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int sum=0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if (matrix[i][j] == 1) {
                if (i == 0 || j == 0) dp[i][j] = 1;
                else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                sum += dp[i][j];
                }
            else dp[i][j]=0;
            }
        }
        return sum;
    }
};



// // TC: 𝑂(m.n. min(m, n)^3)
// // sc: O(1)
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m= matrix.size();
        int n= matrix[0].size();
        int count=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==1){
                    int maxSize = min(m-i, n-j);
                    for(int size=1; size<=maxSize; size++){
                        bool isValid = true;
                        for(int x=i; x<i+size; x++){
                            for(int y=j; y<j+size; y++){
                                if(matrix[x][y]==0){
                                    isValid = false;
                                    break;
                                }
                            }
                            if(!isValid) break;
                        }
                    if(isValid) count++;
                    else break;
                    }
                }
            }
        }
        return count;
    }
};
