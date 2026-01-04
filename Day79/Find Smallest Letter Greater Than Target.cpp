744. Find Smallest Letter Greater Than Target
//QUESTION LINK: https://leetcode.com/problems/find-smallest-letter-greater-than-target/

TOPIC: Array
Binary Search


CODE:
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        auto ub = upper_bound(letters.begin(), letters.end(), target);

        if(ub == letters.end()) return letters[0];

        int idx= ub - letters.begin();
        return letters[idx];
    }
};
