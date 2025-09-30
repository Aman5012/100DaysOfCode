611. Valid Triangle Number
//QUESTION LINK: https://leetcode.com/problems/valid-triangle-number/?envType=daily-question&envId=2025-09-26

// TOPIC: Array
// Two Pointers
// Binary Search
// Greedy
// Sorting


CODE:
// Time Complexity: O(n²)
// Space Complexity: O(1)

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int count=0;
        for (int k = n-1; k >= 2; k--) {
            int i = 0, j = k-1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    // All pairs from i..(j-1) with j are valid
                    count += (j - i);
                    j--;
                } else {
                    i++;
                }
            }
        }
        return count;
    }
};
