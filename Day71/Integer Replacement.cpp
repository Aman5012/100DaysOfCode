397. Integer Replacement
//QUESTION LINK: https://leetcode.com/problems/integer-replacement/

TOPIC: Dynamic Programming
Greedy
Bit Manipulation
Memoization


CODE:
// TC: O(n)
// SC: O(1)

class Solution {
public:
    int integerReplacement(long long  n) {
        int count=0;
        while(n>1){
            if(n%2==0){
                n= n/2;
            }
            else if(n==3 || (n-1)%4==0){   // Tricky part
                n = n-1;
            }else {
                n = n+1;
            }
            count++;
        }
        return count;
    }
};
