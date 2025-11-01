3217. Delete Nodes From Linked List Present in Array
//QUESTION LINK: 

// TOPIC: Array
// Hash Table
// Linked List


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
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> seen(nums.begin(), nums.end());
        while(head!=NULL){
            if(seen.find(head->val)!= seen.end()) head = head->next ;
            else break;
        }
        ListNode* curr = head;
        ListNode* temp = head;
        while(temp!=NULL && temp->next!=NULL){
            if(seen.find(temp->next->val)!=seen.end()){
                temp->next = temp->next->next;
            }else temp = temp->next;
        }
        return head;
    }
};
