Q1. Check Divisibility by Digit Sum and Product
//QUESTION LNK: https://leetcode.com/contest/weekly-contest-459/problems/check-divisibility-by-digit-sum-and-product/ 

TOPIC: maths


CODE: 

// Time Complexity: O(n)
// Space Complexity: O(1)


class Solution {
public:
    bool checkDivisibility(int n) {
        int sum=0;
        int product =1;
        int temp = n;
        while(temp>0){
            int digit = temp%10;
            sum +=digit;
            product *= digit;
            temp=temp/10;
            
        }
        if((sum+product)==0){
            return false;
        }else return  n % (sum + product) == 0;
    }
};
