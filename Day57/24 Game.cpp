679. 24 Game
//QUESTION LINK: https://leetcode.com/problems/24-game/description/?envType=daily-question&envId=2025-08-18

TOPIC: rray
Math
Backtracking


CODE:
// Time Complexity (general n): O((n!)^2)
// Time Complexity (n=4 case): Constant (~576 operations, very fast)
// Space Complexity: O(1) for n=4

class Solution {
public:

    double epsilon = 0.1;
    bool solve(vector<double> &cards){
        // base case
        if(cards.size()==1){
            return abs(cards[0]- 24) <= epsilon;
        }

        // pick two element
        for(int i=0; i<cards.size(); i++){
            for(int j=0; j<cards.size(); j++){
                if(i==j) continue;
                vector<double> temp;
                for(int k=0; k<cards.size(); k++){
                    if(k!=j && k!= i){
                        temp.push_back(cards[k]);
                    }
                }
                double a = cards[i];
                double b = cards[j];

                vector<double> possibleVal={a+b, a-b, b-a, a*b};
                if(abs(a)>0.0){
                    possibleVal.push_back(b/a);
                }
                if(abs(b)>0.0){
                    possibleVal.push_back(a/b);
                }
                for(double val: possibleVal){
                    temp.push_back(val);
                    if(solve(temp)== true) //explore, recursive call
                    return true;
                    temp.pop_back(); // backtrack
                }
            }
        }
        return false;
    }
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums;
        for(int i=0; i<cards.size(); i++){
            nums.push_back(1.0* cards[i]);

        }

        return solve (nums);
    }
};
