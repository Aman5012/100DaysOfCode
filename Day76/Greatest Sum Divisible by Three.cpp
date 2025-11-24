1262. Greatest Sum Divisible by Three
//QUESTION LINK: https://leetcode.com/problems/greatest-sum-divisible-by-three/?envType=daily-question&envId=2025-11-23

TOPIC:
Array
Dynamic Programming
Greedy
Sorting

CODE:
class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
     
       int sum = 0;
        vector<int> r1;
        vector<int> r2;

        for(int x: nums){
            sum +=x;
            if(x%3==1) r1.push_back(x);
            if(x%3==2) r2.push_back(x);
        }

        sort(r1.begin(), r1.end());
        sort(r2.begin(), r2.end());
        if(sum%3==0) return sum;
        int ans=0;

        // with mpodulo 1
        if(sum%3==1){
            int removeOne=INT_MAX;
            if(r1.size()>=1){
                 removeOne = r1[0];
            }
            int removeTwo=INT_MAX;
            if(r2.size()>=2){
                removeTwo = r2[0]+r2[1];
            }
            ans = sum - min(removeOne, removeTwo);
        }else{

            int removeOne=INT_MAX;
            if(r2.size()>=1){
                 removeOne = r2[0];
            }
            int removeTwo=INT_MAX;
            if(r1.size()>=2){
                removeTwo = r1[0]+r1[1];
            }
            ans = sum - min(removeOne, removeTwo);
        }
        return ans;

    }
};
 


