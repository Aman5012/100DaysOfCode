1695. Maximum Erasure Value
//QUESTION LNK: https://leetcode.com/problems/maximum-erasure-value/description/?envType=daily-question&envId=2025-07-22

TOPIC: Array
Hash Table
Sliding Window



CODE:

// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int left = 0, right = 0;
        int currSum = 0, maxSum = 0;

        while (right < nums.size()) {
            // If we encounter a duplicate, shrink window from left
            while (seen.count(nums[right])) {
                seen.erase(nums[left]);
                currSum -= nums[left];
                left++;
            }

            // Add current element
            seen.insert(nums[right]);
            currSum += nums[right];
            maxSum = max(maxSum, currSum);

            right++;
        }

        return maxSum;
    }
};
