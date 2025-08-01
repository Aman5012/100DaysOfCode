21. Merge Two Sorted Lists
//QUESTION LNK: https://leetcode.com/problems/merge-two-sorted-lists/

TOPIC: inked List
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

//  TC: O(m+n)
//  SC: O(1)
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode ans;
        ListNode* temp = &ans;
        while(list1!= NULL && list2!=NULL){
            if(list1->val <= list2->val){
                temp -> next= list1;
                list1 = list1->next;
            }else{
                temp->next = list2;
                list2= list2->next;
            }
            temp = temp->next;
        }
                // Attach the remaining nodes (if any)
        if (list1 != NULL) temp->next = list1;
        if (list2 != NULL) temp->next = list2;
        return ans.next;
    }
};
