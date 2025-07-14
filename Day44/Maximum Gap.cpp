164. Maximum Gap
//QUESTION LNK: https://leetcode.com/problems/maximum-gap/description/

TOPIC: Array
Sorting
Bucket Sort
Radix Sort


CODE:

class Solution {
public:
    // TC: O(n log n)
    // SC: O(1)
    int maximumGap(vector<int>& nums) {
        int n =nums.size();
        if(n<2) return 0;
        sort(nums.begin(), nums.end());
        int maxi=0;
        for(int i=1; i<n; i++){
            maxi = max(maxi, nums[i]- nums[i-1]); 
        }
        return maxi;
    }
};

///      for O(n)  use bucket sort
