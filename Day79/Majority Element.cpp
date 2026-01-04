169. Majority Element
//QUESTION LINK: https://leetcode.com/problems/majority-element/description/

// TOPIC: Array
// Hash Table
// Divide and Conquer
// Sorting
// Counting


CODE:
/////////////////   Boyer–Moore majority vote  ////////////////
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n= nums.size();
        int candidate = 0;
        int count=0;

        for(int num: nums){
            if(candidate == num){
                count++;
            }
            else if(count==0){
                candidate=num;
            }else{
                count--;
            }
        }
        return candidate;
    }
};
