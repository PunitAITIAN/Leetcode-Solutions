/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void levelWise(TreeNode* root,vector<long long>& arr){
        // base case
        if(root==NULL) return;

        queue<TreeNode*> q;
        long long sum =0*1LL;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* front = q.front();
            if(front) sum+=(front->val * 1LL);
            q.pop();

            if(front==NULL){
                // one level is traversed
                arr.push_back(sum*1LL);
                sum =0*1LL;
                if(!q.empty()) q.push(NULL);
            }
            else{
                // insert its child elements if they exist
                if(front->left){
                    q.push(front->left);
                }
                if(front->right){
                    q.push(front->right);
                }
            }
        }

    }
    long long kthLargestLevelSum(TreeNode* root, int k) {
        vector<long long> arr;
        // traverse level wise 
        // store each level sum in array
        levelWise(root,arr);
        
        // sort array
        sort(arr.begin(),arr.end());

        // return Kth largest sum
        if(k>arr.size()) return -1;

        return arr[arr.size()-k];
    }
};