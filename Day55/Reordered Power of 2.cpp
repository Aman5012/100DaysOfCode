869. Reordered Power of 2
//QUESTION LNK: https://leetcode.com/problems/reordered-power-of-2/?envType=daily-question&envId=2025-08-10

TOPIC: Hash Table
Math
Sorting
Counting
Enumeration



CODE:
// TC: O(k log k) // k is the logest length of digits
// SC: O(k)
class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // convert integer to stirng
        string n1 = to_string(n);
        sort(n1.begin(),n1.end());

        for(int i = 0; i < 30 ; i++){
            // check on each iteration 
            string n2 = to_string(1 << i);
            sort(n2.begin(), n2.end());

            if(n1 == n2) return true;
        }
        return false;
    }
};
