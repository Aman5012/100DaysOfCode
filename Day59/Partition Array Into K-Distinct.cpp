Q2. Partition Array Into K-Distinct
//QUESTION LINK: https://leetcode.com/contest/weekly-contest-464/problems/partition-array-into-k-distinct-groups/description/

TOPIC: Array, Hashmap


CODE:
// TC:O(n)
// SC:O(n)
class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n= nums.size();
        int groups = n/k;
        if(k==0) return false;
        if(n%k !=0) return false;
        unordered_map<int, int> mp;
        for(auto x: nums){
            mp[x]++;
        }

        for(const auto &[_, f]: mp){
            if(f>groups) return false;
        }

        return true;
    }
};
