6. Zigzag Conversion
//QUESTION LINK: https://leetcode.com/problems/zigzag-conversion/

TOPIC: String


CODE:

Time Complexity: O(n)
Space Complexity: O(n)

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.size();

        if (numRows == 1 || numRows >= s.size())
            return s;
        vector<string> rows(min(numRows, n), "");
        int currRow =0;
        bool goingDown =false;

        for(char c: s){
           rows[currRow] +=c;

           if(currRow==0 || currRow == numRows-1){
                goingDown = !goingDown;
           }

           if(goingDown ==true){
                currRow++;
           }else currRow--;
        }
        string finalAns = "";
        for (int i = 0; i < numRows; i++)
            finalAns += rows[i];

        return finalAns;
        
    }
};
