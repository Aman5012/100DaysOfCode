1018. Binary Prefix Divisible By 5
//QUESTION LINK: https://leetcode.com/problems/binary-prefix-divisible-by-5/?envType=daily-question&envId=2025-11-24

TOPIC:
Array
Bit Manipulation


CODE:
class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int value = 0;

        for(int bit : nums){
            value = (value * 2 + bit) % 5;
            ans.push_back(value == 0);
        }

        return ans;
    }
};

