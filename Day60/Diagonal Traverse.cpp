498. Diagonal Traverse
//QUESTION LINK: https://leetcode.com/problems/diagonal-traverse/?envType=daily-question&envId=2025-08-25

TOPIC: Array
Matrix
Simulation


CODE:
// Time Complexity: O(m * n)
// Space Complexity: O(m * n)

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, vector<int>> ans;
        for(int r=0; r<m; r++){
            for(int c=0; c<n; c++){
                int x= r+c;
                ans[x].push_back(mat[r][c]);
            }
        }
        vector<int> res;
        for(auto& it: ans){
            if(it.first%2==0){
                reverse(it.second.begin(), it.second.end());
            }
        }
        for(int key=0; key<=(m-1+n-1); key++){
            auto vec= ans[key];

            for(auto it: vec ){
                res.push_back(it);
            }
        }
    
        return res;
    }
};
