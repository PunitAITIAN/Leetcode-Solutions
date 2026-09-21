class Solution {
public:
    void solve(vector<int>& nums,int& ans,int k){
        // intialize a min heap with k elements
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<k;i++){
            pq.push(nums[i]);
        }
        // now traverse whole array and if nums[i] is grater than top of min heap
        // then push it in heap and pop top element first otherwise ignore and move on
        // at last , k large numbers will be in heap 
        // and top element of min heap will be kth largest of array
        for(int i=k; i<nums.size();i++){
            if(nums[i]>pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        ans = pq.top();
    }
    int findKthLargest(vector<int>& nums, int k) {
        // using min heap
        int ans ;
        solve(nums,ans,k);
        return ans;
    }
};