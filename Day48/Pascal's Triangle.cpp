118. Pascal's Triangle
//QUESTION LNK: https://leetcode.com/problems/pascals-triangle/description/

TOPIC: ray
Dynamic Programming


CODE:

// TC: O(n)
// SC:O(1)
class Solution {
public:
    vector<int> solve(int row){
        vector<int> temp;
        long long ans=1;
        temp.push_back(1);
        for(int col=1; col<row; col++){
            ans = ans*(row-col);
            ans = ans/(col);
            temp.push_back(ans);

        }
        return temp;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i=1; i<=numRows; i++){
            ans.push_back(solve(i));
        }
        return ans;
    }
};
