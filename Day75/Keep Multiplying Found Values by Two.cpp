2154. Keep Multiplying Found Values by Two
//QUESTION LINK: https://leetcode.com/problems/keep-multiplying-found-values-by-two/?envType=daily-question&envId=2025-11-19

TOPIC: Array
Hash Table
Sorting
Simulation


CODE:
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> seen(nums.begin(), nums.end());

        while(seen.find(original)!= seen.end()){
            original = 2*original;
        }
        return original;
    }
};
