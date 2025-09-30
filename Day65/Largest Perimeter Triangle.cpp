976. Largest Perimeter Triangle
//QUESTION LINK: https://leetcode.com/problems/largest-perimeter-triangle/?envType=daily-question&envId=2025-09-28

TOPIC: Array
Math
Greedy
Sorting


CODE:
/////////////////////////   Approach 1  ////////////////////////////
TC: O(n)
SC: O(1)

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size()<3) return 0;
        int n = nums.size();
        int maxi = 0;

        int z=n-1;
        int y = z-1;
        int x = z-2;

        while(x>=0){
            if((nums[z]+nums[y] > nums[x]) && (nums[x]+nums[z] > nums[y])&& (nums[x]+nums[y] > nums[z])){
                maxi = max(maxi,nums[x]+nums[y]+nums[z]);
            }
            z--;
            x--;
            y--;
        }
        if(maxi>0)return maxi;
        else return 0;
    }
};


/////////////////////////   Approach 2  ////////////////////////////
// TC: O(n)
// SC: O(1)

class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n<3) return 0;
        
        for(int i = n-3; i>=0; i--){
            if(nums[i]+nums[i+1]> nums[i+2])
            return nums[i]+nums[i+1]+ nums[i+2];
        }
        return 0;
    }
};
