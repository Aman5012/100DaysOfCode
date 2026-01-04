441. Arranging Coins
//QUESTION LINK:  https://leetcode.com/problems/arranging-coins/

TOPIC:
Math
Binary Search

CODE:
class Solution {
public:
    int arrangeCoins(int n) {
        int first =1;
        long long sum=0;
        int row=0;
        while(sum<=n){
            sum +=first;
            first++;
            row++;
        }
        return row-1;
    }
};
