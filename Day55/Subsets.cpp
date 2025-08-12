78. Subsets
//QUESTION LNK: https://leetcode.com/problems/subsets/

TOPIC: Array
Backtracking
Bit Manipulation


CODE:
//////////////////////////////////  Bitmask Enumeration   //////////////////////////
// Time Complexity: O(n. 2^n)
// otal Space (including output): O(n. 2^n)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        for(int mask =0; mask< (1<<n); mask++){
            vector<int> temp;
            for(int j=0; j<n; j++){
                if ((mask >> j) & 1) {// check if j-th bit is set
                    temp.push_back(nums[j]);
                }                  
            }
            ans.push_back(temp);
        }
        return ans;
    }
};





// // ///////////////////    backtracking   //////////////////

// Time Complexity: O(n. 2^n)
// Auxiliary Space Complexity: O(n)
// Total Space (including output): O(n. 2^n)

class Solution {
public:
    void solve(vector<int>& nums, int index,  vector<int> temp, vector<vector<int>> &ans ){
        // base case  
        ans.push_back(temp);

        for(int i=index; i<nums.size(); i++){
            // choose
            temp.push_back(nums[i]);

            // recusion
            solve(nums, i+1, temp, ans);

            // backtracking
            temp.pop_back();
        }

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        int index=0;
        solve(nums, index, temp, ans);
        
        return ans;
    }
};









/////////////////////////   recursion  /////////////
// Time Complexity: O(n. 2^n)
// Auxiliary Space Complexity: O(n)
// Total Space (including output): O(n. 2^n)
class Solution {
public:
    void solve(vector<int>& nums, int index,  vector<int> temp, vector<vector<int>> &ans ){
        // base case  
        if(index>= nums.size()) {
            ans.push_back(temp);
            return;
        }

        solve(nums, index+1, temp, ans);
        int element =nums[index];
        temp.push_back(element);
        solve(nums, index+1, temp, ans);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        int index=0;
        solve(nums, index, temp, ans);
        
        return ans;
    }
};
