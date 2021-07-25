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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* temp = curr -> next; // temp = 2
            curr -> next = prev; // 1 -> prev
            prev = curr; // prev = head
            curr = temp; // curr = 
        }
        return prev;
    }
};