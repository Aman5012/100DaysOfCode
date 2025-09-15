3227. Vowels Game in a String
//QUESTION LINK: https://leetcode.com/problems/vowels-game-in-a-string/?envType=daily-question&envId=2025-09-12

// TOPIC: Math
// String
// Brainteaser
// Game Theory


CODE:
// TC: O(n)
// SC: O(1)
class Solution {
public:
    bool doesAliceWin(string s) {
        int n = s.size();
        int count =0;
        for(char ch : s){
            if(ch == 'a'|| ch == 'o'||ch == 'e'||ch == 'i'||ch == 'u'){
                count++;
            }

        }
        if(count == 0) return false;
        else return true;
    }
};
