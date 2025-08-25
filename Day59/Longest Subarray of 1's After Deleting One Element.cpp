Longest Subarray of 1's After Deleting One Element
  //QUESTION LINK: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/?envType=daily-question&envId=2025-08-24

TOPIC: Array
Dynamic Programming
Sliding Window



CODE:
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, ans = 0, count0 = 0;

        for (int r = 0; r < n; r++) {
            if (nums[r] == 0) count0++;

            // shrink window if more than one zero
            while (count0 > 1) {
                if (nums[l] == 0) count0--;
                l++;
            }

            // window size is (r - l + 1), but we must delete one element (the zero)
            ans = max(ans, r - l);
        }
        return ans;
    }
};
