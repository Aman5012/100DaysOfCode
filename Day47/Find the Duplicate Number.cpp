287. Find the Duplicate Number

//QUESTION LNK: https://leetcode.com/problems/find-the-duplicate-number/

TOPIC: ray
Two Pointers
Binary Search
Bit Manipulation


CODE:

class Solution {
// Time Complexity: O(n)
// Space Complexity: O(n)

public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int , int> freq;
        for(int num: nums){
            freq[num]++;
        }
        int ans;
        for(auto [val, f]: freq){
            if(f>1) ans = val;
        }
        return ans;
    }
};

////////////////////////// (Floyd's Cycle Detection)

class Solution {
// Time Complexity: O(n)
// Space Complexity: O(n)
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Phase 1: Detect cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        // Phase 2: Find entry point (duplicate)
        slow = nums[0];
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};
