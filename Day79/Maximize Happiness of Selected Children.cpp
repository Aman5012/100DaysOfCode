3075. Maximize Happiness of Selected Children
//QUESTION LINK: https://leetcode.com/problems/maximize-happiness-of-selected-children/?envType=daily-question&envId=2025-12-25

TOPIC: Array
Greedy
Sorting


CODE:
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.begin(), happiness.end(), greater<int>());
        int count=0;
        long long  sum =0;
        for(int x: happiness){
                x -=count;
                count++;
            if(k>0 && x>=0){
                sum +=x;
                k--;
            }
        }
        return sum;
    }
};
