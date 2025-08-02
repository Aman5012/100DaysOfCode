1957. Delete Characters to Make Fancy String
//QUESTION LNK: https://leetcode.com/problems/delete-characters-to-make-fancy-string/?envType=daily-question&envId=2025-07-21

TOPIC: String


CODE:

// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int freq = 1;
        ans += s[0]; 

        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == s[i - 1]) {
                freq++;
            } else {
                freq = 1;  // Reset count for new character
            }
            if (freq <= 2) {
                ans += s[i];
            }
        }
        return ans;
    }
};
