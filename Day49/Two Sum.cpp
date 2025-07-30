1. Two Sum

//QUESTION LNK: https://leetcode.com/problems/two-sum/

TOPIC: Array
Hash Table


CODE:
class Solution {
    // TC:O(n log n)
    // SC:O(n)
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int moreNeeded = target - num;
            if (mpp.find(moreNeeded) != mpp.end()) {
                return {mpp[moreNeeded], i};
            }
            mpp[num] = i;
        }
        return { -1, -1};
    }
};

////////////////////   brute force appraoch  ////////////////
    // TC: O(n.n)
    // SC: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i< n; i++){
            for(int j=i+1; j<n; j++){
                if(nums[i]+ nums[j]== target) return {i, j}; 
            }
        }
        return {};
    }
};
