3228. Maximum Number of Operations to Move Ones to the End
//QUESTION LINK: https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/?envType=daily-question&envId=2025-11-13

TOPIC: String
Greedy
Counting


CODE:

class Solution {
public:
    int maxOperations(string s) {
        int ops = 0;
        int ones_count = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            if (s[i] == '1') {
                ones_count++;
            } else { // s[i] == '0'
                // We only add operations when we first encounter a '0' block
                // immediately after a '1' block.
                if (i > 0 && s[i - 1] == '1') {
                    ops += ones_count;
                }
            }
        }
        return ops;
    }
};
