3541. Find Most Frequent Vowel and Consonant
//QUESTION LINK: https://leetcode.com/problems/find-most-frequent-vowel-and-consonant/?envType=daily-question&envId=2025-09-13

TOPIC: Hash Table
String
Counting


CODE:
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int maxFreqSum(string s) {
        map<char, int> mpp;

        for(char ch: s){
            mpp[ch]++;
        }
        int vmaxi = 0;
        int cmaxi = 0;
        for(auto [key, val]: mpp){
            if(key == 'a' || key == 'e' ||key == 'i' ||key == 'o' ||key == 'u' ){
                vmaxi = max(vmaxi, val);
            }
            else{
                cmaxi = max(cmaxi, val);
            }
        }
        return cmaxi + vmaxi;
    }
};
