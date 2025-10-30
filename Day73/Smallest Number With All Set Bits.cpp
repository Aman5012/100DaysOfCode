3370. Smallest Number With All Set Bits
//QUESTION LINK: https://leetcode.com/problems/smallest-number-with-all-set-bits/?envType=daily-question&envId=2025-10-29 

TOPIC: Math
Bit Manipulation


CODE:
class Solution {
public:
    int smallestNumber(int n) {

        int ans=1;
        while(ans<=n){
            ans *= 2; 
        }
        return ans-1;
    }
};
