2536. Increment Submatrices by One
//QUESTION LINK: https://leetcode.com/problems/increment-submatrices-by-one/?envType=daily-question&envId=2025-11-14

// TOPIC: Array
// Matrix
// Prefix Sum


Code:
// Time Complexity: O(Q.n²)
// Space Complexity: O(n²)

class Solution {
public:
    vector<vector<int>> rangeAddQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> mat(n, vector<int>(n,0));
        for(auto q:queries){
            int r1 = q[0]; 
            int c1 = q[1]; 
            int r2 = q[2]; 
            int c2 = q[3]; 

            for(int i = r1; i <= r2; i++){
                for(int j = c1; j <= c2; j++){
                    mat[i][j]++;
                }
            }
        }
        return mat;
    }
};
