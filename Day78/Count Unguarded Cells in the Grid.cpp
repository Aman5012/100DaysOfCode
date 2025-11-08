2257. Count Unguarded Cells in the Grid
//QUESTION LINK: https://leetcode.com/problems/count-unguarded-cells-in-the-grid/?envType=daily-question&envId=2025-11-02

TOPIC: Array
Matrix
Simulation


CODE:
// TC: O(m × n + G × (m + n))
// SC: O(m.n)

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> mat(m, vector<int>(n, 0));
        int row, col;
        for(auto w: walls){
            mat[w[0]][w[1]] =-1;
        }
        for(auto g: guards){
            mat[g[0]][g[1]]=2;
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==2){
                    // move up
                    int x = i-1, y=j;
                    while(x>=0 && mat[x][y]!=-1 && mat[x][y]!=2){
                        mat[x][y]=1;
                        x--;
                    }

                    // mpve down
                    x=i+1, y=j;
                    while(x<m && mat[x][y]!=-1 && mat[x][y]!=2){
                        mat[x][y]=1;
                        x++;
                    }
                    // move right
                    x=i, y= j+1;
                    while(y<n && mat[x][y]!=-1 && mat[x][y]!=2){
                        mat[x][y]=1;
                        y++;
                    }
                    // move left
                    x=i, y=j-1;
                    while(y>=0 && mat[x][y]!=-1 && mat[x][y]!=2){
                        mat[x][y]=1;
                        y--;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==0) ans++;
            }
        }
        return ans;
    }
};
