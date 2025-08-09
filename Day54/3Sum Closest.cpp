16. 3Sum Closest
//QUESTION LNK: https://leetcode.com/problems/3sum-closest/

TOPIC: Array
Two Pointers
Sorting


CODE:
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closestSum = nums[0]+ nums[1]+nums[2];

        for(int i=0; i<n; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int j= i+1;
            int k=n-1;
            while(j<k){
                int sum = nums[i]+ nums[j]+ nums[k];
                if (abs(target - sum) < abs(target - closestSum)) {
                    closestSum = sum;
                }
                else if(sum> target){
                    k--;
                }else if(sum<target){
                    j++;
                }
                else{
                    return sum;
                }

            }
        }
        return closestSum;
    }
};
