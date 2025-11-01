3289. The Two Sneaky Numbers of Digitville
//QUESTION LINK: https://leetcode.com/problems/the-two-sneaky-numbers-of-digitville/?envType=daily-question&envId=2025-10-31

// TOPIC: Array
// Hash Table
// Math


CODE:
////////////////////////////  optimal solution //////////////////////// 
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int a=0;
        int b=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]==nums[i-1]){
                a = nums[i];
                break;
            } 
        }
        for(int i=n-1; i>=0; i--){
            if(nums[i]==nums[i-1]){
                b = nums[i];
                break;
            } 
        }
        return {a,b};
    }
};

///////////////////   using extra  space ///////////////////////////
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int x: nums){
            mp[x]++;
        }
        for(auto [val, f]: mp){
            if(f>1)ans.push_back(val);
        }
        return ans;
    }
};
