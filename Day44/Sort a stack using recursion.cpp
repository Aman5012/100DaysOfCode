Sort a stack using recursion
//QUESTION LNK: https://www.geeksforgeeks.org/problems/sort-a-stack/1

TOPIC: recursive

CODE:

// Time Complexity: O(n.n)
// Space Complexity: O(n)

/*The structure of the class is
class SortedStack{
public:
    stack<int> s;
    void sort();
};
*/

/* The below method sorts the stack s
you are required to complete the below method */

void helper(stack<int>& s, int & temp){
    if(s.empty() || s.top()<= temp){
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    helper(s, temp); // recursive call
    s.push(val);
    return;
}
void SortedStack ::sort() {
    if(s.empty()) return;
    int temp = s.top();
    s.pop();
    // recursive call
    sort();
    helper(s, temp); // help to inser the temp element 
}
