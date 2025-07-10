Permutations of a String


//QUESTION LNK: https://www.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1

TOPIC: Strings, Recursion, Backtracking, Data Structures, Algorithms
CODE:

//////////////////////////////   recursive  solution ////////////////////
// Time Complexity: 	O(n × n!)
// Space Complexity: 	O(n × n!)
class Solution {
  public:
  
    void permute(string ip, string op, vector<string>& v){
        if(ip.size()==0){
            v.push_back(op);
            return;
        }
        unordered_set<char> map;
        for(int i=0; i<ip.size(); i++){
            if(map.find(ip[i])== map.end()){ // ensure uniqueness
                map.insert(ip[i]);
                string newip= ip.substr(0,i)+ ip.substr(i+1);
                string newop= op+ ip[i];
                permute(newip, newop, v);
            }
        }
    }
    
    vector<string> findPermutation(string &s) {
        vector<string> v;
        permute(s, "", v );
        return v;
    }
};

///////////////////////////////////      backtrackoing code  /////////
// Time Complexity: 	O(n × n!)
// Space Complexity: 	O(n × n!)

class Solution {
  public:
  
    void permute(string &s, int start, vector<string>& v){
        if(start==s.size()-1){
            v.push_back(s);
            return;
        }
        unordered_set<char> map;
        for(int i=start; i<s.size(); i++){
            if(map.find(s[i])== map.end()){ // ensure uniqueness
                map.insert(s[i]);
                swap(s[start], s[i]);
                permute(s, start+1, v);
                swap(s[i],s[start]) ;
                
            }
        }
    }
    
    vector<string> findPermutation(string &s) {
        vector<string> v;
        permute(s, 0, v );
        return v;
    }
};


/////////////////////////////// using library  ///////////////
// Time	O(n log n + P × n)
// Output Space	O(P × n)
// Aux Space	O(n)
        
        
class Solution {
  public:
    vector<string> findPermutation(string &s) {
      
        vector<string> res;
        sort(s.begin(), s.end());
        do {
            res.push_back(s);
        } while (next_permutation(s.begin(), s.end()));
        return res;
    }
};

