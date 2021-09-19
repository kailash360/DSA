#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //given l1 and l2 are just pointers to Lists l1 and l2 and not the lists itself
        //whereas we are making l3 from constructor of ListNode so l3 can be thought of as a
        //actual node and *last is a pointer to the last node of l3
        ListNode l3(-1);
        ListNode *last = &l3;
        int carry = 0;
        while(l1!=NULL && l2!=NULL){
            int sum = l1->val + l2->val + carry;
            carry = sum/10;
            sum = sum % 10;
            last->next = new ListNode(sum);
            last = last->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1!=NULL){
            int sum = l1->val + carry;
            carry = sum/10;
            sum = sum % 10;
            last->next = new ListNode(sum);
            last = last->next;
            l1 = l1->next;
        }
        
        while(l2!=NULL){
            int sum = l2->val + carry;
            carry = sum/10;
            sum = sum % 10;
            last->next = new ListNode(sum);
            last = last->next;
            l2 = l2->next;
        }
        
        if(carry){
            last->next = new ListNode(carry);
            last = last->next;
        }
        return l3.next;
    }
};