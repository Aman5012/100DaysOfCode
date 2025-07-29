74. Search a 2D Matrix

//QUESTION LNK: https://leetcode.com/problems/search-a-2d-matrix/description/

TOPIC: ray
Binary Search
Matrix


CODE:

////////////////////////////   binary search method  //////////
class Solution {
    // TC:O(log(m * n))
    // SC: O(1)
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m =matrix.size();
        int n = matrix[0].size();

        int left =0, right =m*n-1;

        while(left<=right){
            int mid = left + (right - left)/2;
            int midVal = matrix[mid / n][mid % n];
            if(midVal == target) return true;
            else if(midVal < target) left = mid+1;
            else right = mid-1;
        }
        return false;
    }
};

 
///////////////////////////////   brute force approach  ///////////////////////
class Solution {
    // TC: O(n*m)
    // SC: O(1)
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m =matrix.size();
        int n = matrix[0].size();

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == target) return true;
            }
        }
        return false;
    }
};
