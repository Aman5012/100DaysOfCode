961. N-Repeated Element in Size 2N Array
//QUESTION LINK: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/?envType=daily-question&envId=2026-01-02

TOPIC: Array
Hash Table


CODE:

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=1; i<nums.size(); i++){
            if(nums[i]== nums[i-1]) return nums[i];
        }
        return 0;
    }
};

////////////////////  approach 2  ////////////////////
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> set;
        
        for(int i=0; i<nums.size(); i++){
            if(set.find(nums[i]) != set.end()) return nums[i];
            else set.insert(nums[i]);
        }
        return 0;
    }
};
