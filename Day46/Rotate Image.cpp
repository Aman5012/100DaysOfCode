48. Rotate Image(matrix)
//QUESTION LNK: https://leetcode.com/problems/rotate-image/description/

TOPIC: array, matrix

CODE:
///////////////////////////////  brute force apppraoch
class Solution {
// TC: O(n.n)
// SC: O(1)
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> arr(n, vector<int>(n));
        for(int i=0; i<n ;i++){
            for(int j=0; j<n;j++){
               arr[j][n-1-i]= matrix[i][j] ;
            }
        }
        matrix =arr;
    }
};

////////////////  optimal approach  ///////////

// TC: O(n.n)
// SC: O(1)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        /// transpose the matrix  
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
