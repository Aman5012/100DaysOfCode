49. Group Anagrams
//QUESTION LINK: https://leetcode.com/problems/group-anagrams/

TOPIC: Array
Hash Table
String
Sorting


CODE:
// TC: O(n klogk)
// SC: O(n)

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n= strs.size();
        unordered_map<string, vector<string>> res;

        for(string s: strs){
            string key =s;
            sort(key.begin(), key.end());
            res[key].push_back(s);
        }

        vector<vector<string>> ans;

        for(auto &pair : res){
            ans.push_back(pair.second);
        }
        return ans;
    }
};
