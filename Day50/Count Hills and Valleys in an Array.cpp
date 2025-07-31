2210. Count Hills and Valleys in an Array

//QUESTION LNK: https://leetcode.com/problems/count-hills-and-valleys-in-an-array/description/?envType=daily-question&envId=2025-07-27

// TOPIC: Array

CODE:
// TC: O(n)
// SC: O(n)
class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int count=0;
        vector<int> cleaned;
        cleaned.push_back(nums[0]);
        for(int i=1; i< nums.size(); i++){
            if(nums[i]!= nums[i-1]){
                cleaned.push_back(nums[i]);
            }

        }
        for(int i=1; i<cleaned.size()-1; i++){
            if(cleaned[i]<cleaned[i-1] && cleaned[i]<cleaned[i+1] || cleaned[i]>cleaned[i-1] && cleaned[i]>cleaned[i+1]) count++;
        }
        return count;
    }
};
