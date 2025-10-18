2598. Smallest Missing Non-negative Integer After Operations
//QUESTION LINK: https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/?envType=daily-question&envId=2025-10-16

TOPIC: Array
Hash Table
Math
Greedy


CODE:
// TC: O(n)
// sc: O(value)

class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int, int> freq;
        for (int x : nums) {
            int key = ((x % value) + value) % value; // handle negatives properly
            freq[key]++;
        }

        for (int i = 0; ; i++) {
            int key = i % value;
            if (freq[key] == 0)
                return i; // this is the smallest missing number
            freq[key]--; 
        }
    }
};
