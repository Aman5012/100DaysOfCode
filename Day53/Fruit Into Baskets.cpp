904. Fruit Into Baskets
//QUESTION LNK: https://leetcode.com/problems/fruit-into-baskets/?envType=daily-question&envId=2025-08-04

TOPIC: Array
Hash Table
Sliding Window


CODE:
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int>mp;
        int i= 0;
        int ans=0;
        for(int j=0; j<fruits.size(); j++){
           int type=fruits[j];
           mp[type]++;

           while(mp.size()>2){
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0){
                    mp.erase(fruits[i]);
                }
                i++;
           }
            ans = max(ans, j-i+1);
        }
        return ans;
    }
};
