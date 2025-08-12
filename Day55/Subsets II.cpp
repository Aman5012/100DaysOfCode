90. Subsets II
//QUESTION LNK: https://leetcode.com/problems/subsets-ii/

TOPIC: Array
Backtracking
Bit Manipulation


CODE:
//////////////////////   recurtion solution   //////////////////////////
// TC: O(n. 2^n);
// SC: O(2^n)
class Solution {
public:
    void rec(int index, vector<int>& nums, vector<vector<int>> &ans, vector<int>ds){
        ans.push_back(ds);

        for(int i =index; i<nums.size(); i++){
            if(i!=index && nums[i]==nums[i-1]) continue;
            ds.push_back(nums[i]);
            rec(i+1, nums, ans, ds);
            ds.pop_back();

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> ds;

        rec(0, nums, ans, ds);
        return ans;
    }
};

//////////////////////////////////  Bitmask Enumeration   //////////////////////////
// TC: O(n. 2^n);
// SC: O(2^n)
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        // create a set which store the unique subsets
        set<vector<int>> subset;

        // vector<vector<int>> ans;
        for(int i=0; i< (1<<n); i++){
            vector<int> temp;
            for(int j=0; j<n; j++){
                if((i>>j)&1){
                    temp.push_back(nums[j]);
                }
            }
            subset.insert(temp);
        }
        return vector<vector<int>>(subset.begin(), subset.end());
    }
};


