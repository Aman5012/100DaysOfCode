2125. Number of Laser Beams in a Bank
//QUESTION LINK: https://leetcode.com/problems/number-of-laser-beams-in-a-bank/?envType=daily-question&envId=2025-10-27

// TOPIC: Array
// Math
// String
// Matrix


CODE:
//////////   appraoch 1 ///////////
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        int prev=0;
        int res=0;

        for(auto& s: bank){
        int cnt=0;
            for(char c: s){
                if(c=='1') cnt++;
            }
            if(cnt!=0){
                res += prev * cnt;
                prev = cnt;
            }
        }
        return res;
       
    }
};



////////////////////   brute force approach  ////////////
class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        
        vector<int>count;
        for(auto & s:bank){
            int cnt =0;
            for(char c: s){
                if(c=='1') cnt++;
            }
            count.push_back(cnt);
        }

        vector<int>nz;

        for(int it: count){
            if(it!= 0) nz.push_back(it);
        }

        int res=0;
        if(nz.size()< 0) return res;

        for(int i=1; i<nz.size(); i++){
            int temp = nz[i]* nz[i-1];
            res += temp; 
        }
        return res;
    }
};
