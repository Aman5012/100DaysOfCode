1488. Avoid Flood in The City
//QUESTION LINK: https://leetcode.com/problems/avoid-flood-in-the-city/description/?envType=daily-question&envId=2025-10-07

TOPIC: Array
Hash Table
Binary Search
Greedy
Heap (Priority Queue)


CODE:
// TC: O(n log n)
// SC: O(n)

class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();

        set<int> dryDays;
        unordered_map<int, int> full;
        vector<int> ans(n, 1);

        for(int i=0; i<n; i++){
            int lake = rains[i];
            if(lake >0){
                ans[i] = -1;
                if(full.find(lake)!=full.end()){
                    // lake already full — we must find a 0-day to dry it
                    auto dry = dryDays.lower_bound(full[lake]);

                    if(dry== dryDays.end()) return {};
                    int day = *dry;
                    ans[day] = lake;
                    dryDays.erase(dry);
                }
                    // mark this lake as now full
                    full[lake] = i; 
            }
            else{
                    // today is a dry day — add to dryDays list
                    dryDays.insert(i);
                }
        }
        return ans;
    }
};

