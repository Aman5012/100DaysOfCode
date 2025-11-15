2169. Count Operations to Obtain Zero
//QUESTION LINK:  https://leetcode.com/problems/count-operations-to-obtain-zero/description/?envType=daily-question&envId=2025-11-09

// TOPIC: Math
// Simulation


CODE:
class Solution {
public:
    int countOperations(int num1, int num2) {
        int step=0;
        while(num1!=0 && num2 !=0){
            if(num1 >= num2){
                num1 = num1 - num2;
                step++;
            } 
            else{
                num2 = num2 - num1;
                step++;
            } 
        }
        return step;
    }
};
