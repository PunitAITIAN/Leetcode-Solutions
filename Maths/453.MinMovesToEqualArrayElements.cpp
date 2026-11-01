class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        
        int sum = 0;
        for(auto v : nums){
            sum+=v;
        }

        // finding minimum element
        int mini = INT_MAX;
        for(int i=0; i<n ; i++){
            if(mini>nums[i]){
                mini = nums[i];
            }
        }
        
        return sum-(mini*n);
    }
};