53. Maximum Subarray

//QUESTION LNK: https://leetcode.com/problems/maximum-subarray/description/

TOPIC: array, divide and Conquer

CODE:

class Solution {
// Time Complexity: O(n)
// Space Complexity: O(1)
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];
        int currSum = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            currSum = max(nums[i], currSum + nums[i]);
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};


//////////////////////   kadane's Algo   //////////////
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        int currSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i]; 
            maxSum = max(maxSum, currSum);
            if(currSum<0) currSum =0;
        }
        return maxSum;
    }
};




// ////////////////////////////   brue force  ////////////////
// Time Complexity: O(n.n)
// Space Complexity: O(1)

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;
        for (int i =0; i < nums.size(); i++) {
            int  sum =0;
            for(int j=i; j<nums.size(); j++){
                sum += nums[j];
                maxSum =max(sum, maxSum);
            }
        }
        return maxSum;
    }
};

