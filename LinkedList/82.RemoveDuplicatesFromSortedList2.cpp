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
    ListNode* deleteDuplicates(ListNode* head) {
        // egde case -> empty list
        if(head==NULL) return NULL;

        ListNode* prev = NULL;
        ListNode* temp = head;
        int duplicateVal ;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->val!=temp->next->val){
                if(prev==NULL) head=temp;
                prev = temp;
                temp = temp->next;
            }
            else{
                duplicateVal = temp->val;
                while(temp!=NULL && temp->val==duplicateVal){
                    temp=temp->next;
                }

                if(temp==NULL && prev==NULL){
                    return NULL;
                }
                else if(temp!=NULL && prev!=NULL){
                    prev->next = temp;
                }
                else if(temp==NULL && prev!=NULL){
                    prev->next=NULL;
                }
                else if(temp!=NULL && prev==NULL && temp->next==NULL){
                    return temp;
                }
            }
        }
        return head;
    }
};