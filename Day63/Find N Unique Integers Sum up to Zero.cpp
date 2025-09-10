1304. Find N Unique Integers Sum up to Zero
//QUESTION LINK: https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/?envType=daily-question&envId=2025-09-07

TOPIC: Array
Math



CODE:
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;

        int limit = n/2;
        int i=-limit;
        while( i<=limit){
            if(n%2!=0){
                ans.push_back(i);
            }else if(n%2==0 && i!=0){
                ans.push_back(i);
            }
            i++;
            
        }
        return ans;
    }
};
