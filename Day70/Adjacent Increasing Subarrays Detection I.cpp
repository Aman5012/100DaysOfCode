3349. Adjacent Increasing Subarrays Detection I
//QUESTION LINK: https://leetcode.com/problems/adjacent-increasing-subarrays-detection-i/?envType=daily-question&envId=2025-10-14

TOPIC: Array


CODE:
// TC: O(n.k)
// SC: O(1)

class Solution {
public:
    bool solve(vector<int>& nums, int start, int k){
        
        for(int i= start; i< start+k-1; i++){
            if(nums[i] >= nums[i+1]) return false;
        }
        return true;
    }
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n= nums.size();

        for(int i = 0; i + 2 * k <= n; i++){
            if(solve(nums, i, k) && solve(nums, i+k, k))
                return true;
            
        }
        return false;
    }
};
