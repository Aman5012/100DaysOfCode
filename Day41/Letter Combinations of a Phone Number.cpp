17. Letter Combinations of a Phone Number

// QUESTION LNK: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

// TOPIC: Hash Table
// String
// Backtracking


// CODE:

// Time Complexity: O(m^n)
// Space Complexity: O(n * m^n)
  class Solution {
public:
    vector<string> ans;  // global vector
    void solve(int index, string& digits, map<char, string>& mapping, string &curr_str){
        if(index==digits.size()){
            ans.push_back(curr_str);
        }
        char ch = digits[index];
        for(char alphabet: mapping[ch]){
            curr_str +=alphabet;
            solve(index+1, digits, mapping, curr_str);// recursive call
            curr_str.pop_back();// backtrack
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return ans;
        vector<string> temp;
        map<char, string> mapping;
        mapping['2'] = {"abc"};
        mapping['3'] = {"def"};
        mapping['4'] = {"ghi"};
        mapping['5'] = {"jkl"};
        mapping['6'] = {"mno"};
        mapping['7'] = {"pqrs"};
        mapping['8'] = {"tuv"};
        mapping['9'] = {"wxyz"};

        string curr_str;
        int index=0;
        solve(index, digits, mapping, curr_str);
        return ans;
    }
};
