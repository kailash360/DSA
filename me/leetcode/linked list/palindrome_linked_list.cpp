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
    
    ListNode* reverseList(ListNode* head){
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
    bool isPalindrome(ListNode* head) {
        // O(n) and O(1)
        ListNode* slow = head;
        ListNode* fast = head;
        
        if(head==NULL || head->next==NULL)
            return true;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
            slow->next = reverseList(slow->next);
            slow = slow->next;
            
            while(slow!=NULL){
                if(head->val!=slow->val)
                    return false;
                head = head->next;
                slow = slow->next;
            }
            return true;
        }
    
};