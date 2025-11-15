2654. Minimum Number of Operations to Make All Array Elements Equal to 1
//QUESTION LINK: https://leetcode.com/problems/minimum-number-of-operations-to-make-all-array-elements-equal-to-1/?envType=daily-question&envId=2025-11-12

// TOPIC: Array
// Math
// Number Theory


CODE:
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n =nums.size();
        int totalgcd = nums[0];

        for(int x: nums) totalgcd = gcd(totalgcd, x);
        if(totalgcd != 1) return -1;

        // count ones;
        int ones = count(nums.begin(), nums.end(), 1);
        if(ones>0) return n-ones;

        int ans = INT_MAX;

        for(int i=0; i<n; i++){
            int g = nums[i];
            for(int j = i+1; j<n; j++){
                g = gcd(g, nums[j]);
                if(g==1){
                    ans= min(ans, j-i);
                    break;
                }
            }
        }
        return ans + n -1;
    }
};

