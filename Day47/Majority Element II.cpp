229. Majority Element II

//QUESTION LNK: https://leetcode.com/problems/majority-element-ii/description/

TOPIC: Array
Hash Table
Sorting
Counting


CODE:
// TC: O(N)
// SC: O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int num: nums){
            freq[num]++;
        }
        vector<int> ans;
        for(auto [key, f]: freq){
            if(f>n/3) ans.push_back(key);
        }

        return ans;
    }
};
