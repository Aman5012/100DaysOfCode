3136. Valid Word

//QUESTION LNK: https://leetcode.com/problems/valid-word/?envType=daily-question&envId=2025-07-15

TOPIC: string

CODE:

Time Complexity: O(n)
Space Complexity: O(1)

class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) {
            return false;
        }
        bool has_vowel = false;
        bool has_consonant = false;
        for (auto c : word) {
            if (isalpha(c)) {
                c = tolower(c);
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                    has_vowel = true;
                } else {
                    has_consonant = true;
                }
            } else if (!isdigit(c)) {
                return false;
            }
        }
        return has_vowel && has_consonant;
    }
};
