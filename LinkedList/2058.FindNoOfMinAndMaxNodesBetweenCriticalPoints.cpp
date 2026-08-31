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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // vector for storing crictical points indexes
        vector<int> indexes;
        // vector for storing ans
        vector<int> ans;
        int index = 1;
        // find critical points
        while(head->next->next!=NULL){
            int prev = head->val;
            int mid = head->next->val;
            int nextt = head->next->next->val;
            if((mid>prev && mid>nextt)||(mid<prev && mid<nextt)){
                indexes.push_back(index+1);
            }
            head = head->next;
            index++;
        }

        int mini = INT_MAX;

        if(indexes.size()<2){
            ans.push_back(-1);
            ans.push_back(-1);
        }
        else{
            // find min and max Distance
            sort(indexes.begin(),indexes.end());
            for(int i=1;i<indexes.size();i++){
                int diff = indexes[i]-indexes[i-1];
                if(diff<mini) mini=diff;
            }
            ans.push_back(mini);
            ans.push_back(indexes[indexes.size()-1]-indexes[0]);
        }

        return ans;
    }
};