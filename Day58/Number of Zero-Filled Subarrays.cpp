2348. Number of Zero-Filled Subarrays
//QUESTION LINK: https://leetcode.com/problems/number-of-zero-filled-subarrays/?envType=daily-question&envId=2025-08-19

TOPIC: Array
Math


CODE:
// TC: O(n)
// SC: O(1)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
         long long count = 0, run = 0;

    for (int x : nums) {
        if (x == 0) {
            run++;  // extend zero run
            count += run; // add new subarrays ending here
        } else {
            run = 0; // reset when non-zero found
        }
    }
    return count;
    }
};
