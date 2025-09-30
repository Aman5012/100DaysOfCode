2221. Find Triangular Sum of an Array
//QUESTION LINK: https://leetcode.com/problems/find-triangular-sum-of-an-array/description/?envType=daily-question&envId=2025-09-30

TOPIC: Array
Math
Simulation
Combinatorics


CODE:
// Time Complexity: O(n²)
// Space Complexity: O(n)

class Solution {
public:
    int triangularSum(vector<int>& nums) {

        while(nums.size()>1){
                vector<int> temp;
            for(int i=1; i<nums.size(); i++){
                temp.push_back((nums[i]+nums[i-1]) % 10);
            }
            nums = temp; // nums = move(new_nums)
            temp.clear();
        }
        return nums[0];
    }
};
