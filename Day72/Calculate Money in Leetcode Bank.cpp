1716. Calculate Money in Leetcode Bank
//QUESTION LINK: https://leetcode.com/problems/calculate-money-in-leetcode-bank/?envType=daily-question&envId=2025-10-25

TOPIC: Math


CODE:
///////////////////  appraoch 1 ////////////////////
class Solution {
public:
    int totalMoney(int n) {
        int terms = n/7; // total compelte week
        int first =28;  // in one week
        int last  = 28 + (terms-1)*7; 
        int res = terms*(first + last)/2;
        
        int remain = n%7;
        int start = terms + 1;
        for(int d=1; d<= remain; d++){
            res += start;
            start++;
        }
        
        return res;;
    }
};


///////////////////  appraoch 2 ////////////////////
class Solution {
public:
    int totalMoney(int n) {
        int totalAmount=0;
        int Monday=1;
        
        while(n>0){
            for(int day=0; day< min(n, 7); day++){
                totalAmount += Monday + day;
            }
            n -=7;
            Monday++;
        }
        return totalAmount;
    }
};
