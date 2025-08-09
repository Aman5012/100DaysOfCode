61. Rotate List
//QUESTION LNK: https://leetcode.com/problems/rotate-list/

TOPIC: Linked List
Two Pointers


CODE:
// TC: O(n)
// SC: O(1)
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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k == 0) return head;
        ListNode* tail =head;
        int len = 1;
        while(tail->next){
            tail = tail->next;
            len++;
        }
        tail ->next = head;// make list Circular
        ListNode* newTail =tail; // move this to the final tail
        k %=len; //  when k > len then 
        
        int stepsToNewHead  = len-k;
        while(stepsToNewHead --){
            newTail = newTail->next;
        }
        ListNode* newHead =newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};
