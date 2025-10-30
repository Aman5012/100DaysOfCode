526. Minimum Number of Increments on Subarrays to Form a Target Array
//QUESTION LINK: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/?envType=daily-question&envId=2025-10-30

// TOPIC: Array
// Dynamic Programming
// Stack
// Greedy
// Monotonic Stack


CODE:

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int n = target.size();
        int ans = target[0]; 
        
        for (int i = 1; i < n; i++) {
            if (target[i] > target[i - 1]) {
                ans += target[i] - target[i - 1];
            }
        }
        
        return ans;
    }
};
