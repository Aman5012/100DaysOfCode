9. Remove Nth Node From End of List

//QUESTION LNK: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

TOPIC: Linked List
Two Pointers


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


//  TC: O(n)
//  SC: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            len ++;
            temp = temp->next;
        }
        //  when delete to the hred 
        if(n==len){
            ListNode * newHead = head->next;
            delete head;
            return newHead;
        }
        temp =head;
        for(int i=1; i<len-n; i++){
            temp= temp->next;
        }
        ListNode * nodeToDelete = temp->next;
        temp ->next = nodeToDelete->next;
        delete nodeToDelete;

        return head;
    }
};
