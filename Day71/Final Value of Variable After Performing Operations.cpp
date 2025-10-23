2011. Final Value of Variable After Performing Operations
//QUESTION LINK: https://leetcode.com/problems/final-value-of-variable-after-performing-operations/?envType=daily-question&envId=2025-10-20

TOPIC: Array
String
Simulation


CODE
TC: O(n)
SC: O(1)
class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int v=0;
        
        for(auto x: operations){
            if(x == "X++" || x=="++X" ){
                v = v+1;
            }else v = v-1;
        }
        return v;
    }
};
