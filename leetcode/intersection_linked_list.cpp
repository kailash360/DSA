/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA = headA;
        ListNode* tempB = headB;
        
        int sizeA = 0;
        int sizeB = 0;
        
        while(tempA!=NULL && tempB!=NULL){
            tempA = tempA->next;
            tempB = tempB->next;
            sizeA++;
            sizeB++;
        }
        while(tempA!=NULL){
            tempA = tempA->next;
            sizeA++;
        }
        while(tempB!=NULL){
            tempB = tempB->next;
            sizeB++;
        }
        
        if(tempA!=tempB)
            return nullptr;
        
        ListNode* tempX = headA;
        ListNode* tempY = headB;
        
        if(sizeA > sizeB){
            for(int i=0;i< sizeA-sizeB;i++){
                tempX = tempX->next;
            }
        }
        else if(sizeB > sizeA){
            for(int i=0;i< sizeB-sizeA;i++){
                tempY = tempY->next;
            }
        }
        
        while(tempX!=tempY){
            tempX = tempX->next;
            tempY = tempY->next;
        }
        return tempX;
        
    }
};