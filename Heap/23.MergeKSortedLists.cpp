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
    class compare{
        public:
            bool operator()(ListNode* a , ListNode* b){
                return a->val > b->val;
            }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // create a min heap
        priority_queue<ListNode* , vector<ListNode*> , compare> pq;

        ListNode* head = NULL;
        ListNode* tail = NULL;

        // insert first nodes into min heap
        for(int i=0; i<lists.size();i++){
            ListNode* temp = lists[i];
            if(temp!=NULL){
                pq.push(temp);
            }
        }

        // main logic
        while(!pq.empty()){
            ListNode* front = pq.top();
            pq.pop();

            // we are inserting first element
            if(head==NULL && tail==NULL){
                head = front;
                tail = front;
            }
            else{
                // not first element
                tail->next = front;
                tail = front;
            }
            // if there exists next element m then insert that also
            if(tail->next){
                pq.push(tail->next);
            }
        }
        return head;
    }
};