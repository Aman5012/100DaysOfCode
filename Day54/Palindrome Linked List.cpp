234. Palindrome Linked List
//QUESTION LNK: https://leetcode.com/problems/palindrome-linked-list/

TOPIC: Linked List
Two Pointers
Stack
Recursion


CODE:
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
////////////////////   appraoch 2  ////////////////////////
// TC: O(n)
// SC: O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head){
        ListNode* pre=NULL;
        ListNode* next=NULL;
        while(head!=NULL){
            next = head->next;
            head->next = pre;
            pre = head;
            head =next;
        }
        return pre;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next== NULL) return head;
        ListNode* slow = head; 
        ListNode* fast = head;

        while(fast->next != NULL && fast->next->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        } 
        slow->next = reverseList(slow->next);
        slow = slow->next;

        while(slow!=NULL){
            if(head->val!=slow->val) return false;

            slow = slow->next;
            head = head->next;
        }
        return true;
    }
};
 
 //////////////////////////////  using stack  /////////////////

//  TC: O(n)
//  SC: O(n)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* temp = head;

        while(temp!= NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        temp=head;
        while(!st.empty()){
            if(st.top()!= temp->val) return false;

            st.pop();
            temp = temp->next;
        }
        return true;
    }
};
