2561. Rearranging Fruits
//QUESTION LNK: https://leetcode.com/problems/rearranging-fruits/?envType=daily-question&envId=2025-08-02

TOPIC: Array
Hash Table
Greedy
Sort


CODE:
// TC: O(n log n)
// SC: O(n)
class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> mp;
        int minE= INT_MAX;

        for(auto & x: basket1){
            mp[x]++;
            minE = min(minE, x);
        }
        for(auto & x: basket2){
            mp[x]--;
            minE = min(minE, x);
        }
        vector<int> finalList;
        for(auto &it: mp){
            int cost = it.first;
            int count = it.second;

            if(count % 2!=0) return -1;

            for(int i=1; i<=abs(count/2); i++){
                finalList.push_back(cost);
            }
        }

        sort(finalList.begin(), finalList.end());

        long long res=0;
        for(int i=0;i<finalList.size()/2; i++){
            res += min(finalList[i], minE * 2);
        }
        return res;
    }
};
