3461. Check If Digits Are Equal in String After Operations I

//QUESTION LINK: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/description/?envType=daily-question&envId=2025-10-23

// TOPIC: Math
// String
// Simulation
// Combinatorics
// Number Theory


CODE:
//////////////////////  iterative method ///////////////////////////
// TC: O(n²)
// SC: O(n)

class Solution {
public:
    bool hasSameDigits(string s) {
        if (s.size() < 2) return false;

        string temp =s;
        while(temp.size()>2){
            string st = "";
            for(int i=1; i<temp.size(); i++){
                st += to_string(((temp[i] - '0') + (temp[i - 1] - '0')) % 10);
            }
            temp = st;
        }
        bool ok = false;
        if (temp.size() == 2) {
            if(temp[0] == temp[1]) ok = true;
        }
        return ok;
    }
};

 ////////////////////////////////   recursive soslution ///////////////////
// TC: O(n²)
// SC: O(n)

class Solution {
public:
    bool solve(string temp) {
        if (temp.size() == 2) {
            return temp[0] == temp[1];
        }

        string st = "";
        for (int i = 1; i < temp.size(); i++) {
            st += to_string(((temp[i] - '0') + (temp[i - 1] - '0')) % 10);
        }

        return solve(st);
    }

    bool hasSameDigits(string s) {
        if (s.size() < 2) return false;
        return solve(s);
    }
};
