36. Valid Sudoku
//QUESTION LINK: https://leetcode.com/problems/valid-sudoku/

TOPIC: Array
Hash Table
Matrix


CODE:
// TC: O(n.n)
// SC: O(n)

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        // creating set to store the value of rows and cols and boxes
        vector<unordered_set<char>> rows(9), cols(9), boxes(9);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                char c= board[i][j];
                if(c == '.') continue;
                // check the number in rows
                if(rows[i].count(c)) return false;
                rows[i].insert(c);
                // check the number in cols
                if(cols[j].count(c)) return false;
                cols[j].insert(c);

                /// now check the boxes
                int boxIndex=(i/3)*3 +  j/3;
                if(boxes[boxIndex].count(c)) return false;
                boxes[boxIndex].insert(c);
            }
        }
        return true;
    }
};
