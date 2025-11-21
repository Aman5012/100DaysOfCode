717. 1-bit and 2-bit Characters
//QUESTION LINK: https://leetcode.com/problems/1-bit-and-2-bit-characters/?envType=daily-question&envId=2025-11-18

TOPIC: Array


CODE:
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        int n = bits.size();
        int i=0;
        bool check = true;
        while(i<n){
            if(bits[i]==1){
                i +=2;
                if(i>=n-1) check = false;
            }else{
                check = true;
                i++;
            } 
        }
        return check;
    }
};
