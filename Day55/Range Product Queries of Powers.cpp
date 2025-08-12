438. Range Product Queries of Powers
//QUESTION LNK: https://leetcode.com/problems/range-product-queries-of-powers/?envType=daily-question&envId=2025-08-11

TOPIC: Array
Bit Manipulation
Prefix Sum


CODE:
// TC: O(q)
// SC: O(q)
class Solution {
public:
    const int MOD =1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powers;
        vector<int> ans;
        
        for(int i=0; i<32; i++){
            if(n&(1<<i)){
                powers.push_back(1<<i);
            }
        }

        for(int j=0; j<queries.size(); j++){
            long long num=1;
            for(int x=queries[j][0]; x<=queries[j][1]; x++){
                num=(num*(powers[x]%MOD)) % MOD;
            }
            ans.push_back(num);
        }
        return ans;
    }
};
